#ifndef USBDEVICE_H
#define USBDEVICE_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QTimer>

class UsbDevice : public QObject {
    Q_OBJECT
public:
    explicit UsbDevice(QObject *parent = nullptr);
    ~UsbDevice();

    bool connect(const QString &portName, qint32 baudRate = 115200);
    void disconnect();

    bool sendCommandWaitResponse(const QString &command, int timeoutMs = 1500);

    QString lastResponse() const { return m_lastResponse; }
    QString lastError() const { return m_lastError; }
    bool    isConnected() const { return m_serial && m_serial->isOpen(); }
    void    onReadyRead();
    void    onTimeout();

signals:
    void connected();
    void disconnected();
    void responseReceived(const QString &response);
    void errorOccurred(const QString &message);

private:
    QSerialPort *m_serial           = nullptr;
    QTimer      *m_responseTimer    = nullptr;
    QString     m_lastResponse;
    QString     m_lastError;
    bool        m_waitingResponse   = false;
};

#endif // USBDEVICE_H
