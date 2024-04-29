#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Stack {
    int* stack;
    int size;
    int max;
};

struct Stack* create_stack(int max) {
    struct Stack* stack = (struct Stack*)malloc(sizeof( struct Stack));

    stack->max = 4;
    stack->size = -1;

    stack->stack = (int*)malloc(4 * sizeof(int));

    return stack;
}

void push(struct Stack* stack, int val) {
    if (stack->max - 1 == stack->size) return;

    stack->size += 1;
    stack->stack[stack->size] = val;
}

int pop(struct Stack* stack) {
    if (stack->size == -1) return -1;

    int val = stack->stack[stack->size];
    stack->size -= 1;

    return val;
}

void main() {
    struct Stack* s = create_stack(4);
}