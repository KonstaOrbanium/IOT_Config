#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox> ///< TODO
#include <QFileDialog>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Создаём объекты-менеджеры
    m_licenseManager = new LicenseManager(this);
    m_usb            = new UsbDevice(this);

    // QString jsonPath = QCoreApplication::applicationDirPath() + "/licenses.json";
    // if (!m_licenseManager->load(jsonPath)) {
    //     // обработка ошибки загрузки
    //     ui->statusbar->showMessage("Не удалось загрузить лицензии");
    // }

    connect(m_licenseManager, &LicenseManager::errorOccurred,
            this, [this](const QString &msg) {
                QMessageBox::warning(this, "Ошибка лицензий", msg);
            });

    connect(m_licenseManager, &LicenseManager::licenseUsed, this, &MainWindow::onLicenseUsed);
    connect(this->ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_btnActivateLicense_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnActivateLicense_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Выберите файл лицензий", QDir::homePath(), "JSON (*.json);;Все файлы (*.*)");
    if (path.isEmpty()) return;

    if (!m_licenseManager->load(path)) {
        QMessageBox::warning(this, "Ошибка", m_licenseManager->lastError());
        return;
    }

    QSettings settings("MyCompany", "LicenseApp");
    settings.setValue("lastLicenseFile", path);

    // Получаем все неиспользованные лицензии
    auto unused = m_licenseManager->getUnusedLicenses();

    if (unused.isEmpty()) {
        ui->textEdit->setText("Нет доступных лицензий");
        QMessageBox::information(this, "Инфо", "В файле нет неактивированных лицензий");
        return;
    }

    int success = 0;
    QStringList log;

    for (const auto &[uuid, authkey] : unused) {
        QString payload = QString("LIC:%1|%2\n").arg(uuid, authkey);

        if (m_usb->sendCommandWaitResponse(payload, 3000)) {
            m_licenseManager->markLicenseUsed(uuid);
            success++;
            log << QString("OK → %1").arg(uuid);
        }
        else {
            log << QString("FAIL → %1 : %2").arg(uuid, m_usb->lastError());
        }
    }

    m_licenseManager->save();

    ui->textEdit->setText(QString("Активировано %1 из %2").arg(success).arg(unused.size()));
    ui->textEdit->append(log.join("\n"));

    QMessageBox::information(this, "Результат", QString("Успешно: %1\nВсего попыток: %2").arg(success).arg(unused.size()));
}

void MainWindow::on_btnSendExec_clicked() {

}


void MainWindow::onLicenseUsed(const QString &licenseNumber) {

}
