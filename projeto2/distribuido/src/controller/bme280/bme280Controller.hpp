#include <iostream>

extern "C"{
    #include "bme280.h"
}

using namespace std;

class BmeController
{
  int temperature;
  int pression;
  int humidity;

public:
  void initializeBme();
  void readValues();
  float getTemperature();
  float getPression();
  float getHumidity();
};