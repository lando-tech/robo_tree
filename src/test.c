#include <stdio.h>
#include <stdbool.h>
#include "string_utils.h"

#define VEC_TYPE int
#define VEC_PREFIX int_vector
#include "vector.h"

void print_int_vec(int_vector_t* vec)
{
    printf("\n");
    printf("Vector Size    : %lu\n", vec->size);
    printf("Vector Capacity: %lu\n", vec->capacity);
    printf("[");

    for (int i = 0; i < vec->size; ++i)
    {
        if ( i == vec->size - 1 )
        {
            printf("%d", vec->data[i]);
        }
        else
        {
            printf("%d, ", vec->data[i]);
        }
    }
    printf("]\n");
}

void test_str_array()
{
    StringArray *string_arr = str_array_init(10);
    str_array_append(string_arr, "hello");
    str_array_append(string_arr, "world");
    str_array_append(string_arr, "people");

    str_array_print(string_arr);
    str_array_pop(string_arr);
    str_array_print(string_arr);
    
    str_array_free(string_arr);
}

void test_vector()
{
    int_vector_t int_vec;
    int_vector_init(&int_vec);
    int_vector_push(&int_vec, 10);
    int_vector_push(&int_vec, 5);
    int_vector_push(&int_vec, 1);

    print_int_vec(&int_vec);    
    int_vector_pop(&int_vec);
    print_int_vec(&int_vec);

    int_vector_free(&int_vec);
}

int main()
{
    test_str_array();
    test_vector();
    return 0;
}