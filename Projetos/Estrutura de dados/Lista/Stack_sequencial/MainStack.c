#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(){

    Stack* stack = stack_create(5);
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);
    stack_push(stack, 4);
    stack_push(stack, 5);
    stack_push(stack, 6);
    printf("Valor do topo: %d\n", stack_top(stack));
    printf("Valor da posição 2: %d\n", stack_peek(stack, 2));
    printf("Valor da posição -1: %d\n", stack_peek(stack, -1));
    printf("Valor da posição 5: %d\n", stack_peek(stack, 5));
    printf("Item removido: %d\n", stack_pop(stack));
    printf("Item removido: %d\n", stack_pop(stack));
    printf("Item removido: %d\n", stack_pop(stack));
    printf("Item removido: %d\n", stack_pop(stack));
    printf("Item removido: %d\n", stack_pop(stack));
    printf("Valor do topo: %d\n", stack_top(stack));

    stack_free(stack);

    return 0;
}