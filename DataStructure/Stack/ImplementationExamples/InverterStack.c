#include "../Stack.h"
#include <stdio.h>
#include <stdlib.h>

#define size 5

int main()
{
    Stack *stack = stack_create(size);
    int num;

    for (int i = 0; i < size; i++)
    {
        printf("Digite os valores da stack: ");
        scanf("%d", &num);
        stack_push(stack, num);
        system("cls");
    }

    printf("[ ");
    for (int i = size - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%d", stack_peek(stack, i));
        }
        else
        {
            printf("%d, ", stack_peek(stack, i));
        }
    }
    printf(" ]\n");

    system("pause");
    stack_free(stack);
    return 0;
}