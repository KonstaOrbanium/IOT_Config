#include <QDebug>
#include <QEventLoop>
#include "usbdevice.h"



UsbDevice::UsbDevice(QObject *parent)
    : QObject{parent} {
    m_serial = new QSerialPort(this);
    m_responseTimer = new QTimer(this);
    m_responseTimer->setSingleShot(true);

    QSerialPort::connect(m_serial, &QSerialPort::readyRead, this, &UsbDevice::onReadyRead);
    QSerialPort::connect(m_responseTimer, &QTimer::timeout, this, &UsbDevice::onTimeout);
}
UsbDevice::~UsbDevice() {
    this->disconnect();
}

bool UsbDevice::connect(const QString &portName, qint32 baudRate) {
    if (m_serial->isOpen()) {
        m_serial->close();
    }

    m_serial->setPortName(portName);
    m_serial->setBaudRate(baudRate);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);

    if (!m_serial->open(QIODevice::ReadWrite)) {
        m_lastError = m_serial->errorString();
        emit errorOccurred(m_lastError);
        return false;
    }

    emit connected();
    return true;
}

void UsbDevice::disconnect() {
    if (m_serial->isOpen()) {
        m_serial->close();
        emit disconnected();
    }
}

bool UsbDevice::sendCommandWaitResponse(const QString &command, int timeoutMs)
{
    if (!m_serial->isOpen()) {
        m_lastError = "Порт не открыт";
        emit errorOccurred(m_lastError);
        return false;
    }

    m_lastResponse.clear();
    m_lastError.clear();
    m_waitingResponse = true;

    // Отправляем команду
    QByteArray data = (command + "\n").toUtf8();
    qint64 written = m_serial->write(data);
    if (written != data.size()) {
        m_lastError = "Ошибка записи: " + m_serial->errorString();
        m_waitingResponse = false;
        emit errorOccurred(m_lastError);
        return false;
    }

    m_serial->flush();

    // Запускаем таймер ожидания ответа
    m_responseTimer->start(timeoutMs);

    // Здесь можно сделать блокирующий цикл, но лучше использовать сигналы
    // Для простоты пока оставим синхронный вариант с QEventLoop

    QEventLoop loop;
    QEventLoop::connect(this, &UsbDevice::responseReceived, &loop, &QEventLoop::quit);
    QEventLoop::connect(this, &UsbDevice::errorOccurred, &loop, &QEventLoop::quit);

    loop.exec();

    m_responseTimer->stop();
    m_waitingResponse = false;

    return !m_lastResponse.isEmpty() && m_lastError.isEmpty();
}

void UsbDevice::onReadyRead()
{
    if (!m_waitingResponse) return;

    QByteArray data = m_serial->readAll();
    m_lastResponse += QString::fromUtf8(data);

    // Можно добавить проверку завершения ответа, например по символу \n
    if (m_lastResponse.contains('\n')) {
        m_lastResponse = m_lastResponse.trimmed();
        m_responseTimer->stop();
        emit responseReceived(m_lastResponse);
    }
}

void UsbDevice::onTimeout()
{
    if (m_waitingResponse) {
        m_lastError = "Таймаут ожидания ответа";
        m_waitingResponse = false;
        emit errorOccurred(m_lastError);
    }
}
