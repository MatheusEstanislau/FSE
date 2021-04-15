#include "lampsController.hpp"

void LampsController::initializeGpio() {
  int initializeWirinpi = wiringPiSetup();
  if (initializeWirinpi < 0)
  {
    cout << "Não foi possivel iniciar wiringPi";
    exit(1);
  }
}

void LampsController::powerOn(int pin)
{
  if (pin > 3)
  {
    cout << "Pino Inválido" << endl;
  }
  else
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    cout << "Lampada " << pin + 1 << " Ligada" << endl;
  }
}

void LampsController::powerOff(int pin)
{
  if (pin > 3)
  {
    cout << "Pino Inválido" << endl;
  }
  else
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    cout << "Lampada " << pin + 1 << " Desligada" << endl;
  }
}