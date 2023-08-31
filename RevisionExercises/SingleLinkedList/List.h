
typedef struct list List;

List* list_create();
void list_add_head(List* list, int value);
void list_add_tail(List* list, int value);
void list_free(List* list);
void list_display(List* list);


