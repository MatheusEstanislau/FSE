#include "doorsController.hpp"

string DoorsController::readValue(int pin) {
  if ( pin != 21 && pin != 26 )
  {
    return "Invalid Pin\n";
  }
  else
  {
    string door;
    string state;
    pin == 21 ? door = "kitchen" : door = "living room";
    pinMode(pin,INPUT);
    int response = digitalRead(pin);
    response == 0 ? state = "closed" : state = "opened";
    return "Door " + door + ": " + state + "\n";
  }
}