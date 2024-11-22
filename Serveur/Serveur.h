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
    void onReadyRead();


private slots:
    void startTcpServer();

};
