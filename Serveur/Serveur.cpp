#include "Serveur.h"
#include "ui_Serveur.h"
#include <qtcpserver.h>
#include <qtcpsocket.h>
#include <QRandomGenerator>

Serveur::Serveur(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	connect(&serverTCP, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

Serveur::~Serveur()
{}

void Serveur::onNewConnection()
{
    QTcpSocket* client = serverTCP.nextPendingConnection();
	clients.append(client);
	connect(client, SIGNAL(readyRead()), this, SLOT(readRequest()));
    connect(client, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
	ui.serverConsole->appendPlainText("Nouvelle connexion :" + client->peerAddress().toString() + "\n");
}

void Serveur::readRequest()
{
	QTcpSocket* client = qobject_cast<QTcpSocket*>(sender());
	if (client == nullptr) { return; }
	QByteArray data = client->readAll();
	if (data.startsWith("Td") && data.endsWith("?") && data.length() == 5) {
		int IdCapteur = data.mid(2, 2).toInt();
		if (IdCapteur <= 0 || IdCapteur > 99)
		{
			ui.serverConsole->appendPlainText("Id du capteur invalide \n");
			client->write("Capteur invalide");
			return;
		}
		ui.serverConsole->appendPlainText("Id du capteur :" + QString::number(IdCapteur) + "\n");
		double TemperatureCelsius = QRandomGenerator::global()->bounded(-20, 37);
		QString sign = "+";
		if (TemperatureCelsius < 0) sign = "-";
		QString response;
		ui.tempLabel->setText(QString::number(TemperatureCelsius) + "C");
		ui.serverConsole->appendPlainText("Temperature generee" + QString::number(TemperatureCelsius) + "C" + "\n");
		response = "Td" + QString::number(IdCapteur) + "," + sign + QString::number(TemperatureCelsius, 'f', 2).replace(",", ".");
		client->write(response.toUtf8());
		ui.serverConsole->appendPlainText("Envoi de la temperature au client reussi \n" );
		client->flush();
		return;
	}
	if (data.startsWith("Tf") && data.endsWith("?") && data.length() == 5) {
		int IdCapteur = data.mid(2, 2).toInt();
		if (IdCapteur <= 0 || IdCapteur > 99)
		{
			ui.serverConsole->appendPlainText("Id du capteur invalide \n");
			client->write("Capteur invalide");
			return;	
		}
		ui.serverConsole->appendPlainText("Id du capteur :" + QString::number(IdCapteur) + "\n");
		double TemperatureCelsius = QRandomGenerator::global()->bounded(-20, 37);
		double TemperatureFahrenheit = (TemperatureCelsius * 9 / 5) + 32;
		QString sign = "+";
		if (TemperatureFahrenheit < 0) sign = "-";
		QString response;
		response = "Tf" + QString::number(IdCapteur) + "," + sign + QString::number(TemperatureFahrenheit, 'f', 2).replace(",", ".");
		ui.tempLabel->setText(QString::number(TemperatureFahrenheit)+ "F");
		ui.serverConsole->appendPlainText("Temperature generee" + QString::number(TemperatureFahrenheit) + "F \n");
		client->write(response.toUtf8());
		ui.serverConsole->appendPlainText("Envoi de la temperature au client reussi \n ");
		client->flush();
		return;
	}
	if (data.startsWith("Hr") && data.endsWith("?") && data.length() == 5)
	{
		int IdCapteur = data.mid(2, 2).toInt();
		if (IdCapteur <= 0 || IdCapteur > 99)
		{
			ui.serverConsole->appendPlainText("Id du capteur invalide \n");
			client->write("Capteur invalide");
			return;
			
		}
		ui.serverConsole->appendPlainText("Id du capteur : " + QString::number(IdCapteur) + "\n");
		double Hygrometrie = QRandomGenerator::global()->bounded(0, 99.99);
		QString response;
		response = "Hr" + QString::number(IdCapteur) + "," + QString::number(Hygrometrie, 'f', 2).replace(",", ".");
		ui.hygroLabel->setText(QString::number(Hygrometrie) + "%");
		ui.serverConsole->appendPlainText("Hygometrie generee :" + QString::number(Hygrometrie));
        client->write(response.toUtf8());
		ui.serverConsole->appendPlainText("Envoi de l'hygometrie au client reussi \n ");
        client->flush();
		return;
	}
	else
	{
        ui.serverConsole->appendPlainText("Requete inconnue \n");
        client->write("Requete inconnue");
		return;
	}
}

void Serveur::clientDisconnected()
{
	QTcpSocket* client = qobject_cast<QTcpSocket*>(sender());
    	if (client == nullptr) { return; }
    	ui.serverConsole->appendPlainText("Client deconnecter");
    	client->disconnect();

        
}




void Serveur::startTcpServer() {
	if (status == false) {

	
		QString tcpPort = ui.portInput->text();
		bool ok;
		int port = tcpPort.toInt(&ok);
		if (ok)
		{
			if (serverTCP.listen(QHostAddress("127.0.0.1"), port))
			{

				ui.portInfoLabel->setText("Serveur demarrer sur le port :" + tcpPort);
				ui.serverConsole->appendPlainText("Demarrage du serveur sur le port :" + tcpPort);
				ui.startTcpServerButton->setText("Arreter le serveur");
				status = true;
				return;
			}
			else
			{
				ui.portInfoLabel->setText("Port deja utilise");
				return;
			}
		}
		else {
			ui.portInfoLabel->setText("Port invalide");
			return;
		}
	}
	else if (status == true)
	{
        serverTCP.close();
		status = false;
        ui.portInfoLabel->setText("Serveur arreter");
        ui.serverConsole->appendPlainText("Arret du serveur");

        ui.startTcpServerButton->setText("Demarrer le serveur");
	}
	
	
}


