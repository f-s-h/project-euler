#include "list.h"

#include <stdlib.h>

struct List* list;

void insert(void* value) {
    if(list == NULL) {
      init();
    }
    
    struct Node* current = list->head;

    if(current == NULL) {
        current = malloc(sizeof(struct Node));
        current->value = value;
        list->length++;
        return;
    }

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(struct Node));
    current->next->value = value;
    list->length++;
}

struct List* init() {
    list = malloc(sizeof(struct List));

    return list;
}
