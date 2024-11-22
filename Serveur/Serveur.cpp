#include "Serveur.h"
#include <qtcpserver.h>


Serveur::Serveur(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

Serveur::~Serveur()
{}


void Serveur::startTcpServer() {
	
	QString tcpPort = ui.portInput->text();
	bool ok;
	int port = tcpPort.toInt(&ok);
	if (ok)
	{
		if (serverTCP.listen(QHostAddress("127.0.0.1"), port) == true)
		{
			ui.portInfoLabel->setText("Server started on port " + tcpPort);
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

