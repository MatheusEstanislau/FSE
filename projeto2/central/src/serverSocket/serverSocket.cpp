#include "serverSocket.hpp"

using namespace std;

int ditrinutedSocket;
int clientSocket;

void socketTreatment(int clientSocket)
{
	vector<char> buf(5000);
	int bytes = recv(clientSocket, buf.data(), buf.size(), 0);
	string s(buf.begin(), buf.end());
	cout << s << endl;
	buf.clear();
}

void SocketServer::runSocketServer()
{

	struct sockaddr_in distributedServerAddr;
	struct sockaddr_in clientAddr;

	unsigned int clientLength;

	ditrinutedSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	distributedServerAddr.sin_family = AF_INET;
	distributedServerAddr.sin_port = htons(10008);
	distributedServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(ditrinutedSocket, (struct sockaddr *)&distributedServerAddr, sizeof(distributedServerAddr)) < 0)
		cerr << "Can't bind to IP/port";

	// Listen
	if (listen(ditrinutedSocket, SOMAXCONN) < 0)
		cerr << "Can't bind to IP/port";

	// you are using C++ not C
	while (1)
	{
		clientLength = sizeof(clientAddr);
		if ((clientSocket = accept(ditrinutedSocket,
															 (struct sockaddr *)&clientAddr,
															 &clientLength)) < 0)
			printf("Accept Failed\n");
		socketTreatment(clientSocket);
		printf("Cliente Connection %s\n", inet_ntoa(clientAddr.sin_addr));
		close(clientSocket);
	}
	close(ditrinutedSocket);
}

void SocketServer::closeSocket()
{
	close(clientSocket);
	close(ditrinutedSocket);
}

bool SocketServer::getAlarm() {
	return alarmState;
}

void SocketServer::setAlarm(bool state) {
	alarmState = state;
}

string SocketServer::getResponse()
{
	return response;
}