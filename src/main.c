#include <ls_cpy.h>
#include <stdio.h>

#define VEC_TYPE int
#define VEC_PREFIX int_vector
#include "vector.h"

void print_int_vec(int_vector_t *vec) {
  printf("\n");
  printf("Vector Size    : %lu\n", vec->size);
  printf("Vector Capacity: %lu\n", vec->capacity);
  printf("[");

  for (int i = 0; i < vec->size; ++i) {
    if (i == vec->size - 1) {
      printf("%d", vec->data[i]);
    } else {
      printf("%d, ", vec->data[i]);
    }
  }
  printf("]\n");
}

int main() {
  const char *dir_path = {"/home/landotech"};
  read_directory_entries(dir_path);
  return 0;
}
