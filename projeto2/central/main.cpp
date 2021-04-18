#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "src/menu/menu.hpp"
#include "src/clientSocket/server.hpp"
#include "src/serverSocket/serverSocket.hpp"

Menu menu;
Server server;
Server bmeValues;
SocketServer alarmSocket;

int flagStop = 0;

void *threadFunction(void *)
{
	while (1)
	{
		bmeValues.callServer(15);
		if (flagStop == 0)
		{
			cout << bmeValues.getResponse() << endl;
		}
		usleep(1000000);
	}
}

void *threadFunction2(void *)
{
	int command;
	while (1)
	{
		if (flagStop == 0)
		{
			cout << "Digite 1 para abrir o menu" << endl;
			cin >> flagStop;
		}
		else
		{
			menu.displayMenu();
			command = menu.getCommand();
			server.callServer(command);
			cout << server.getResponse() << endl;
			flagStop = 0;
		}
	}
}

void *threadFunction3(void *)
{
	int command;
	while (1)
	{
		alarmSocket.runSocketServer();
		cout << alarmSocket.getResponse() << endl;
	}
}

int main()
{
	pthread_t t1, t2, t3;
	pthread_create(&t1, NULL, threadFunction2, NULL);
	pthread_create(&t2, NULL, threadFunction, NULL);
	pthread_create(&t1, NULL, threadFunction3, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t1, NULL);
	return 0;
}