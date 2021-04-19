#include <iostream>
#include <wiringPi.h>

using namespace std;

class DoorsController
{
public:
  string readValue(int pin);
};