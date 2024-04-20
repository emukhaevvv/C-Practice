#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    int val;
    struct Node* next;
};

struct LinkedList {
    int size;
    bool empty;
    struct Node* head;
    struct Node* tail;
};

struct LinkedList* createLinkedList();
void push_front(struct LinkedList* list, int value);

void main() {
    struct LinkedList* list = createLinkedList();
}

struct LinkedList* createLinkedList() {
    struct LinkedList* linkedList = (struct LinkedList*)malloc(sizeof(struct LinkedList*));
    linkedList->size = 0;
    linkedList->empty = true;

    push_front(linkedList, 54);
    push_front(linkedList, 12);

    return linkedList;
}

void push_front(struct LinkedList* list, int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->val = value;
    node->next = NULL;

    if (list->size == 0) {
        list->head = node;
        list->tail = node;

        list->empty = false;
    } else {
        node->next = list->head;
        list->head = node;  
    }

    list->size += 1;
}