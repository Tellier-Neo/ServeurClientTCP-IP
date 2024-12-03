#include "CPPNetworkClient.h"

CPPNetworkClient::CPPNetworkClient(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    socket = new QTcpSocket(this);
    
    QObject::connect(socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
}

CPPNetworkClient::~CPPNetworkClient()
{
    delete socket;
}

void CPPNetworkClient::connectButtonClicked()
{
    QString ip = ui.ipLineEdit->text();
    QString port = ui.portLineEdit->text();
    
    bool ok;
    int portInt = port.toInt(&ok);
    if (ok) {
        socket->connectToHost(ip, portInt);
    }
}

void CPPNetworkClient::celsiusButtonClicked()
{
    if (socket->state() == QTcpSocket::ConnectedState)
    {
        QString trame = "Td";
        if(ui.spinBox->value() < 10) trame += "0";
        trame += QString::number(ui.spinBox->value()) + "?";
        socket->write(trame.toUtf8());
    }
}

void CPPNetworkClient::farhenheitButtonClicked()
{
    if (socket->state() == QTcpSocket::ConnectedState)
    {
        QString trame = "Tf";
        if (ui.spinBox->value() < 10) trame += "0";
        trame += QString::number(ui.spinBox->value()) + "?";
        socket->write(trame.toUtf8());
    }
}

void CPPNetworkClient::hygometrieButtonClicked()
{
    if (socket->state() == QTcpSocket::ConnectedState)
    {
        QString trame = "Hr";
        if (ui.spinBox->value() < 10) trame += "0";
        trame += QString::number(ui.spinBox->value()) + "?";
        socket->write(trame.toUtf8());
    }
}

void CPPNetworkClient::onSocketConnected()
{
    ui.portStatusLabel->setText("Statut connexion : Connectee");
}

void CPPNetworkClient::onSocketDisconnected()
{
    ui.portStatusLabel->setText("Statut connexion : déconnectee");
}

void CPPNetworkClient::onSocketReadyRead()
{
    QByteArray data = socket->read(socket->bytesAvailable());
    QString str(data);
    int idCapteur, bfFloat, atFloat;
    QString sign,result;

    if (str.startsWith("Td") && str.length() == 11)
    {
        idCapteur = data.mid(2, 2).toInt();
        sign = (data.mid(5, 1));
        bfFloat = data.mid(6, 2).toInt();
        atFloat = data.mid(8, 2).toInt();
        result = "Temperature du capteur " + QString::number(idCapteur) + " : " + sign + QString::number(bfFloat) + "," + QString::number(atFloat) + " Degres Celsius";
    }
    else if (str.startsWith("Tf") && str.length() == 11)
    {
        idCapteur = data.mid(2, 2).toInt();
        sign = (data.mid(5, 1));
        bfFloat = data.mid(6, 2).toInt();
        atFloat = data.mid(8, 2).toInt();
        result = "Temperature du capteur " + QString::number(idCapteur) + " : " + sign + QString::number(bfFloat) + "," + QString::number(atFloat) + " Degres farhenheit";
    }
    else if(str.startsWith("Hr") && str.length() == 11)
    {
        idCapteur = data.mid(2, 2).toInt();
        bfFloat = data.mid(4, 2).toInt();
        atFloat = data.mid(7, 2).toInt();
        result = "Hygrométrie du capteur " + QString::number(idCapteur) + " : " + QString::number(bfFloat) + "," + QString::number(atFloat) + "%";
    }
    ui.ResultLabel->setText(result);
}
