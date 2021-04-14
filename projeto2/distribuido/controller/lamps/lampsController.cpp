#include "lampsController.hpp"

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