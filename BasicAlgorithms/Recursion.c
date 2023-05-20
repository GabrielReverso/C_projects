#include <stdio.h>
#include <stdlib.h>

// void printUntilZero(int);
// void printUntilZero2(int);
void printUntilZero3(int);

int main()
{
    printUntilZero3(5);
    return 0;
}

/*
void printUntilZero(int x){
    if(x < 0) return;
    printf("%i\n", x);
    x--;
    printUntilZero(x);
}
*/

/*
void printUntilZero2(int x){
    if(x < 0) return;
    x--;
    printUntilZero2(x);
    printf("%i\n", x);
}
*/

void printUntilZero3(int x)
{
    if (x < 0)
        return;
    printUntilZero3(x - 1);
    printUntilZero3(x - 2);
    printf("%i\n", x);
}
