#include "server.hpp"
#include <string>
#include <vector>
#include <string.h>

char buffer[16];

void Server::callServer(int request)
{
	int clienteSocket;
	struct sockaddr_in serverAddr;
	unsigned short servidorPorta;

	string mensagem = to_string(request);

	int tamanhoMensagem;
	int bytesRecebidos;
	int totalBytesRecebidos;

	// Criar Socket
	if ((clienteSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		cout << "Error in socket" << endl;

	// Construir struct sockaddr_in
	memset(&serverAddr, 0, sizeof(serverAddr)); // Zerando a estrutura de dados
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("192.168.0.4");
	serverAddr.sin_port = htons(10108);

	// Connect
	if (connect(clienteSocket, (struct sockaddr *)&serverAddr,
							sizeof(serverAddr)) < 0)
		cout << "Connect Error" << endl;

	tamanhoMensagem = mensagem.length();

	if (send(clienteSocket, mensagem.c_str(), mensagem.length(), 0) != tamanhoMensagem)
		printf("\n");

	totalBytesRecebidos = 0;
	vector<char> buf(5000); // you are using C++ not C
	int bytes = recv(clienteSocket, buf.data(), buf.size(), 0);
	string s(buf.begin(), buf.end());
	response = s;
	close(clienteSocket);
}

string Server::getResponse()
{
	return response;
}