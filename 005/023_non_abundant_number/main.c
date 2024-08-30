#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// All numbers greater than 28123 are the sum of two abundant numbers
#define UPPER_BOUND 28123

int length = 0;

struct Node {
    struct Node *next;
    int number;
};

struct Node* insertNumber(struct Node *head, int number) {
    if(head == NULL) {
      //printf("Inserting %d into the list\n", number);
      head = malloc(sizeof(struct Node));
      head->number = number;
      //head->next = NULL;
      return head;
    }

  struct Node *current = head;

  while (current->next != NULL) {
      current = current->next;
  }

  //printf("Inserting %d into the list\n", number);
  current->next = malloc(sizeof(struct Node));
  current->next->number = number;
  //current->next->next = NULL;

  return head;
}

void printList(struct Node *head) {
  struct Node* current = head;
  int i = 0;
  while (current->next != NULL) {
      printf("Element %d, pointer %p: %d \n", i, current ,current->number);
      ++i;
      current = current->next;
  }
}

bool isAbundant(int number) {
    int sum = 0;

    for(int i = 1; i < number; i++) {
        if(number % i == 0) {
            sum += i;
        }
    }
    bool isAbundant = sum > number;

    return isAbundant;
}

struct Node* init(struct Node *head) {
    for(int i = 1; i <= UPPER_BOUND; i++) {
        //printf("%d\n", i);
        if(isAbundant(i)) {
            head = insertNumber(head, i);
        }
    }

    return head;
}

bool isSumOfTwoAbundant(int number, struct Node *head) {
    struct Node *current1 = head;
    struct Node *current2 = head;


    while (current1 != NULL){
        current2 = head;
        if(current1->number > number) {
            break;
        }
        while(current2 != NULL){
            if(current2->number > number) {
                 break;
             }


            if(current1->number + current2->number == number) {
                //printf("Sum of two abundant: %d (%d + %d)\n", number, current1->number, current2->number);
                return true;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }


    return false;
}

int sumNoSumOfTwoAbundant(struct Node *head) {
    int sum = 0;

    for(int i = 1; i <= UPPER_BOUND; i++) {
        if(!isSumOfTwoAbundant(i, head)) {
            //printf("No sum of two abundant two numbers: %d\n", i);
            sum += i;
        }
        if(i % 5000 == 0) {
          printf("%d numbers checked.\n", i);
        }
    }

    return sum;
}

int main(void) {
    struct Node *head = NULL;
    head = init(head);
    printf("Init done.\n");
    //printList(head);
    int result = sumNoSumOfTwoAbundant(head);
    printf("Sum: %d\n", result);
    return EXIT_SUCCESS;
}
