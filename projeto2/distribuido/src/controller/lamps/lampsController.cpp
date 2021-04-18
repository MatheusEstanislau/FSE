#include "lampsController.hpp"
#include <string>

string LampsController::powerOn(int pin)
{
  string s;
  if (pin > 3)
  {
    return s = "Invalid Pin";
  }
  else
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);

    return s = "Lam " + to_string(pin + 1) + " turn on";
  }
}

string LampsController::powerOff(int pin)
{
  string s;
  if (pin > 3)
  {
    return s = "Invalid pin";
  }
  else
  {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    string s;
    return s = "Lamp " + to_string(pin + 1) + " turn off";
  }
}