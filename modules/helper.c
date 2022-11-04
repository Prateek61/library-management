#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "helper.h"

date date_init(int year, int month, int day)
{
    date hmm = {year, month, day};
    return hmm;
}

/******************************************************************************************************************/

// Reallocates memory of integer vector
void int_vec_realloc(int_vec *vec);

int_vec int_vec_init()
{
    int_vec new_vec;
    new_vec.vec = NULL;
    new_vec.size = 0;
    new_vec.mem_size = 0;
    return new_vec;
}

void int_vec_push_back(int_vec *vec, int value)
{
    if (vec->size == vec->mem_size)
    {
        int_vec_realloc(vec);
    }

    vec->vec[vec->size] = value;
    vec->size += 1;
}

void int_vec_pop_back(int_vec *vec)
{
    vec->size -= 1;
}

void int_vec_insert(int_vec *vec, int index, int value)
{
    if (vec->size == vec->mem_size)
    {
        int_vec_realloc(vec);
    }

    for (int i = vec->size; i > index; i--)
    {
        vec->vec[i] = vec->vec[i - 1];
    }
    vec->vec[index] = value;
    vec->size += 1;
}

void int_vec_remove(int_vec *vec, int index)
{
    for (int i = index; i < vec->size - 1; i++)
    {
        vec->vec[i] = vec->vec[i + 1];
    }
    vec->size -= 1;
}

int int_vec_get(int_vec *vec, int index)
{
    return vec->vec[index];
}

void int_vec_set(int_vec *vec, int index, int value)
{
    vec->vec[index] = value;    
}

int int_vec_size(int_vec *vec)
{
    return vec->size;
}

int int_vec_find(int_vec *vec, int value)
{
    for (int i = 0; i < vec->size; i++)
    {
        if (int_vec_get(vec, i) == value)
        {
            return i;
        }
    }

    return -1;
}

void int_vec_print(int_vec *vec)
{
    for (int i = 0; i < int_vec_size(vec); i++)
    {
        printf("%d ", int_vec_get(vec, i));
    }
    printf("\n");
}

void int_vec_destroy(int_vec *vec)
{
    free(vec->vec);
    vec->vec = NULL;
    vec->size = 0;
    vec->mem_size = 0;
}

void int_vec_realloc(int_vec *vec)
{
    if (vec->mem_size == 0)
    {
        vec->vec = (int*)malloc(sizeof(int));
        vec->mem_size = 1;
    }
    else 
    {
        vec->vec = (int*)realloc(vec->vec, sizeof(int) * 2 * vec->mem_size);
        vec->mem_size = vec->mem_size * 2;
    }

    return;
}