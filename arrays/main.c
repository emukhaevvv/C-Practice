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

void jugged_push(JAarray* jAarray, int value) {
  if (jAarray->len == jAarray->cap) {
    jugged_update(jAarray);
  }

  jAarray->array[jAarray->len] = value;
  jAarray->len += 1;
}

int main() {
  JAarray* array = jugged_array(4);

  for (int i = 0; i < 6; i++) {
    jugged_push(array, i);
  }

  for (int i = 0; i < 10; i++) {
    printf("%d\n", array->array[i]);
  }
 
  return 0;
}