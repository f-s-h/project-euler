#ifndef LIST_H
#define LIST_H

struct List {
    int length;
    struct Node *head;
};

struct Node {
    void* value;
    struct Node* next;
};

struct List* init();
void printList();
void insert();

#endif //LIST_H
