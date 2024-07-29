#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

// Initializes list with values from 2 to max_val
node_t* init(int max_val) {
    node_t *head = malloc(sizeof (node_t));
    node_t *current = head;
    for(int i = 2; i <= max_val; ++i) {
        node_t *next = malloc(sizeof (node_t));
        current->val = i;
        current->next = next;
        current = next;
    }
    return head;
}

void print_nodes(node_t* head) {
    node_t* current = head;

    int i = 0;
    while (current != NULL) {
        printf("Value at node_t(%d): %d\n", i, current->val);
        ++i;
        current = current->next;
    }
}

// Deletes first occurrence of val
node_t* remove_val(int val, node_t *head) {
    node_t *previous = NULL;
    node_t *current = head;

    // Head needs to be removed
    if(current->val == val) {
        head = head->next;
        return head;
    }
    else {
        previous = current;
        current = current->next;
    }

    while(current->next != NULL) {
        if(current->val == val) {
            previous->next = current->next;
            return head;
        }
        else {
            previous = current;
            current = current->next;
        }
    }

    // If tail needs to be removed
    if(current->val == val) {
        previous->next = NULL;
        return head;
    }

    return head;
}

node_t* reduce(node_t* head) {
    remove_val(0, head);

    node_t* current = head;
    while (current != NULL) {
        for(int i = 2; i < current->val; ++i) {
            for(int j = 2; j < current->val; ++j) {
                if(i != j && i * j == current->val) {
                    printf("IS MULTIPLE!");
                    printf("cur: %d, i: %d, j:%d \n", current->val, i, j);
                    head = remove_val(i, head);
                    head = remove_val(j, head);
                }
            }
        }
        current = current->next;
    }

    return head;
}

int multiply_nodes(node_t* head) {
    int result = 1;
    node_t* current = head;

    while(current != NULL) {
        result *= current->val;
        current = current->next;
    }

    return result;
}

// Calculates the smallest possible number that can be divided by each of the numbers from 1 to n.
int smallest_multiple(int n) {
    node_t* head = init(n);
    print_nodes(head);
    head = reduce(head);
    print_nodes(head);
    int result = multiply_nodes(head);
    return result;
}

int main(void) {
    int n = 10;
    int result = smallest_multiple(n);
    printf("Smallest multiple from 1 to %d: %d\n", n, result);
    return EXIT_SUCCESS;
}
