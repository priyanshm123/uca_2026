#include <stdio.h>

int sign(int x) {
  int sign_bit = x >> 31;

  return sign_bit | !!x;
}

int main() {
  int x;

  printf("Enter the Integer: ");
  scanf("%d", &x);

  printf("Result: %d\n", sign(x));
}
