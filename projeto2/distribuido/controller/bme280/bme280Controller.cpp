#include "bme280Controller.hpp"

void BmeController::initializeBme()
{
  int init = bme280Init(0x01, 0x76);
  if (init != 0)
  {
    cout << "Erro ao inicializar bme280" << endl;
    exit(0);
  }
}

void BmeController::readValues()
{
  bme280ReadValues(&temperature, &pression, &humidity);
}

float BmeController::getTemperature(){
  return temperature/100.0;
}

float BmeController::getPression(){
  return pression/256.0;
}

float BmeController::getHumidity(){
  return humidity/1024.0;
}