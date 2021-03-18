#include <wiringPi.h>
#include <softPwm.h>

int wiringPiSetup();

void activateResistor(int value){
  pinMode(4,OUTPUT);
  softPwmCreate(4, 0, 100);
  softPwmWrite(4, value);
}

void disableResistor(){
  softPwmCreate(4, 0, 100);
  pinMode(4,OUTPUT);
  softPwmWrite(4, 0);
}

void activateCooler(int value){
  pinMode(5,OUTPUT);
  softPwmCreate(5, 0, 100);
  softPwmWrite(5, value);
}

void disableCooler(){
  pinMode(5,OUTPUT);
  softPwmCreate(5, 0, 100);
  softPwmWrite(5, 0);
}