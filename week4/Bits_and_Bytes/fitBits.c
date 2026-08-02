#include <stdio.h>

int fitBits(int x, int n) {

  int shift = 32 + (~n + 1);

  return !(((x << shift) >> shift) ^ x);
}

int main() {
  int x, n;

  printf("Enter integer: ");
  scanf("%d", &x);

  printf("Enter no. of bits: ");
  scanf("%d", &n);

  printf("Result: %d\n", fitBits(x, n));

  return 0;
}
