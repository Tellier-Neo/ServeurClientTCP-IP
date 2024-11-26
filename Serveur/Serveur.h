#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Serveur.h"
#include <QTcpServer>
#include <QTcpSocket>

class Serveur : public QMainWindow
{
    Q_OBJECT

public:
    Serveur(QWidget *parent = nullptr);
    ~Serveur();

private:
    Ui::ServeurClass ui;
    QTcpServer serverTCP;
    QTcpSocket* clientSocket;
    QList<QTcpSocket*> clients;
    bool status;

private slots:
    void startTcpServer();
    void onNewConnection();
    void readRequest();
    void clientDisconnected();
 
   
};
