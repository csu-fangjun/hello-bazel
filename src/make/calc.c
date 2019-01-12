#include <math.h>
#include <stdio.h>

int main() {
  int a = 3;
  // if we write sqrt(4) instead of sqrt(a + 1),
  // the compiler will optimise it to avoid linking -lm
  printf("sqrt(4) = %f\n", sqrt(a + 1));
  return 0;
}
