#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main()
{
    List *list = list_create();
    list_add(list, 1);
    list_add(list, 2);
    list_display(list);
    list_insert(list, 0, 10);
    list_insert(list, 0, 10);
    list_insert(list, 0, 10);
    list_insert(list, 0, 10);
    list_display(list);
    list_free(list);
    return 0;
}