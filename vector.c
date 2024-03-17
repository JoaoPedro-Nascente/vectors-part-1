#include "vector.h"

#include <stdlib.h>

Vector *vector_construct()
{
    Vector *v = (Vector *)calloc(1, sizeof(Vector));

    v->allocated = 10;
    v->size = 0;
    v->data = (data_type *)calloc(v->allocated, sizeof(data_type));

    return v;
}

void vector_destroy(Vector *v)
{
    free(v->data);
    free(v);
}

void vector_push_back(Vector *v, data_type val)
{
    if (v->size >= v->allocated)
    {
        v->data = (data_type *)realloc(v->data, v->allocated * 2 * (sizeof(data_type)));
        v->allocated *= 2;
    }

    v->data[v->size] = val;
    v->size++;
}