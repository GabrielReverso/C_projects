#include "List.h"

int main(){
    List *list = list_create();
    list_add(list, 1);
    list_add(list, 2);
    list_add(list, 3);
    list_add(list, 4);
    list_display(list);
    list_free(list);
    return 0;
}