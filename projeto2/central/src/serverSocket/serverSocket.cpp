#include "../../inc/serverSocket.hpp"

using namespace std;

int centralSocket;
int clientSocket;

void SocketServer::socketTreatment(int clientSocket)
{
	string response = "OK";
	vector<char> buf(5000);
	int bytes = recv(clientSocket, buf.data(), buf.size(), 0);
	string s(buf.begin(), buf.end());
	cout << s << endl;
	response = "Ativar alarme";
	send(clientSocket, response.c_str(), response.length(), 0);
	buf.clear();
	response.clear();
}

void SocketServer::runSocketServer()
{

	struct sockaddr_in centralServerAddr;
	struct sockaddr_in clientAddr;

	unsigned int clientLength;

	centralSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	centralServerAddr.sin_family = AF_INET;
	centralServerAddr.sin_port = htons(10008);
	centralServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(centralSocket, (struct sockaddr *)&centralServerAddr, sizeof(centralServerAddr)) < 0)
		cerr << "Can't bind to IP/port";

	// Listen
	if (listen(centralSocket, SOMAXCONN) < 0)
		cerr << "Can't bind to IP/port";

	// you are using C++ not C
	while (1)
	{
		clientLength = sizeof(clientAddr);
		if ((clientSocket = accept(centralSocket,
															 (struct sockaddr *)&clientAddr,
															 &clientLength)) < 0)
			printf("Accept Failed\n");
		socketTreatment(clientSocket);
		printf("Cliente Connection %s\n", inet_ntoa(clientAddr.sin_addr));
		close(clientSocket);
	}
	close(centralSocket);
}

void SocketServer::closeSocket()
{
	close(clientSocket);
	close(centralSocket);
}


string SocketServer::getResponse()
{
	return response;
}