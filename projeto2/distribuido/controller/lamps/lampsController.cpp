#include "lampsController.hpp"
#include <string>

void LampsController::initializeGpio() {
  int initializeWirinpi = wiringPiSetup();
  if (initializeWirinpi < 0)
  {
    cout << "Não foi possivel iniciar wiringPi";
    exit(1);
  }
}

string LampsController::powerOn(int pin)
{
  if (pin > 3)
  {
    cout << "Pino Inválido" << endl;
  }
  else
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    string s;
    return s = "Lam " + to_string(pin + 1) + " turn on";
  }
}

string LampsController::powerOff(int pin)
{
  if (pin > 3)
  {
    cout << "Pino Inválido" << endl;
  }
  else
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    string s;
    return s = "Lam " + to_string(pin + 1) + " turn off";
  }
}