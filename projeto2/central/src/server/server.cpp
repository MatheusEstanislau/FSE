#include "server.hpp"

void Server::callServer(int request) {
	int clienteSocket;
	struct sockaddr_in serverAddr;
	unsigned short servidorPorta;
	char mensagem;
	char buffer[16];
	unsigned int tamanhoMensagem;

	mensagem = request +'0';

	int bytesRecebidos;
	int totalBytesRecebidos;

	// Criar Socket
	if ((clienteSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		printf("Erro no socket()\n");

	// Construir struct sockaddr_in
	memset(&serverAddr, 0, sizeof(serverAddr)); // Zerando a estrutura de dados
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("192.168.0.52");
	serverAddr.sin_port = htons(10108);

	// Connect
	if (connect(clienteSocket, (struct sockaddr *)&serverAddr,
							sizeof(serverAddr)) < 0)
		printf("Erro no connect()\n");

	tamanhoMensagem = strlen(&mensagem);

	if (send(clienteSocket, &mensagem, tamanhoMensagem, 0) != tamanhoMensagem)
		printf("Erro no envio: numero de bytes enviados diferente do esperado\n");

	totalBytesRecebidos = 0;
	while (totalBytesRecebidos < tamanhoMensagem)
	{
		if ((bytesRecebidos = recv(clienteSocket, buffer, 16 - 1, 0)) <= 0)
			printf("Não recebeu o total de bytes enviados\n");
		totalBytesRecebidos += bytesRecebidos;
		buffer[bytesRecebidos] = '\0';
    response = atoi(buffer);
	}
	close(clienteSocket);
}

int Server::getResponse(){
  return response;
}