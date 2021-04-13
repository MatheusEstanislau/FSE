#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <vector>

extern "C"{
    #include "bme280.h"
}

using namespace std;

int temperature, humidity, pression;
vector<int> values;

void initializeBme() {
  int init = bme280Init(0x01, 0x76);
  if (init != 0)
  {
    cout << "Erro ao inicializar bme280" << endl;
    exit(0);
  }
}

vector<int> readValues() {
  bme280ReadValues(&temperature, &pression, &humidity);
  values.push_back(temperature);
  values.push_back(pression);
  values.push_back(humidity);
  return values;
}