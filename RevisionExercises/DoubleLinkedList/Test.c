#include "List.h"
#include <stdio.h>

int main()
{
    List *list = list_create();
    list_insert_tail(list, 1);
    list_display(list);
    list_insert_tail(list, 2);
    list_display(list);
    list_insert_head(list, 3);
    list_display(list);
    list_insert_head(list, 4);
    list_display(list);

    list_remove_head(list);
    list_display(list);

    list_remove_head(list);
    list_display(list);

    list_remove_head(list);
    list_display(list);

    list_remove_head(list);
    list_display(list);


    list_free(list);

    return 0;
}