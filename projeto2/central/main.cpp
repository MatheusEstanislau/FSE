#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "src/menu/menu.hpp"
#include "src/server/server.hpp"

Menu menu;
Server server;
Server bmeValues;

void *threadFunction(void *)
{
	while (1)
	{
		bmeValues.callServer(15);
		usleep(1000000);
	}
}

void *threadFunction2(void *)
{
	int command;
	while (1)
	{
		cout << bmeValues.getResponse() << endl;
		menu.displayMenu();
		command = menu.getCommand();
		server.callServer(command);
		cout << server.getResponse() << endl;
	}
}

int main()
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, threadFunction2, NULL);
	pthread_create(&t2, NULL, threadFunction, NULL);
	pthread_join(t2, NULL);
	pthread_join(t1, NULL);
	return 0;
}
