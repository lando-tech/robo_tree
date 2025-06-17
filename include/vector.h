#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#ifndef VEC_TYPE
#error "You must define a VEC_TYPE before including vector.h"
#endif

#ifndef VEC_PREFIX
#error "You must define a VEC_PREFIX before including vector.h"
#endif

#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define FUNC(name) CAT(VEC_PREFIX, name)

typedef struct
{
    VEC_TYPE *data;
    size_t size;
    size_t capacity;
} FUNC(_t);

static inline void FUNC(_init)(FUNC(_t) *vec)
{
    vec->capacity = 10;
    vec->data = malloc(sizeof(VEC_TYPE) * vec->capacity);
    vec->size = 0;
}

static inline void FUNC(_push)(FUNC(_t) *vec, VEC_TYPE element)
{
    if ( vec->size == vec->capacity )
    {
        vec->capacity *= 2;
        VEC_TYPE *temp = realloc(vec->data, sizeof(VEC_TYPE) * vec->capacity);
        if (temp != NULL)
        {
            vec->data = temp;
            vec->data[vec->size] = element;
            // printf("Index: %zu\n", vec->size);
            vec->size++;
            // printf("Memory reallocated, and new item appended to vector.\n");
        }
        else
        {
            printf("Unable to reallocate memory!\n");
            return;
        }
    }
    else if ( vec->size < vec->capacity )
    {
        vec->data[vec->size] = element;
        // printf("Index: %zu\n", vec->size);
        vec->size++;
        // printf("No reallocation needed. Item appended to vector.\n");
    }
}

static inline void FUNC(_pop)(FUNC(_t) *vec)
{
    if ( vec->size == 0 )
    {
        printf("Vector has no elements to remove!\n");
        return;
    }
    vec->size--;

    if ( vec->size < vec->capacity / 4 && vec->capacity > 10 )
    {
        vec->capacity /= 2;
        VEC_TYPE *new_data = realloc(vec->data, sizeof(VEC_TYPE) * vec->capacity);

        if ( new_data )
        {
            vec->data = new_data;
        }
        else
        {
            printf("Failed to resize vector during removal!\n");
            return;
        }
    }
}

static inline VEC_TYPE FUNC(_get)(FUNC(_t) *vec, size_t index)
{
    if ( index > vec->size )
    {
        printf("Index out of bounds!\n");
        return -1;
    }
    return vec->data[index];
}

static inline void FUNC(_free)(FUNC(_t) *vec)
{
    free(vec->data);
}

#endif