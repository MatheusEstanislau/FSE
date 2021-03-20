#include <stdio.h>

void initWrite()
{
  FILE *f = fopen("project1.csv", "w");
  fprintf(f, "Text,Tint,Tref\n");
  fclose(f);
}

void writeInCsv(float text, float tint, float tref)
{
  FILE *f = fopen("project1.csv", "a");
  fprintf(f, "%f,%f,%f\n", text, tint, tref);
  fclose(f);
}