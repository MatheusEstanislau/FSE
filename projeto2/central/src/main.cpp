#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <thread>
#include <csignal>

#include "../inc/menu.hpp"
#include "../inc/server.hpp"
#include "../inc/serverSocket.hpp"
#include "../inc/generateLog.hpp"

using namespace std;

Menu menu;
Server server;
Server bmeValues;
SocketServer alarmSocket;

int flagStop = 0;

void poweroff(int exitAlarm)
{
	cout << endl
			 << "...Desligando Sistema" << endl;
	alarmSocket.closeSocket();
	bmeValues.closeSocket();
	server.closeSocket();
	cout << endl
			 << "Sistema desligado" << endl;
	exit(0);
}

void threadFunction()
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

void threadFunction2()
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
			writeInCsv(command, alarmSocket.getAlarm());
			if (command == 13)
			{
				alarmSocket.setAlarm(true);
			}
			else if (command == 14)
			{
				alarmSocket.setAlarm(false);
			}
			else if (command == 15)
			{
				int temp;
				server.callServer(16);
				cout << server.getResponse() << endl;
				cout << "Insira qualquer numero para continuar" << endl;
				cin >> temp;
			}
			else
			{
				server.callServer(command);
				cout << server.getResponse() << endl;
			}
			flagStop = 0;
		}
	}
}

void threadFunction3()
{
	alarmSocket.runSocketServer();
}

int main()
{
	signal(SIGINT, poweroff);
	initWrite();
	thread getBme (threadFunction);
	thread menuHandler (threadFunction2);
	thread alarmScoket (threadFunction3);
	getBme.join();
	menuHandler.join();
	alarmScoket.join();
	return 0;
}