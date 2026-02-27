/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 464);
        MainWindow->setStyleSheet(QString::fromUtf8(" background-color: rgb(0, 127, 127)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, -10, 491, 361));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(180, 40));
        pushButton_4->setMaximumSize(QSize(160, 40));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
" 		background-color: rgb(0, 166, 139);\n"
"		color: white;\n"
"		border: none;\n"
"		border-radius: 5px;\n"
"		padding: 10px;\n"
"		font-size: 14px;\n"
"		font-weight: bold;\n"
"            }\n"
"QPushButton::hover {\n"
"		background-color: rgb(0, 190, 139)\n"
"         	  }\n"
"QPushButton::pressed {\n"
"                background-color: #3d8b40;\n"
"            };"));

        gridLayout->addWidget(pushButton_4, 2, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName("pushButton");
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(180, 40));
        pushButton->setMaximumSize(QSize(160, 40));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
" 		background-color: rgb(0, 166, 139);\n"
"		color: white;\n"
"		border: none;\n"
"		border-radius: 5px;\n"
"		padding: 10px;\n"
"		font-size: 14px;\n"
"		font-weight: bold;\n"
"   }\n"
"QPushButton::hover {\n"
"		background-color: rgb(0, 190, 139)\n"
"   }\n"
"QPushButton::pressed {\n"
"                background-color: #3d8b40;\n"
"   };"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(180, 44));
        comboBox->setMaximumSize(QSize(160, 20));
        comboBox->setStyleSheet(QString::fromUtf8("QPushButton, QComboBox {\n"
"    background-color: rgb(0, 166, 139);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 4px 14px 4px 10px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    min-height: 36px;          /* \321\207\321\202\320\276\320\261\321\213 \320\262\321\213\321\201\320\276\321\202\320\260 \320\261\321\213\320\273\320\260 \320\277\321\200\320\270\320\274\320\265\321\200\320\275\320\276 \320\272\320\260\320\272 \321\203 \320\272\320\275\320\276\320\277\320\276\320\272 */\n"
"	 text-align: center;\n"
"}\n"
"\n"
"QPushButton:hover, QComboBox:hover {\n"
"    background-color: rgb(0, 190, 139);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3d8b40;\n"
"}\n"
"\n"
"/* \320\241\321\202\320\270\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 (\321\201\320\260\320\274\320\276\320\265 \320\262\320"
                        "\260\320\266\320\275\320\276\320\265) */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: rgb(0, 166, 139);\n"
"    color: white;\n"
"    selection-background-color: rgb(0, 190, 139);\n"
"    selection-color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox QAbstractItemView::item {\n"
"    padding: 8px 12px;\n"
"}\n"
"\n"
"/* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\203\321\216 \321\200\320\260\320\274\320\272\321\203 \320\262\320\276\320\272\321\200\321\203\320\263 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277"
                        "\320\270\321\201\320\272\320\260 */\n"
"QComboBox QAbstractItemView {\n"
"    outline: none;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    background: transparent !important;\n"
"    border-image: none;\n"
"    box-shadow: none;\n"
"}\n"
"/* \320\237\320\276\320\273\320\265 \320\262\320\262\320\276\320\264\320\260/\321\202\320\265\320\272\321\201\321\202\320\260 \320\262\320\275\321\203\321\202\321\200\320\270 \320\272\320\276\320\274\320\261\320\276\320\261\320\276\320\272\321\201\320\260 */\n"
"QComboBox {\n"
"    padding-left: 12px;\n"
"    padding-right: 30px;            /* \320\274\320\265\321\201\321\202\320\276 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"}\n"
""));

        gridLayout->addWidget(comboBox, 4, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
" 		background-color: rgb(0, 166, 139);\n"
"		color: white;\n"
"		border: none;\n"
"		border-radius: 5px;\n"
"		padding: 10px;\n"
"		font-size: 14px;\n"
"		font-weight: bold;\n"
"            }\n"
"QPushButton::hover {\n"
"		background-color: rgb(0, 190, 139)\n"
"         	  }\n"
"QPushButton::pressed {\n"
"                background-color: #3d8b40;\n"
"            };"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton, QComboBox {\n"
"    background-color: rgb(0, 166, 139);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 4px 14px 4px 10px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    min-height: 36px;          /* \321\207\321\202\320\276\320\261\321\213 \320\262\321\213\321\201\320\276\321\202\320\260 \320\261\321\213\320\273\320\260 \320\277\321\200\320\270\320\274\320\265\321\200\320\275\320\276 \320\272\320\260\320\272 \321\203 \320\272\320\275\320\276\320\277\320\276\320\272 */\n"
"	 text-align: center;\n"
"}\n"
"\n"
"QPushButton:hover, QComboBox:hover {\n"
"    background-color: rgb(0, 190, 139);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3d8b40;\n"
"}\n"
"\n"
"/* \320\241\321\202\320\270\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 (\321\201\320\260\320\274\320\276\320\265 \320\262\320"
                        "\260\320\266\320\275\320\276\320\265) */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: rgb(0, 166, 139);\n"
"    color: white;\n"
"    selection-background-color: rgb(0, 190, 139);\n"
"    selection-color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\262\320\275\321\203\321\202\321\200\320\270 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"QComboBox QAbstractItemView::item {\n"
"    padding: 8px 12px;\n"
"}\n"
"\n"
"/* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\321\203\321\216 \321\200\320\260\320\274\320\272\321\203 \320\262\320\276\320\272\321\200\321\203\320\263 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277"
                        "\320\270\321\201\320\272\320\260 */\n"
"QComboBox QAbstractItemView {\n"
"    outline: none;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    background: transparent !important;\n"
"    border-image: none;\n"
"    box-shadow: none;\n"
"}\n"
"/* \320\237\320\276\320\273\320\265 \320\262\320\262\320\276\320\264\320\260/\321\202\320\265\320\272\321\201\321\202\320\260 \320\262\320\275\321\203\321\202\321\200\320\270 \320\272\320\276\320\274\320\261\320\276\320\261\320\276\320\272\321\201\320\260 */\n"
"QComboBox {\n"
"    padding-left: 12px;\n"
"    padding-right: 30px;            /* \320\274\320\265\321\201\321\202\320\276 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"}\n"
""));

        gridLayout->addWidget(pushButton_3, 3, 0, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 363, 481, 91));
        textEdit->setMinimumSize(QSize(140, 40));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit, QTextBrowser {\n"
"    background-color: rgb(0, 166, 139);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px 10px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTextEdit:focus, QTextBrowser:focus {\n"
"    background-color: rgb(0, 190, 139);\n"
"    outline: none;\n"
"}\n"
"\n"
"/* \320\225\321\201\320\273\320\270 \321\205\320\276\321\207\320\265\321\210\321\214 \321\207\321\203\321\202\321\214 \321\202\320\265\320\274\320\275\320\265\320\265 \321\204\320\276\320\275 \320\277\321\200\320\270 \320\262\320\262\320\276\320\264\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"QTextEdit[readOnly=\"false\"] {\n"
"    background-color: rgb(0, 180, 150);\n"
"}\n"
"\n"
"/* \320\237\320\276\320\273\320\276\321\201\320\260 \320\277\321\200\320\276\320\272\321\200\321\203\321\202\320\272\320\270 \320\262 \321\202\320\276\320\274 \320\266\320\265 \321\201\321\202\320\270\320\273\320\265 */\n"
"QTextEdit::handle:vertical, QTextBrowser"
                        "::handle:vertical,\n"
"QTextEdit::handle:horizontal, QTextBrowser::handle:horizontal {\n"
"    background: rgba(255, 255, 255, 0.25);\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    min-width: 8px;\n"
"    min-height: 8px;\n"
"}\n"
"\n"
"QTextEdit::add-line:vertical, QTextBrowser::add-line:vertical,\n"
"QTextEdit::sub-line:vertical, QTextBrowser::sub-line:vertical,\n"
"QTextEdit::add-page:vertical, QTextBrowser::add-page:vertical,\n"
"QTextEdit::sub-page:vertical, QTextBrowser::sub-page:vertical {\n"
"    background: transparent;\n"
"}\n"
"\n"
"QTextEdit::groove:vertical, QTextBrowser::groove:vertical {\n"
"    background: rgba(0, 0, 0, 0.15);\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"}"));
        textEdit->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \321\201\320\262\321\217\320\267\321\214", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 JSON \321\204\320\260\320\271\320\273", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "      \320\234\320\276\320\264\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "8 \320\242\320\243", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "16 \320\242\320\243", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "8 \320\242\320\241", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "16 \320\242\320\241", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "8 \320\242\320\241 4 \320\242\320\243", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "8 \320\242\320\241 8 \320\242\320\243", nullptr));

        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:14px; font-weight:700; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265: </p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
