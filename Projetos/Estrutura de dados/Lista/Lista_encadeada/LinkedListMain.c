#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    List *list = list_create();
    list_add(list, 3);
    list_add(list, 7);
    list_add(list, 9);
    list_display(list);
    printf("Get: %d\n", list_get(list, 0));
    printf("Get: %d\n", list_get(list, 1));
    printf("Get: %d\n", list_get(list, 2));
    printf("Get: %d\n", list_get(list, 3));
    list_set(list, 0, 200);
    list_set(list, 2, 200);
    list_display(list);
    list_insert(list, 0, 100);
    list_display(list);
    list_insert(list, 2, 100);
    list_display(list);
    list_insert(list, 5, 100);
    list_display(list);
    list_insert(list, 7, 100);
    list_display(list);
    printf("Removed: %d\n", list_remove(list, 0));
    printf("Removed: %d\n", list_remove(list, 1));
    printf("Removed: %d\n", list_remove(list, 7));
    list_display(list);
    list_free(list);

    return 0;
}