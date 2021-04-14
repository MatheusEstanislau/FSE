#include <iostream>
#include <wiringPi.h>

using namespace std;

class DoorsController
{
public:
  void readValue(int pin);
};