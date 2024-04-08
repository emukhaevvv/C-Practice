#include "stdio.h"
#include "stdlib.h"

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

void jugged_unshift(JAarray* jAarray, int value) {
  check_jugged_full(jAarray);

  for (int i = jAarray->len; i >= 0; i--) {
    jAarray->array[i + 1] = jAarray->array[i];
  }

  jAarray->array[0] = value;
  jAarray->len += 1;
}

int main() {
  JAarray* array = jugged_array(4);

  for (int i = 0; i < 4; i++) {
    jugged_push(array, i);
  }

  jugged_unshift(array, 12);
  jugged_unshift(array, 23);
  jugged_unshift(array, 65);
  jugged_unshift(array, 22);

  for (int i = 0; i < 10; i++) {
    printf("%d\n", array->array[i]);
  }
 
  return 0;
}