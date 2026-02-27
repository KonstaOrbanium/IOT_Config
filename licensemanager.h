#pragma once

#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QSet>

class LicenseManager : public QObject
{
    Q_OBJECT

public:
    explicit LicenseManager(QObject *parent = nullptr);

    bool load(const QString &filePath);
    bool save() const;

    bool isUsed(const QString &licenseNumber) const;
    bool markAsUsed(const QString &licenseNumber);

    int  executionNumber() const;
    void setExecutionNumber(int number);

    QString lastError() const;

signals:
    void errorOccurred(const QString &message);
    void licenseUsed(const QString &licenseNumber);
    void executionNumberChanged(int newNumber);

private:
    QString         m_filePath;
    QJsonObject     m_jsonRoot;
    QSet<QString>   m_usedLicensesCache;
    int             m_executionNumber = 1;
    mutable QString m_lastError;
};
