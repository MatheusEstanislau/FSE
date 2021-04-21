#include <iostream>
#include <wiringPi.h>

using namespace std;

class WindowsController
{
public:
  string readValue(int pin);
};