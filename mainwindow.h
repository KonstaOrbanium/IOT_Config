#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "licensemanager.h"
#include "usbdevice.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnActivateLicense_clicked();
    void on_btnSendExec_clicked();
    void onLicenseUsed(const QString &licenseNumber);

private:
    Ui::MainWindow *ui;

    LicenseManager *m_licenseManager = nullptr;
    UsbDevice      *m_usb           = nullptr;
};
#endif // MAINWINDOW_H
