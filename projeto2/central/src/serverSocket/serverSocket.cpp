#include "../../inc/serverSocket.hpp"

using namespace std;

int centralSocket;
int clientSocket;

void SocketServer::socketTreatment()
{
	string responseClient = "Ok, message received";
	vector<char> buf(5000);
	int bytes = recv(clientSocket, buf.data(), buf.size(), 0);
	string s(buf.begin(), buf.end());
	response = true;
	send(clientSocket, responseClient.c_str(), responseClient.length(), 0);
	buf.clear();
	responseClient.clear();
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

	if (listen(centralSocket, SOMAXCONN) < 0)
		cerr << "Can't Listen";

	while (1)
	{
		clientLength = sizeof(clientAddr);
		if ((clientSocket = accept(centralSocket, (struct sockaddr *)&clientAddr, &clientLength)) < 0)
			cerr << "Accept Failed" << endl;
		cout << "Client Connection: " << inet_ntoa(clientAddr.sin_addr) << endl;
		socketTreatment();
		close(clientSocket);
	}
	close(centralSocket);
}

void SocketServer::closeSocket()
{
	close(clientSocket);
	close(centralSocket);
}

void SocketServer::setResponse(bool newState)
{
	response = newState;
}

bool SocketServer::getResponse()
{
	return response;
}