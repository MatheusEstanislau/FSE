#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string>
#include <string.h>

#include "controller/lamps/lampsController.hpp"
#include "controller/windows/windowController.hpp"
#include "controller/doors/doorsController.hpp"
#include "controller/bme280/bme280Controller.hpp"
#include "controller/airConditioner/airConditioner.hpp"

using namespace std;

AirConditionerController air;
WindowsController window;
LampsController lamp;
DoorsController door;
BmeController bme;

void socketTreatment(int socketCliente)
{
	char buffer[16];
	int tamanhoRecebido;
	int num;

	if ((tamanhoRecebido = recv(socketCliente, buffer, 16, 0)) < 0)
		printf("Error in recv()\n");

	string mensagem;

	switch (atoi(buffer))
	{
	case 1:
		mensagem = lamp.powerOn(0);
		break;
	case 2:
		mensagem = lamp.powerOn(1);
		break;
	case 3:
		mensagem = lamp.powerOn(2);
		break;
	case 4:
		mensagem = lamp.powerOn(3);
		break;
	case 5:
		mensagem = lamp.powerOff(0);
		break;
	case 6:
		mensagem = lamp.powerOff(1);
		break;
	case 7:
		mensagem = lamp.powerOff(2);
		break;
	case 8:
		mensagem = lamp.powerOff(3);
		break;
	case 9:
		air.powerOn(23);
		break;
	case 10:
		air.powerOn(24);
		break;
	case 11:
		air.powerOff(23);
		break;
	case 12:
		air.powerOff(24);
		break;
	case 15:
	{
		bme.readValues();
		float temperature = bme.getTemperature();
		float humidity = bme.getHumidity();
		mensagem = "Temperatura: " + to_string(temperature) + " Humidade: " + to_string(humidity) + "%";
	}

	default:
		break;
	}
	cout << mensagem << endl;
	send(socketCliente, mensagem.c_str(), mensagem.length(), 0);
	mensagem.clear();
	memset(buffer, 0, sizeof buffer);
}

int main()
{
	lamp.initializeGpio();
	bme.initializeBme();

	int ditrinutedSocket;
	int clientSocket;

	struct sockaddr_in distributedServerAddr;
	struct sockaddr_in clientAddr;

	unsigned int clientLength;

	ditrinutedSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	distributedServerAddr.sin_family = AF_INET;
	distributedServerAddr.sin_port = htons(10108);
	distributedServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(ditrinutedSocket, (struct sockaddr *)&distributedServerAddr, sizeof(distributedServerAddr)) < 0)
		cerr << "Can't bind to IP/port";

	// Listen
	if (listen(ditrinutedSocket, SOMAXCONN) < 0)
		cerr << "Can't bind to IP/port";

	while (1)
	{
		clientLength = sizeof(clientAddr);
		if ((clientSocket = accept(ditrinutedSocket,
															 (struct sockaddr *)&clientAddr,
															 &clientLength)) < 0)
			printf("Accept Failed\n");

		printf("Cliente Connection %s\n", inet_ntoa(clientAddr.sin_addr));
		socketTreatment(clientSocket);
		close(clientSocket);
	}
	close(ditrinutedSocket);

	return 0;
}
