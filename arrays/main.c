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

int main() {
  JAarray* array = jugged_array(4);
  JAarray* arrayX = jugged_array(2);

  jugged_push(arrayX, 322);
  jugged_push(arrayX, 1337);

  for (int i = 0; i < 4; i++) {
    jugged_push(array, i);
  }

  jugged_unshift(array, 12);
  jugged_unshift(array, 23);
  jugged_unshift(array, 65);
  jugged_unshift(array, 22);
  jugged_pop(array);
  jugged_shift(array);
  
  jugged_concat(array, arrayX);

  for (int i = 0; i < array->len; i++) {
    printf("%d\n", array->array[i]);
  }
 
  return 0;
}