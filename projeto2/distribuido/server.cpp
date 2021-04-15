#include <iostream>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

#include "controller/lamps/lampsController.hpp"
#include "controller/windows/windowController.hpp"
#include "controller/doors/doorsController.hpp"
#include "controller/bme280/bme280Controller.hpp"

using namespace std;

WindowsController window;
LampsController lamp;
DoorsController door;
BmeController bme;

void socketTreatment(int socketCliente)
{
	char buffer[16];
	int tamanhoRecebido;

	if ((tamanhoRecebido = recv(socketCliente, buffer, 16, 0)) < 0)
		printf("Error in recv()\n");

	while (tamanhoRecebido > 0)
	{
		if (send(socketCliente, buffer, tamanhoRecebido, 0) != tamanhoRecebido)
			printf("Error in send()\n");

		if ((tamanhoRecebido = recv(socketCliente, buffer, 16, 0)) < 0)
			printf("Error in recv()\n");
	}
}

int main()
{
	lamp.initializeGpio();
	bme.initializeBme();
	bme.readValues();
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
			printf("Falha no Accept\n");

		printf("Conexão do Cliente %s\n", inet_ntoa(clientAddr.sin_addr));
		socketTreatment(clientSocket);
		close(clientSocket);
	}
	close(ditrinutedSocket);

	return 0;
}
