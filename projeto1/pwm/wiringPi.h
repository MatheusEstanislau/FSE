#ifndef __WIRINGPI__
#define __WIRINGPI__

int wiringPiSetup();
void activateResistor(int value);
void disableResistor();
void activateCooler(int value);
void disableCooler();

#endif // __WIRINGPI__