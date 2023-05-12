#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

int main()
{
    List *list = list_create();

    list_add(list, 2);
    list_display(list);

    list_add(list, 4);
    list_display(list);

    list_add(list, 6);
    list_display(list);

    return 0;
}