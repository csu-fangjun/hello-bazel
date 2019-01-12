#include <stdio.h>

int main() {
  printf("2 + 2 is %f\n", 4);
  /*warning: format specifies type 'double' but the argument has type 'int'
   * [-Wformat]*/
  return 0;
}
