#include <iostream>
#include "bme280.h"

using namespace std;

class BmeController
{
  int temperature;
  int pression;
  int humidity;
public:
  void initializeBme();
  void readValues();
};