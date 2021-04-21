#include <iostream>
#include <wiringPi.h>

using namespace std;

class PresenceSensor
{
public:
  string readValue(int pin);
};