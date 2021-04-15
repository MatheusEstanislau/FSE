#include <iostream>
#include <wiringPi.h>

using namespace std;

class AirConditionerController
{
public:
  void powerOn(int pin);
  void powerOff(int pin);
};