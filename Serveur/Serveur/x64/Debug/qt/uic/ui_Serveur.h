/********************************************************************************
** Form generated from reading UI file 'Serveur.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVEUR_H
#define UI_SERVEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServeurClass
{
public:
    QWidget *centralWidget;
    QPushButton *startTcpServerButton;
    QLineEdit *portInput;
    QLabel *infolabel_1;
    QLabel *portInfoLabel;
    QLabel *infolabel_2;
    QLabel *infolabel_3;
    QLabel *tempLabel;
    QLabel *infolabel_4;
    QLabel *hygroLabel;
    QPlainTextEdit *serverConsole;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ServeurClass)
    {
        if (ServeurClass->objectName().isEmpty())
            ServeurClass->setObjectName(QString::fromUtf8("ServeurClass"));
        ServeurClass->resize(597, 172);
        centralWidget = new QWidget(ServeurClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        startTcpServerButton = new QPushButton(centralWidget);
        startTcpServerButton->setObjectName(QString::fromUtf8("startTcpServerButton"));
        startTcpServerButton->setGeometry(QRect(177, 90, 141, 21));
        portInput = new QLineEdit(centralWidget);
        portInput->setObjectName(QString::fromUtf8("portInput"));
        portInput->setGeometry(QRect(37, 90, 113, 21));
        infolabel_1 = new QLabel(centralWidget);
        infolabel_1->setObjectName(QString::fromUtf8("infolabel_1"));
        infolabel_1->setGeometry(QRect(7, 90, 47, 20));
        portInfoLabel = new QLabel(centralWidget);
        portInfoLabel->setObjectName(QString::fromUtf8("portInfoLabel"));
        portInfoLabel->setGeometry(QRect(40, 70, 270, 13));
        infolabel_2 = new QLabel(centralWidget);
        infolabel_2->setObjectName(QString::fromUtf8("infolabel_2"));
        infolabel_2->setGeometry(QRect(333, 2, 90, 13));
        infolabel_3 = new QLabel(centralWidget);
        infolabel_3->setObjectName(QString::fromUtf8("infolabel_3"));
        infolabel_3->setGeometry(QRect(10, 10, 81, 31));
        tempLabel = new QLabel(centralWidget);
        tempLabel->setObjectName(QString::fromUtf8("tempLabel"));
        tempLabel->setGeometry(QRect(90, 20, 47, 13));
        infolabel_4 = new QLabel(centralWidget);
        infolabel_4->setObjectName(QString::fromUtf8("infolabel_4"));
        infolabel_4->setGeometry(QRect(10, 32, 89, 31));
        hygroLabel = new QLabel(centralWidget);
        hygroLabel->setObjectName(QString::fromUtf8("hygroLabel"));
        hygroLabel->setGeometry(QRect(86, 41, 47, 13));
        serverConsole = new QPlainTextEdit(centralWidget);
        serverConsole->setObjectName(QString::fromUtf8("serverConsole"));
        serverConsole->setGeometry(QRect(330, 20, 261, 91));
        ServeurClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ServeurClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 597, 20));
        ServeurClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ServeurClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ServeurClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ServeurClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ServeurClass->setStatusBar(statusBar);

        retranslateUi(ServeurClass);
        QObject::connect(startTcpServerButton, SIGNAL(clicked()), ServeurClass, SLOT(startTcpServer()));

        QMetaObject::connectSlotsByName(ServeurClass);
    } // setupUi

    void retranslateUi(QMainWindow *ServeurClass)
    {
        ServeurClass->setWindowTitle(QCoreApplication::translate("ServeurClass", "Serveur", nullptr));
        startTcpServerButton->setText(QCoreApplication::translate("ServeurClass", "D\303\251marrer le serveur TCP", nullptr));
        infolabel_1->setText(QCoreApplication::translate("ServeurClass", "Port :", nullptr));
        portInfoLabel->setText(QString());
        infolabel_2->setText(QCoreApplication::translate("ServeurClass", "Traffic du serveur", nullptr));
        infolabel_3->setText(QCoreApplication::translate("ServeurClass", "Temp\303\251rature :", nullptr));
        tempLabel->setText(QString());
        infolabel_4->setText(QCoreApplication::translate("ServeurClass", "Hygrom\303\251trie :", nullptr));
        hygroLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ServeurClass: public Ui_ServeurClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVEUR_H
