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
};

struct LinkedList* createLinkedList();

void main() {
    struct LinkedList* list = createLinkedList();

    printf("%d", list->size);
}

struct LinkedList* createLinkedList() {
    struct LinkedList* linkedList = (struct LinkedList*)malloc(sizeof(struct LinkedList*));
    linkedList->size = 0;
    linkedList->empty = true;

    return linkedList;
}