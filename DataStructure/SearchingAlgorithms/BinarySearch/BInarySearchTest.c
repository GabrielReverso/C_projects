#include "List.h"
#include <stdio.h>

int main()
{
    List *list = list_create();
    list_add(list, 1);
    list_add(list, 2);
    list_add(list, 3);
    list_add(list, 4);
    list_add(list, 5);
    list_display(list);

    printf("Index: %d\n", list_binary_search(list, 2));
    printf("Index: %d\n", list_binary_search(list, 4));
    printf("Index: %d\n", list_binary_search(list, 1));
    printf("Index: %d\n", list_binary_search(list, 6));

    list_free(list);

    return 0;
}