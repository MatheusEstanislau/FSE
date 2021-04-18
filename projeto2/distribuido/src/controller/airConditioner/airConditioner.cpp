#include "airConditioner.hpp"

string AirConditionerController::powerOn(int pin)
{
  string s;
  switch (pin)
  {
  case 23:
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    return s = "Air conditioner 1 turn on";
  case 24:
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    return s = "Air conditioner 2 turn on";
  default:
    return s;
  }
}

string AirConditionerController::powerOff(int pin)
{
  string s;
  switch (pin)
  {
  case 23:
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    return s = "Air conditioner 1 turn off";
  case 24:
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    return s = "Air conditioner 2 turn off";
  default:
    return s;
  }
}