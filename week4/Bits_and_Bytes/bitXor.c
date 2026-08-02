#include <stdio.h>

int bitXor(int x, int y) {
  int a = ~(~x & y);
  int b = ~(x & ~y);

  return ~(a & b);
}

int main() {
  int x, y;

  printf("Enter value of x:");
  scanf("%d",&x);

  printf("Enter value of y:");
  scanf("%d", &y);

  printf("Result: %d\n", bitXor(x, y));

  return 0;
}
