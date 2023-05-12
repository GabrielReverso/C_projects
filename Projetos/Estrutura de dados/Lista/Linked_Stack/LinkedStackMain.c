#include "LinkedStack.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    Stack *stack = stack_create(5);
    printf("\n");
    printf("\n");
    stack_push(stack, 1);
    printf("\n");
    stack_push(stack, 2);
    printf("\n");
    stack_push(stack, 3);
    printf("\n");
    stack_push(stack, 4);
    printf("\n");
    stack_push(stack, 5);
    printf("\n");
    stack_push(stack, 6);
    printf("\n");
    printf("\n");
    printf("Valor do topo: %d\n", stack_top(stack));
    printf("Valor da posicao 2: %d\n", stack_peek(stack, 2));
    printf("Valor da posicao -1: %d\n", stack_peek(stack, -1));
    printf("Valor da posicao 5: %d\n", stack_peek(stack, 5));
    printf("Item removido: %d\n", stack_pop(stack));
    printf("Item removido: %d\n", stack_pop(stack));
    printf("Item removido: %d\n", stack_pop(stack));
    printf("Item removido: %d\n", stack_pop(stack));
    printf("Item removido: %d\n", stack_pop(stack));
    printf("Valor do topo: %d\n", stack_top(stack));

    stack_free(stack);

    return 0;
}