#include <stdio.h>
#include <time.h>

void initWrite()
{
  FILE *f = fopen("project1.csv", "w");
  fprintf(f, "Text,Tint,Tref,Cooler,Resistor,Data,Hora\n");
  fclose(f);
}

void writeInCsv(float text, float tint, float tref, float cooler, float resistor)
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  FILE *f = fopen("project1.csv", "a");
  fprintf(f, "%f,%f,%f,%f,%f,%d/%d/%d, %.2d:%.2d:%.2d\n", text, tint, tref, cooler, resistor, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  fclose(f);
}