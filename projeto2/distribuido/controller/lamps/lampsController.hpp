#include <iostream>
#include <wiringPi.h>

using namespace std;

class LampsController
{
public:
  void initializeGpio();
  void powerOn(int pin);
  void powerOff(int pin);
};