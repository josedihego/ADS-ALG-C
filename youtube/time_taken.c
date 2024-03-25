#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  clock_t p1 = clock();

  double something;
  for (double i = 0; i < 1000; i = i + 1) {
    something = something + pow(i, i);
  }

  clock_t p2 = clock();
  double time_consumed = ((double)p2 - p1) / CLOCKS_PER_SEC;
  printf("Time consumed between points p1 and p2 is: %f seconds\n",
         time_consumed);
}