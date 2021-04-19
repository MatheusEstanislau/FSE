#include "presenceSensorController.hpp"

string PresenceSensor::readValue(int pin)
{
  if (pin != 6 && pin != 25)
  {
    return "Invalid Pin\n";
  }
  else
  {
    string presence;
    string state;
    pin == 6 ? presence = "01" : presence = "02";
    pinMode(pin, INPUT);
    int response = digitalRead(pin);
    response == 0 ? state = "no presence" : state = "activated";
    return "Presence sensor " + presence + ": " + state + "\n";
  }
}