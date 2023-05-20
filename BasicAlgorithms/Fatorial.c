#include <stdio.h>
#include <stdlib.h>

#define fatorial 5

int calculaFatorial(int);

int main()
{
    printf("Fatorial de %i e: %i", fatorial, calculaFatorial(fatorial));
    return 0;
}

int calculaFatorial(int x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return x * calculaFatorial(x - 1);
    }
}