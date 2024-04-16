#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    int val;
    struct Node* next;
};

typedef struct {
    struct Node* head;
    struct Node* tail;
    int size;
    bool empty;
} LinkedList;

LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->size = 0;
    list->empty = true;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

int size(LinkedList* list) {
    return list->size;
}

void push_front(LinkedList* list, int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->val = value;
    node->next = NULL;

    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        struct Node* curNode = list->head;

        while (curNode->next)
        {
            curNode = curNode->next;
        }

        curNode->next = node;
    }

    list->size += 1;
    list->empty = false;
    list->tail = node;
}

void pop_front(LinkedList* list) {
    if (list->head == NULL) return;

    if (list->size == 1) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        struct Node* node = list->head;
        list->head = node->next;

        memset(node, 0, sizeof(*node));
        free(node);
    }
}

void main() {
   LinkedList* list = createList();
   push_front(list, 3);
   push_front(list, 4);
   push_front(list, 65);

   pop_front(list);
   pop_front(list);

   printf("%d", list->head->val);
}