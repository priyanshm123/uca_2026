#include <stdio.h>

int isPower2(int x) {
    int positive = !(x >> 31);
    int nonzero = !!x;
    int singleBit = !(x & (x + ~0));

    return positive & nonzero & singleBit;
}

int main() {
    int x;

    printf("Enter an integer: ");
    scanf("%d", &x);

    printf("Result:  %d\n",isPower2(x));

    return 0;
}

