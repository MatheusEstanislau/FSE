#include <iostream>
#include <pthread.h>
#include <csignal>
#include "../inc/socketServer.hpp"
#include "../inc/gpioController.hpp"
#include "../inc/socketClient.hpp"

using namespace std;

GpioController gpio;
BmeController bme280;
SocketServer serverSocket;
SocketClient alarmSocket;

void poweroff(int exitAlarm)
{
  cout << endl
       << "...Shutting down the system" << endl;
  alarmSocket.closeSocket();
  serverSocket.closeSocket();
  cout << endl
       << "System off" << endl;
  exit(0);
}

void sendAlarm()
{
  alarmSocket.callServer();
  cout << alarmSocket.getResponse() << endl;
  alarmSocket.closeSocket();
}

int main(int argc, char const *argv[])
{
  signal(SIGINT, poweroff);
  bme280.initializeBme();
  gpio.initializeGpio();
  pthread_t t1, t2;
  wiringPiISR(6, INT_EDGE_RISING, sendAlarm);
  wiringPiISR(21, INT_EDGE_RISING, sendAlarm);
  wiringPiISR(22, INT_EDGE_RISING, sendAlarm);
  wiringPiISR(25, INT_EDGE_RISING, sendAlarm);
  wiringPiISR(26, INT_EDGE_RISING, sendAlarm);
  wiringPiISR(27, INT_EDGE_RISING, sendAlarm);
  wiringPiISR(28, INT_EDGE_RISING, sendAlarm);
  wiringPiISR(29, INT_EDGE_RISING, sendAlarm);
  serverSocket.runSocketServer();
  return 0;
}