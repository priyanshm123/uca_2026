#include <stdio.h>

long long sumEvenFibBrute(long long n) {
    long long a = 1;
    long long b = 1;
    long long sum = 0;

    while (b <= n) {
        if (b % 2 == 0) {
            sum += b;
        }

        long long next = a + b;
        a = b;
        b = next;
    }

    return sum;
}

int main() {
    long long n;

    printf("Enter n: ");
    scanf("%lld", &n);

    printf("Sum of even Fibonacci numbers = %lld\n", sumEvenFibBrute(n));

    return 0;
}

