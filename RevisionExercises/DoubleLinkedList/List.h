
typedef struct list List;

List* list_create();
void list_insert_head(List* list, int value);
void list_insert_tail(List* list, int value);
void list_remove_head(List* list);
void list_remove_tail(List* list);
void list_free(List* list);
void list_display(List* list);


