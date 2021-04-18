#include <iostream>
#include <wiringPi.h>

using namespace std;

class AirConditionerController
{
public:
  string powerOn(int pin);
  string powerOff(int pin);
};