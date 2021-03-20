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

int ventoinha;
int resistor;

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
  signal(SIGINT, poweroff);
  signal(SIGALRM, waitFunction);
  alarm(1);
  while (1)
  {
    potentiometer = getPotentiometerData();
    lm35 = getLM35Data();
    bme280ReadValues(&Temperature, &Pressure, &Humidity);
    pid_atualiza_referencia(potentiometer);

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
      ventoinha = controle*-1;
      resistor = 0;
    }
    printf("\n|---------------------------------------------------|\n");
    printf("|                                                   |\n");
    printf("| Text = %.2f ºC, Tint. = %.2f%%  Tref = %.2f     |\n", (float)Temperature / 100, lm35, potentiometer);
    printf("| Uso Ventoinha: %.2d %% Uso Resistor: %.2d %%           |\n", ventoinha, resistor);
    printf("|                                                   |\n");
    printf("|---------------------------------------------------|\n");
    writeInLcd(potentiometer, lm35, (float)Temperature / 100);
    writeInCsv((float)Temperature / 100, (float)lm35, (float)potentiometer);
    pause();
  }
  return 0;
}
