#include "gpioController.hpp"

void GpioController::initializeGpio()
{
  int initializeWirinpi = wiringPiSetup();
  if (initializeWirinpi < 0)
  {
    cout << "Couldnt initilize wiringPi";
    exit(1);
  }
}