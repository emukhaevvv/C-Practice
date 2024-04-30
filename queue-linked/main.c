#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    int val;
    struct Node* next;
};

struct LinkedListQueue {
    struct Node* head;
    struct Node* tail;
    struct Node* first;
    int size;
    int max;
    int point;
    int headIndex;
};

struct LinkedListQueue* createList(int size) {
    struct LinkedListQueue* list = (struct LinkedListQueue*)malloc(sizeof(struct LinkedListQueue));

    list->max = size;
    list->size = -1;
    list->point = -1;
    list->headIndex = 0;

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = 0;
    node->next = NULL;

    list->head = node;
    list->first = node;
    list->tail = list->head;

    int i = 1;
    struct Node* current = list->head;

    while (i < list->max) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));

        node->val = 0;
        node->next = NULL;

        current->next = node;
        current = node;

        i++;
    }

    return list;
}

int is_empty(struct LinkedListQueue* q) {
    if (q->size == -1) return 1;
    return 0;
}

int is_full(struct LinkedListQueue* q) {
    if (q->point == q->max - 1) return 1;
    return 0;
}

void enqueue(struct LinkedListQueue* q, int value) {
    if (is_full(q)) {
        q->point = 0;
        q->tail = q->first;
        q->tail->val = value;
        q->tail = q->tail->next;
    } else {
        q->tail->val = value;
        q->tail = q->tail->next;
        q->point += 1;
        q->size += 1;
    }
}

void dequeue(struct LinkedListQueue* q) {
    if (is_empty(q)) return;

    q->head->val = 0;

    if (q->headIndex == q->max - 1) {
        q->head = q->first;
    } else {
        q->head = q->head->next;
        q->headIndex += 1;
    } 

    q->size -= 1;
}

void main() {
   struct LinkedListQueue* list = createList(4);
}