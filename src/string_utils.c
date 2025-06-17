#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_utils.h"

// TODO utilize INITIAL_CAPACITY constant from string_utils.h
StringArray *str_array_init(size_t capacity) {
  // Ensure capacity is set in case the caller passes in 0
  if (capacity == 0)
    capacity = 24; // Resizing is expensive, so a larger buffer is used
  StringArray *arr = malloc(sizeof(StringArray));
  if (arr == NULL) {
    printf("Failed to initialize StringArray!\n");
    return NULL;
  }

  arr->data = malloc(sizeof(char *) * capacity);
  if (arr->data == NULL) {
    printf("Failed to initialize StringArray!\n");
    return NULL;
  }
  // Array is empty, size = 0
  arr->size = 0;
  arr->capacity = capacity;
  return arr;
}

void str_array_append(StringArray *arr, char *element) {
  char *new_elem = strdup(element);
  // Size has reached capacity, resize the array
  if (arr->size == arr->capacity) {
    arr->capacity *= 2;
    char **temp = realloc(arr->data, sizeof(char *) * arr->capacity);
    if (temp != NULL) {
      arr->data = temp;
      arr->data[arr->size] = new_elem;
      arr->size++;
    } else {
      printf("Unable to reallocate memory!\n");
      free(new_elem);
      return;
    }
  } else if (arr->size < arr->capacity) {
    arr->data[arr->size] = new_elem;
    arr->size++;
  }
}

void str_array_pop(StringArray *arr) {
  if (arr->size == 0) {
    printf("Array has no elements to remove!\n");
    return;
  }
  free(arr->data[arr->size - 1]);
  arr->size--;

  if (arr->size < arr->capacity / 4 && arr->capacity > 5) {
    arr->capacity /= 2;
    char **new_data = realloc(arr->data, sizeof(char *) * arr->capacity);

    if (new_data)
      arr->data = new_data;
    else
      printf("Failed to resize String Array!\n");
    return;
  }
}

void str_array_print(StringArray *arr) {
  int i;
  printf("\n");
  printf("Array size    : %lu\n", arr->size);
  printf("Array capacity: %lu\n", arr->capacity);
  printf("[");
  for (i = 0; i < arr->size; ++i) {
    if (i == arr->size - 1) {
      printf("%s", arr->data[i]);
    } else {
      printf("%s, ", arr->data[i]);
    }
  }
  printf("]");
  printf("\n\n");
}

void str_array_free(StringArray *arr) {
  for (size_t i = 0; i < arr->size; ++i) {
    free(arr->data[i]);
  }
  free(arr->data);
  free(arr);
}

void strip(char *str, char dilim) {
  int length = strlen(str);
  int j = 0;
  for (int i = 0; i < length; ++i) {
    if (str[i] != dilim) {
      str[j++] = str[i];
    }
  }
  str[j] = '\0';
}

/*
 * Split the string with '\0'
 * and return the index position of the '\0'
 */
// TODO Implement complementary function to return a StringArray based on index
int in_place_split(char *str, char dilim) {
  int len = strlen(str);
  int i;
  for (i = 0; i < len; ++i) {
    if (str[i] == dilim) {
      str[i] = '\0';
      break;
    }
  }
  return i;
}

int get_token_index(const char *str, const char dilim) {
  int i;
  for (i = 0; i < strlen(str); ++i) {
    if (str[i] == dilim) {
      return i;
    }
  }
  return -1;
}