#include "windowController.hpp"

void WindowsController::readValue(int pin)
{
  if ( pin != 22 && pin != 27 && pin != 28 && pin != 29 )
  {
    cout << "Invalid Pin" << endl;
  }
  else
  {
    string window;
    string state;
    pin == 22 ? window = "kitchen" : pin == 27 ? window = "living room"  : pin == 28 ? window = "room" : "room 2";
    pinMode(pin,INPUT);
    int response = digitalRead(pin);
    response == 0 ? state = "closed" : state = "opened";
    cout << "Window " << window << " " << state << endl;
  }
}