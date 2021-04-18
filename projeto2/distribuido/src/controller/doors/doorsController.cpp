#include "doorsController.hpp"

void DoorsController::readValue(int pin) {
  if ( pin != 21 && pin != 26 )
  {
    cout << "Invalid Pin" << endl;
  }
  else
  {
    string door;
    string state;
    pin == 21 ? door = "kitchen" : door = "living room";
    pinMode(pin,INPUT);
    int response = digitalRead(pin);
    response == 0 ? state = "closed" : state = "opened";
    cout << "Door " << door << " " << state << endl;
  }
}