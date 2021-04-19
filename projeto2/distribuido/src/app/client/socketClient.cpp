#include "socketClient.hpp"
#include <string>
#include <vector>
#include <string.h>
#include <wiringPi.h>

char buffer[16];

int clienteSocket;

void SocketClient::callServer()
{

	struct sockaddr_in serverAddr;
	unsigned short servidorPorta;

	string mensagem = "Sensor detected presence\n alarm trigger";

	int tamanhoMensagem;
	int bytesRecebidos;
	int totalBytesRecebidos;

	if ((clienteSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		cout << "Error in socket" << endl;

	memset(&serverAddr, 0, sizeof(serverAddr)); // Zerando a estrutura de dados
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("192.168.0.53");
	serverAddr.sin_port = htons(10008);

	if (connect(clienteSocket, (struct sockaddr *)&serverAddr,
							sizeof(serverAddr)) < 0)
		cout << "Connect Error" << endl;

	send(clienteSocket, mensagem.c_str(), mensagem.length(), 0);
	totalBytesRecebidos = 0;
	vector<char> buf(5000);
	int bytes = recv(clienteSocket, buf.data(), buf.size(), 0);
	string s(buf.begin(), buf.end());
	cout << mensagem << endl;
	mensagem.clear();
}

void SocketClient::closeSocket()
{
	close(clienteSocket);
}

string SocketClient::getResponse()
{
	return response;
}