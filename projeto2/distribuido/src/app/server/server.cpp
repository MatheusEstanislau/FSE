#include "socketServer.hpp"

using namespace std;

AirConditionerController air;
LampsController lamp;
BmeController bme;
PresenceSensor presence;
DoorsController doors;
WindowsController windows;

int ditrinutedSocket;
int clientSocket;

void socketTreatment(int socketCliente)
{
	char buffer[16];
	int tamanhoRecebido;
	int num;

	if ((tamanhoRecebido = recv(socketCliente, buffer, 16, 0)) < 0)
		printf("Error in recv()\n");

	string message;

	switch (atoi(buffer))
	{
	case 1:
		message = lamp.powerOn(0);
		break;
	case 2:
		message = lamp.powerOn(1);
		break;
	case 3:
		message = lamp.powerOn(2);
		break;
	case 4:
		message = lamp.powerOn(3);
		break;
	case 7:
		message = lamp.powerOff(0);
		break;
	case 8:
		message = lamp.powerOff(1);
		break;
	case 9:
		message = lamp.powerOff(2);
		break;
	case 10:
		message = lamp.powerOff(3);
		break;
	case 5:
		message = air.powerOn(23);
		break;
	case 6:
		message = air.powerOn(24);
		break;
	case 11:
		message = air.powerOff(23);
		break;
	case 12:
		message = air.powerOff(24);
		break;
	case 16:
		message = presence.readValue(6) + presence.readValue(25) + doors.readValue(21) + doors.readValue(26) + windows.readValue(22) + windows.readValue(27) + windows.readValue(28) + windows.readValue(29);
		break;
	case 15:
	{
		bme.readValues();
		int temperature = bme.getTemperature();
		int humidity = bme.getHumidity();
		message = "Temperature: " + to_string(temperature) + " ºC" + " Humidity: " + to_string(humidity) + "%";
	}

	default:
		break;
	}
	cout << message << endl;
	send(socketCliente, message.c_str(), message.length(), 0);
	message.clear();
	memset(buffer, 0, sizeof buffer);
}

void SocketServer::runSocketServer()
{
	//bme.initializeBme();

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
}

void SocketServer::closeSocket()
{
	close(ditrinutedSocket);
	close(clientSocket);
}
