/********************************************************************************
** Form generated from reading UI file 'Client.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientClass
{
public:
    QWidget *centralWidget;
    QPushButton *connectToServerButton;
    QPushButton *sendRequestButton;
    QComboBox *typeOfValueCB;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClientClass)
    {
        if (ClientClass->objectName().isEmpty())
            ClientClass->setObjectName(QString::fromUtf8("ClientClass"));
        ClientClass->resize(600, 400);
        centralWidget = new QWidget(ClientClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        connectToServerButton = new QPushButton(centralWidget);
        connectToServerButton->setObjectName(QString::fromUtf8("connectToServerButton"));
        connectToServerButton->setGeometry(QRect(10, 10, 151, 21));
        sendRequestButton = new QPushButton(centralWidget);
        sendRequestButton->setObjectName(QString::fromUtf8("sendRequestButton"));
        sendRequestButton->setGeometry(QRect(10, 30, 151, 21));
        typeOfValueCB = new QComboBox(centralWidget);
        typeOfValueCB->setObjectName(QString::fromUtf8("typeOfValueCB"));
        typeOfValueCB->setGeometry(QRect(410, 10, 151, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 10, 180, 19));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(300, 70, 231, 251));
        ClientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ClientClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 20));
        ClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ClientClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ClientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ClientClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ClientClass->setStatusBar(statusBar);

        retranslateUi(ClientClass);

        QMetaObject::connectSlotsByName(ClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *ClientClass)
    {
        ClientClass->setWindowTitle(QCoreApplication::translate("ClientClass", "Client", nullptr));
        connectToServerButton->setText(QCoreApplication::translate("ClientClass", "Se connecter au serveur", nullptr));
        sendRequestButton->setText(QCoreApplication::translate("ClientClass", "Envoyer la requ\303\252te", nullptr));
        label->setText(QCoreApplication::translate("ClientClass", "Choisir le type de valeur attendu :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientClass: public Ui_ClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
