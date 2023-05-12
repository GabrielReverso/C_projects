#include <stdbool.h>

typedef struct stack Stack;


// Cria pilha na memória heap com size especificado e retorna ponteiro
Stack* stack_create(int size);

// Libera toda memória heap ocupada pela pilha
void stack_free(Stack* stack);

// adiciona novo item no fim da pilha
void stack_push(Stack* stack, int value);

// retorna ultimo item e o remove da pilha
int stack_pop(Stack* stack);

// retorna item de determinado index da pilha
int stack_peek(Stack* stack, int index);

// retorna ultimo item da pilha
int stack_top(Stack* stack);

// retorna TRUE se pilha está vazia e caso contrário FALSE
bool stack_is_empty(Stack* stack);

// retorna TRUE se pilha está cheia e caso contrário FALSE
bool stack_is_full(Stack* stack);