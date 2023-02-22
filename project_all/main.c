#include <stdio.h>
#include <stdlib.h>

const double pi;

double calculaVolumeEsfera(double raio)
{
     double x = 4.0/3;
     return x * pi * pow(raio,3);
}

double calculaVolumeCilindro(double raio)
{
     return 1.5 * (4/3.0) * pi * pow(raio,3);
}


int main(int argc, char *argv[])
{
  double vol = calculaVolumeEsfera(5.3);
  printf("Volume= %lf",vol);
  system("PAUSE");	
  return 0;
}
