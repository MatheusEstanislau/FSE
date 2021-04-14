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
  cout << temperature / 100 << endl
       << pression / 256 << endl
       << humidity / 1024 << endl;
}