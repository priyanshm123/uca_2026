#include <stdio.h>

long long sumEvenFibOptimized(long long n) {

    long long even1 = 2;
    long long even2 = 8;
    long long sum = 0;

    if (n >= 2)
        sum += even1;

    if (n >= 8)
        sum += even2;

    while (1) {

        long long next = 4 * even2 + even1;

        if (next > n)
            break;

        sum += next;

        even1 = even2;
        even2 = next;
    }

    return sum;
}


int main() {

    long long n;

    printf("Enter n: ");
    scanf("%lld", &n);

    printf("Sum of even Fibonacci numbers = %lld\n",
           sumEvenFibOptimized(n));

    return 0;
}


