#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
int main()
{
    int *x;
    x = (int *)malloc(sizeof(int));
    *x = 10;
    printf("Minha variavel e: %i", *x);
    return 0;
}
*/

int main()
{
    setlocale(LC_ALL, "portuguese");
    int a = 1;
    int *b = &a; // ponteiro B aponta para o endereço de A

    a = 40;

    printf("Minha variável é: %i", *b);
    return 0;
}