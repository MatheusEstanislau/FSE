#include <iostream>
#include <wiringPi.h>

using namespace std;

class PresenceSensor
{
public:
  void readValue(int pin);
};