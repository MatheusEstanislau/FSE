#include <stdio.h>
#include <stdlib.h>
#include "bme280/bme280.h"
#include "uartModBus/uart.h"
#include <unistd.h>
#include "i2c/i2c.h"
#include "pwm/wiringPi.h"
#include "pid/pid.h"
#include "file/writeCsv.h"
#include <signal.h>

float ventoinha;
float resistor;
int flagStop = 0;
float referenceTemperature = 0;
float user;
void poweroff()
{
  disableCooler();
  disableResistor();
  ClrLcd();
  printf("\nDesligando Sistema\n");
  exit(0);
}

void waitFunction()
{
  alarm(1);
}

void userInsertStop()
{
  flagStop = 1;
  printf("\nInsira a temperatura desejada: \n");
  scanf("%f", &user);
}

int main(int argc, char const *argv[])
{
  wiringPiSetup();
  initWrite();
  initializeUart();
  pid_configura_constantes(5.0, 1.0, 5.0);
  int initialize;
  float potentiometer, lm35;
  int Temperature, Pressure, Humidity;
  initialize = bme280Init(1, 0x76);
  printf("referencia antes: %f\n", referenceTemperature);
  signal(SIGINT, poweroff);
  signal(SIGALRM, waitFunction);
  alarm(1);
  while (1)
  {
    signal(SIGTSTP, userInsertStop);
    potentiometer = getPotentiometerData();
    if (flagStop == 0)
    {
      referenceTemperature = potentiometer;
    }
    else
    {
      referenceTemperature = user;
    }
    lm35 = getLM35Data();
    bme280ReadValues(&Temperature, &Pressure, &Humidity);
    pid_atualiza_referencia(referenceTemperature);

    double controle = pid_controle(lm35);

    if (controle > 0)
    {
      activateResistor(controle);
      disableCooler();
      resistor = controle;
      ventoinha = 0;
    }
    else if (controle < -40)
    {
      activateCooler((controle * -1));
      disableResistor();
      ventoinha = controle * -1;
      resistor = 0;
    }
    printf("\n|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("| Text = %.2f ºC, Tint. = %.2f%%  Tref = %.2f     |\n", (float)Temperature / 100, lm35, referenceTemperature);
    printf("| Uso Ventoinha: %.2f %% Uso Resistor: %.2f %%           |\n", ventoinha, resistor);
    printf("|  difite: ctrl + z para entrar com sua temperatura  |\n");
    printf("|---------------------------------------------------|\n");
    writeInLcd(referenceTemperature, lm35, (float)Temperature / 100);
    writeInCsv((float)Temperature / 100, (float)lm35, (float)referenceTemperature, ventoinha, resistor);
    pause();
  }
  return 0;
}