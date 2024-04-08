#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>

typedef struct {
  int len;
  int cap;
  int* array;
} JAarray;

JAarray* jugged_array(int capacity) {
  JAarray* jArray = (JAarray*)malloc(sizeof(JAarray));
  jArray->array = malloc(capacity * sizeof(*jArray->array));

  jArray->cap = capacity;
  jArray->len = 0;

  return jArray;
}

void jugged_update(JAarray* jAarray) {
  jAarray->cap = jAarray->cap * 2;

  int* updatedArray = (int*)malloc(jAarray->cap * sizeof(int*));

  for (int i = 0; i < jAarray->len; i++) {
    updatedArray[i] = jAarray->array[i];
  }

  free(jAarray->array);

  jAarray->array = updatedArray;
}

void check_jugged_full(JAarray* jAarray) {
  if (jAarray->len == jAarray->cap) {
    jugged_update(jAarray);
  }
} 

void jugged_push(JAarray* jAarray, int value) {
  check_jugged_full(jAarray);

  jAarray->array[jAarray->len] = value;
  jAarray->len += 1;
}

void jugged_pop(JAarray* jAarray) {
  if (jAarray->len == 0) return;

  jAarray->array[jAarray->len] = 0;
  jAarray->len -= 1;
}

void jugged_shift(JAarray* jAarray) {
  if (jAarray->len == 0) return;

  jAarray->len -= 1;

  for (int i = 0; i < jAarray->len; i++) {
    jAarray->array[i] = jAarray->array[i + 1];
  }
}

void jugged_unshift(JAarray* jAarray, int value) {
  check_jugged_full(jAarray);

  for (int i = jAarray->len; i >= 0; i--) {
    jAarray->array[i + 1] = jAarray->array[i];
  }

  jAarray->array[0] = value;
  jAarray->len += 1;
}

void jugged_concat(JAarray* jAarrayX, JAarray* jAarrayY) {
  for (int i = 0; i < jAarrayY->len; i++) {
    jugged_push(jAarrayX, jAarrayY->array[i]);
  }
}

bool jugged_every(JAarray* jAarray, bool func(int item, int index, JAarray* jAarray)) {
  if (jAarray->len == 0) return true;

  for (int i = 0; i < jAarray->len; i++) {
    int value = jAarray->array[i];
    if (!func(value, i, jAarray)) return false;
  }

  return true;
}

bool everyWithoutZero(int item, int index, JAarray* jAarray) {
  if (jAarray->array[0] == 0 || index > 15) return false;
}

int main() {
  JAarray* array = jugged_array(4);

  for (int i = 1; i < 15; i++) {
    jugged_push(array, i);
  }

  for (int i = 0; i < array->len; i++) {
    printf("%d\n", array->array[i]);
  }

  printf("%d", jugged_every(array, everyWithoutZero));

  return 0;
}