#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int main(int argc, char *argv[])
{
  Hash * h = malloc(sizeof(Hash));
  initHash(h);
  
  insertHash(h,30);
  insertHash(h,12);
  insertHash(h,1000);
  insertHash(h,0);
  insertHash(h,400);
  insertHash(h,11);
  
  insertHash(h,32);
  insertHash(h,90);
  insertHash(h,45);
  
  printHash(h);
  
  printf("%s","----------\n");
  
  removeHash(h, searchHash(h,400));
  printHash(h);
  
  printf("%s","----------\n");
  
  removeHash(h, searchHash(h,11));
  printHash(h);
  
  system("PAUSE");	
  return 0;
}
