#include "airConditioner.hpp"

void AirConditionerController::powerOn(int pin)
{
  switch (pin)
  {
  case 23:
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    cout << "Air Conditioner on" << endl;
    break;
  case 24:
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    cout << "Air Conditioner on" << endl;
    break;
  default:
    break;
  }
}

void AirConditionerController::powerOff(int pin)
{
  switch (pin)
  {
  case 23:
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    cout << "Air Conditioner off" << endl;
    break;
  case 24:
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    cout << "Air Conditioner off" << endl;
    break;
  default:
    break;
  }
}