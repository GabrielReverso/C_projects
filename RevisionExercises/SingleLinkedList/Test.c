#include "List.h"

int main()
{
    List* list = list_create();
    list_add_head(list, 1);
    list_add_head(list, 1);
    list_add_head(list, 1);
    list_add_tail(list, 2);
    list_display(list);
    list_free(list);
}