// how to make a function that return the sum of two values in C?
#include <stdio.h>

int SumOfDigits(long x)
{
    int sum;
    for (sum = 0; x; x /= 10)
        sum += x % 10;
    return sum;
}

int main(void)
{
    long x = 12345678;
    printf("Sum of Digits of %lu is %d\n", x, SumOfDigits(x));
    return 0;
}

// Success #stdin #stdout 0s 5420KB
// Sum of Digits of 12345678 is 36

// 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36

// Source: https://stackoverflow.com/questions/74186700
