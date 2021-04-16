#include <iostream>
#include <wiringPi.h>

using namespace std;

class LampsController
{
public:
  void initializeGpio();
  string powerOn(int pin);
  string powerOff(int pin);
};