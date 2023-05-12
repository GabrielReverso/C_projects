#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main()
{
    Queue* queue = queue_create(5);
    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 3);
    queue_enqueue(queue, 4);
    queue_enqueue(queue, 5);
    queue_enqueue(queue, 6);
    printf("Valor do topo: %d\n", queue_last(queue));
    printf("Valor do comneço: %d\n", queue_first(queue));
    printf("Valor removido: %d\n", queue_dequeue(queue));
    printf("Valor do topo: %d\n", queue_last(queue));
    printf("Valor do comneço: %d\n", queue_first(queue));
    printf("Valor removido: %d\n", queue_dequeue(queue));
    printf("Valor removido: %d\n", queue_dequeue(queue));
    printf("Valor removido: %d\n", queue_dequeue(queue));
    printf("Valor do topo: %d\n", queue_last(queue));
    printf("Valor do comneço: %d\n", queue_first(queue));
    printf("Valor removido: %d\n", queue_dequeue(queue));
    printf("Valor do topo: %d\n", queue_last(queue));
    printf("Valor do comneço: %d\n", queue_first(queue));
    printf("Valor removido: %d\n", queue_dequeue(queue));
    queue_free(queue);
}