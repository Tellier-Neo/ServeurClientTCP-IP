#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CPPNetworkClient.h"
#include <qtcpsocket.h>

class CPPNetworkClient : public QMainWindow
{
    Q_OBJECT

public:
    CPPNetworkClient(QWidget *parent = nullptr);
    ~CPPNetworkClient();

private:
    Ui::CPPNetworkClientClass ui;
    QTcpSocket* socket;

public slots:
    void connectButtonClicked();
    void celsiusButtonClicked();
    void farhenheitButtonClicked();
    void hygometrieButtonClicked();
    void onSocketConnected();
    void onSocketDisconnected();
    void onSocketReadyRead();
};
