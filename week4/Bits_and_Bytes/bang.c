#include <stdio.h>

int bang(int x) {
    x = x | (~x + 1);
    return (x >> 31) + 1;
}

int main() {
    int x;

    printf("Enter an integer: ");
    scanf("%d", &x);

    printf("Result: %d\n",bang(x));

    return 0;
}

