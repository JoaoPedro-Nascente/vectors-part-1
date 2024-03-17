#include "vector.h"

#include <stdio.h>
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

int vector_size(Vector *v)
{
    return v->size;
}

data_type vector_get(Vector *v, int i)
{
    if (i <= v->size && i >= 0)
    {
        return v->data[i];
    }
    else
    {
        printf("ERRO: INDICE INVALIDO!\n");
        exit(0);
    }
}

void vector_set(Vector *v, int i, data_type val)
{
    vector_get(v, i);

    v->data[i] = val;
}
int vector_find(Vector *v, data_type val)
{
    int i;

    for (i = 0; i < v->size; i++)
    {
        if (v->data[i] == val)
            return i;
    }

    return -1;
}

data_type vector_max(Vector *v)
{
    return v->data[vector_argmax(v)];
}

data_type vector_min(Vector *v)
{
    return v->data[vector_argmin(v)];
}

int vector_argmax(Vector *v)
{
    int i;
    int max = v->data[0];
    int argmax = 0;

    for (i = 0; i < v->size; i++)
    {
        if (v->data[i] > max)
        {
            max = v->data[i];
            argmax = i;
        }
    }

    return argmax;
}

int vector_argmin(Vector *v)
{
    int i;
    int min = v->data[0];
    int argmin = 0;

    for (i = 0; i < v->size; i++)
    {
        if (v->data[i] < min)
        {
            min = v->data[i];
            argmin = i;
        }
    }

    return argmin;
}