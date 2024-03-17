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