#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <thread>
#include <csignal>
#include <iostream>

#include "../inc/menu.hpp"
#include "../inc/server.hpp"
#include "../inc/serverSocket.hpp"
#include "../inc/generateLog.hpp"
#include "../inc/alarmHandler.hpp"

using namespace std;

Menu menu;
Server server;
Server bmeValues;
SocketServer alarmSocket;
Alarm myAlarm;

int flagStop = 0;

string alarmSecret = "Ativar alarme";

void monitoring()
{
	server.callServer(16);
	cout << server.getResponse() << endl;
}

void poweroff(int exitAlarm)
{
	cout << endl
			 << "...Shutting down the system" << endl;
	alarmSocket.closeSocket();
	bmeValues.closeSocket();
	server.closeSocket();
	cout << endl
			 << "System off" << endl;
	exit(0);
}

void threadFunction()
{
	while (1)
	{
		bmeValues.callServer(15);
		if (flagStop == 0 && !myAlarm.getAlarmState() && "Ativar alarme" == alarmSecret)
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
		int handler = 1;
		if (myAlarm.getAlarmState() && "Ativar alarme" == alarmSecret)
		{
			myAlarm.playAlarm();
		}
		if (flagStop == 0)
		{
			cout << "Insert 1 to open the menu" << endl;
			cin >> flagStop;
		}
		else
		{
			while (handler != 0)
			{
				menu.displayMenu();
				command = menu.getCommand();

				if (command == 13)
				{
					myAlarm.setAlarmState(true);
				}
				else if (command == 14)
				{
					myAlarm.setAlarmState(false);
				}
				else if (command == 15)
				{
					int temp = 1;
					while (temp != 0)
					{
						monitoring();
						cout << "Enter 1 to re-monitor the system" << endl;
						cin >> temp;
						switch (temp)
						{
						case 0:
							temp = 0;
							break;
						case 1:
							break;
						default:
							cout << "Invalid option, exiting monitoring" << endl;
							temp = 0;
							break;
						}
					}
				}
				else
				{
					server.callServer(command);
					cout << server.getResponse() << endl;
				}
				writeInCsv(command, myAlarm.getAlarmState());
				cout << "Digite 1 para continuar, ou 0 para sair do menu" << endl;
				cin >> handler;
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
	thread getBme(threadFunction);
	thread menuHandler(threadFunction2);
	thread alarmScoket(threadFunction3);
	getBme.join();
	menuHandler.join();
	alarmScoket.join();
	return 0;
}