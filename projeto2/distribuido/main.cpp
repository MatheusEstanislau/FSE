#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>

#include "controller/lamps/lampsController.hpp"
#include "controller/windows/windowController.hpp"
#include "controller/doors/doorsController.hpp"

// #include "bme280/bme-read-values.h"

using namespace std;

//vector<int> myvalues;
string message;

int main() {
  int initializeWirinpi = wiringPiSetup();
  if (initializeWirinpi < 0)
  {
    cout << "Não foi possivel iniciar wiringPi";
    exit(1);
  }
  
  WindowsController window;
  LampsController lamp;
  DoorsController door;
  door.readValue(26);
  // lamp.powerOff(5);
  // initializeBme();
  // while (1)
  // {
  //   myvalues = readValues();
  //   printf("temperatura: %3.2f ºC\n", (float)myvalues[0]/100.0);
  //   printf("umidade: %2.2f%%\n", (float)myvalues[2]/1024.0);
  //   printf("pressão: %6.2f Pa\n", (float)myvalues[1]/256.0);
  //   cout << endl;
  //   usleep(1000000);
  // }
  return 0;
}