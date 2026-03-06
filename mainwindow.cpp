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
    // 1. Выбор файла
    QString path = QFileDialog::getOpenFileName(
        this,
        "Выберите файл лицензий",
        QDir::homePath(),
        "JSON файлы (*.json);;Все файлы (*.*)"
        );

    if (path.isEmpty()) {
        ui->statusbar->showMessage("Выбор отменён", 4000);
        return;
    }

    // 2. Загрузка файла
    if (!m_licenseManager->load(path)) {
        QMessageBox::critical(this, "Ошибка",
                              "Не удалось прочитать файл:\n" + m_licenseManager->lastError());
        return;
    }

    // Запоминаем путь
    QSettings settings("MyCompany", "LicenseApp");
    settings.setValue("lastLicenseFile", path);

    ui->textEdit->setText("Загружен: " + QFileInfo(path).fileName());
    ui->statusbar->showMessage("Поиск первой свободной лицензии...");

    // 3. Получаем первую неиспользованную лицензию
    auto unused = m_licenseManager->getUnusedLicenses();

    if (unused.isEmpty()) {
        ui->textEdit->setText("Нет свободных лицензий");
        QMessageBox::information(this, "Информация", "В файле нет неактивированных лицензий");
        return;
    }

    // Берём самую первую
    auto [uuid, authkey] = unused.first();

    ui->textEdit->setText("Найдена лицензия: " + uuid.left(8) + "...");
    ui->statusbar->showMessage("Отправка лицензии " + uuid.left(12) + "...");

    // 4. Формируем строку для отправки
    QString payload = QString("LIC:%1|%2\n").arg(uuid, authkey);
    // Если нужен другой формат — измени здесь, например:
    // QString payload = QString("UUID:%1 AUTHKEY:%2\n").arg(uuid, authkey);
    // или QString payload = QJsonDocument(QJsonObject{{"uuid", uuid}, {"authkey", authkey}}).toJson() + "\n";

    // 5. Отправляем по USB
    if (!m_usb->sendCommandWaitResponse(payload, 3000)) {
        QMessageBox::warning(this, "Ошибка связи",
                             "Не удалось отправить лицензию:\n" + m_usb->lastError());
        ui->statusbar->showMessage("Ошибка отправки", 5000);
        return;
    }

    // 6. Отмечаем как использованную
    if (!m_licenseManager->markLicenseUsed(uuid)) {
        QMessageBox::warning(this, "Ошибка",
                             "Не удалось отметить лицензию как использованную");
        return;
    }

    // 7. Сохраняем файл
    if (!m_licenseManager->save()) {
        QMessageBox::warning(this, "Ошибка сохранения",
                             "Лицензия отправлена, но файл не сохранён:\n" +
                                 m_licenseManager->lastError());
    }

    ui->textEdit->setText("Активирована: " + uuid.left(12) + "...");
    ui->statusbar->showMessage("Лицензия успешно активирована", 6000);
    QMessageBox::information(this, "Успех",
                             QString("Лицензия активирована:\nUUID: %1\nAuthKey: %2")
                                 .arg(uuid, authkey));
}

void MainWindow::on_btnSendExec_clicked() {

}


void MainWindow::onLicenseUsed(const QString &licenseNumber) {

}
