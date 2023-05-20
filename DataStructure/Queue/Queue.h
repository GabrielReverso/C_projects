#include <stdbool.h>

typedef struct queue Queue;

// Cria fila na memória heap com size especificado e retorna ponteiro
Queue *queue_create(int size);

// Libera toda memória heap ocupada pela fila
void queue_free(Queue *queue);

// adiciona novo item no final da fila
void queue_enqueue(Queue *queue, int value);

// retorna primeiro item, remove da fila e reorganiza a fila
int queue_dequeue(Queue *queue);

// retorna primeiro item
int queue_first(Queue *queue);

// retorna ultimo item
int queue_last(Queue *queue);

// retorna TRUE se fila está vazia e caso contrário FALSE
bool queue_is_empty(Queue *queue);

// retorna TRUE se fila está cheia e caso contrário FALSE
bool queue_is_full(Queue *queue);