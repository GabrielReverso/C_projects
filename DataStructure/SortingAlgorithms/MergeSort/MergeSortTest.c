#include "List.h"

int main()
{
    List *list = list_create();
    list_add(list, 20);
    list_add(list, 2);
    list_add(list, 29);
    list_add(list, 7);
    list_add(list, 9);
    list_add(list, 1);
    list_add(list, 6);

    list_display(list);

    list_merge_sort(list);

    list_display(list);

    list_free(list);

    return 0;
}