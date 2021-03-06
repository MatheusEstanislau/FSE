#include "../../../inc/socketServer.hpp"
#include <chrono>
#include <ctime>

using namespace std;

AirConditionerController air;
LampsController lamp;
BmeController bme;
PresenceSensor presence;
DoorsController doors;
WindowsController windows;

string lamp1 = "Lamp 1: Turn off\n", lamp2 = "Lamp 2: Turn off\n", lamp3 = "Lamp 3: Turn off\n", lamp4 = "Lamp 4: Turn off\n", air1 = "Air 01: Turn off\n", air2 = "Air 01: Turn off\n";

int ditrinutedSocket;
int clientSocket;

string getTimeStr()
{
	time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());

	string s(30, '\0');
	strftime(&s[0], s.size(), "%Y/%m/%d %H:%M:%S", localtime(&now));
	return s;
}

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
		lamp1 = "Lamp 1: Turn on\n";
		break;
	case 2:
		message = lamp.powerOn(1);
		lamp2 = "Lamp 2: Turn on\n";
		break;
	case 3:
		message = lamp.powerOn(2);
		lamp3 = "Lamp 3: Turn on\n";
		break;
	case 4:
		message = lamp.powerOn(3);
		lamp4 = "Lamp 4: Turn on\n";
		break;
	case 7:
		message = lamp.powerOff(0);
		lamp1 = "Lamp 1: Turn off\n";
		break;
	case 8:
		message = lamp.powerOff(1);
		lamp2 = "Lamp 2: Turn off\n";
		break;
	case 9:
		message = lamp.powerOff(2);
		lamp3 = "Lamp 3: Turn off\n";
		break;
	case 10:
		message = lamp.powerOff(3);
		lamp3 = "Lamp 4: Turn off\n";
		break;
	case 5:
		message = air.powerOn(23);
		air1 = "Air 01: Turn on\n";
		break;
	case 6:
		message = air.powerOn(24);
		air2 = "Air 02: Turn on\n";
		break;
	case 11:
		message = air.powerOff(23);
		air1 = "Air 01: Turn off\n";
		break;
	case 12:
		message = air.powerOff(24);
		air2 = "Air 02: Turn off\n";
		break;
	case 16:
		message = lamp1 + lamp2 + lamp3 + lamp4 + air1 + air2 + presence.readValue(6) + presence.readValue(25) + doors.readValue(21) + doors.readValue(26) + windows.readValue(22) + windows.readValue(27) + windows.readValue(28) + windows.readValue(29);
		break;
	case 15:
	{
		bme.readValues();
		int temperature = bme.getTemperature();
		int humidity = bme.getHumidity();
		message = "Temperature: " + to_string(temperature) + " ??C" + " Humidity: " + to_string(humidity) + "%";
	}

	default:
		break;
	}
	send(socketCliente, message.c_str(), message.length(), 0);
	cout << getTimeStr() << ": " << message << endl;
	message.clear();
	memset(buffer, 0, sizeof buffer);
}

void SocketServer::runSocketServer()
{

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
		cerr << "Can't listen";

	while (1)
	{
		clientLength = sizeof(clientAddr);
		if ((clientSocket = accept(ditrinutedSocket,
															 (struct sockaddr *)&clientAddr,
															 &clientLength)) < 0)
			printf("Accept Failed\n");

		cout << "Cliente Connection: " << inet_ntoa(clientAddr.sin_addr) << endl;
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
