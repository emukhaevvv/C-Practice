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
void pop_front(struct LinkedList* list);
void push_back(struct LinkedList* list, int value);
void pop_back(struct LinkedList* list);

int size(struct LinkedList* list);
bool empty(struct LinkedList* list);

void main() {
    struct LinkedList* list = createLinkedList();

    printf("head: %d\n", list->head->val);
    printf("tail: %d\n", list->tail->val);
    printf("size: %d\n", size(list));
}

struct LinkedList* createLinkedList() {
    struct LinkedList* linkedList = (struct LinkedList*)malloc(sizeof(struct LinkedList*));
    linkedList->size = 0;
    linkedList->empty = true;

    return linkedList;
}

int size(struct LinkedList* list) {
    return list->size;
}

bool empty(struct LinkedList* list) {
    return list->empty;
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

void push_back(struct LinkedList* list, int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->val = value;
    node->next = NULL;

    if (list->empty == true) {
        list->head = node;
        list->tail = node;

        list->empty = false;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    list->size += 1;
}

void pop_front(struct LinkedList* list) {
    if (list->empty == true) return;

    if (list->head->next == NULL) {
        list->head = NULL;
        list->tail = NULL;
    
        list->empty = true;
    } else {
        struct Node* temp = list->head;
        list->head = list->head->next;

        temp->next = NULL;
        free(temp);
        temp = NULL;
    }

    list->size -= 1;
}

void pop_back(struct LinkedList* list) {
    if (list->empty == true) return;

    if (list->size == 1) {
        list->head = NULL;
        list->tail = NULL;

        list->empty = true;
    } else {
        struct Node* node = list->head;
        struct Node* prevNode = NULL;

        while (node->next != NULL) {
            prevNode = node;
            node = node->next;
        }

        prevNode->next = NULL;
        list->tail = prevNode;

        free(node);
        node = NULL;
    }

    list->size -= 1;
}