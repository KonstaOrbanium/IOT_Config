#include "licensemanager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QSaveFile>
#include <QDebug>


LicenseManager::LicenseManager(QObject *parent)
    : QObject(parent) {

}

bool LicenseManager::load(const QString &filePath)
{
    m_filePath = filePath;
    m_lastError.clear();
    m_usedLicensesCache.clear();

    QFile file(filePath);
    if (!file.exists())
    {
        // файл не существует → создаём пустую структуру
        m_jsonRoot["used_licenses"] = QJsonArray();
        m_jsonRoot["execution_number"] = 1;
        return save();
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        m_lastError = QString("Не удалось открыть файл: %1").arg(file.errorString());
        emit errorOccurred(m_lastError);
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError)
    {
        m_lastError = QString("Ошибка парсинга JSON: %1 (offset %2)")
                          .arg(parseError.errorString())
                          .arg(parseError.offset);
        emit errorOccurred(m_lastError);
        return false;
    }

    if (!doc.isObject())
    {
        m_lastError = "JSON не является объектом";
        emit errorOccurred(m_lastError);
        return false;
    }

    m_jsonRoot = doc.object();

    // заполняем кэш использованных лицензий
    QJsonValue licensesVal = m_jsonRoot.value("used_licenses");
    if (licensesVal.isArray())
    {
        QJsonArray arr = licensesVal.toArray();
        for (const auto &v : arr)
        {
            if (v.isString())
                m_usedLicensesCache.insert(v.toString().trimmed().toUpper());
        }
    }

    // номер исполнения
    QJsonValue execVal = m_jsonRoot.value("execution_number");
    if (execVal.isDouble())
        m_executionNumber = static_cast<int>(execVal.toDouble());
    else
        m_executionNumber = 1;

    return true;
}

bool LicenseManager::save() const
{
    if (m_filePath.isEmpty())
    {
        m_lastError = "Путь к файлу не задан";
        return false;
    }

    QSaveFile file(m_filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        m_lastError = QString("Не удалось открыть файл для записи: %1").arg(file.errorString());
        return false;
    }

    QJsonObject root = m_jsonRoot;

    // сохраняем использованные лицензии
    QJsonArray licensesArray;
    for (const QString &lic : m_usedLicensesCache)
        licensesArray.append(lic.toUpper());

    root["used_licenses"] = licensesArray;
    root["execution_number"] = m_executionNumber;

    QJsonDocument doc(root);
    QByteArray data = doc.toJson(QJsonDocument::Indented);

    qint64 written = file.write(data);
    if (written != data.size())
    {
        m_lastError = QString("Ошибка записи: записано %1 из %2 байт").arg(written).arg(data.size());
        file.cancelWriting();
        return false;
    }

    if (!file.commit())
    {
        m_lastError = QString("Ошибка коммита: %1").arg(file.errorString());
        return false;
    }

    m_lastError.clear();
    return true;
}

bool LicenseManager::isUsed(const QString &licenseNumber) const
{
    return m_usedLicensesCache.contains(licenseNumber.trimmed().toUpper());
}

bool LicenseManager::markAsUsed(const QString &licenseNumber)
{
    QString normalized = licenseNumber.trimmed().toUpper();
    if (normalized.isEmpty())
        return false;

    if (m_usedLicensesCache.contains(normalized))
        return true;  // уже есть → считаем успехом

    m_usedLicensesCache.insert(normalized);

    emit licenseUsed(normalized);

    // можно сразу сохранять, а можно отложить до явного вызова save()
    // return save();   ← если хочешь автосохранение
    return true;
}

int LicenseManager::executionNumber() const
{
    return m_executionNumber;
}

void LicenseManager::setExecutionNumber(int number)
{
    if (number < 1)
        number = 1;

    if (m_executionNumber == number)
        return;

    m_executionNumber = number;
    emit executionNumberChanged(number);

    // можно сразу сохранять
    // save();
}

QString LicenseManager::lastError() const
{
    return m_lastError;
}
