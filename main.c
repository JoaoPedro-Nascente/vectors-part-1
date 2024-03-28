#include <stdio.h>
#include "vector.h"

int main()
{
    int i, m, n;

    scanf("%d %d", &m, &n);

    Vector *v = vector_construct();

    printf("OK!\n");

    for (i = 0; i < 25; i++)
    {
        vector_push_back(v, i + 1);
    }

    for (i = 0; i < vector_size(v); i++)
    {
        printf("%d\n", vector_get(v, i));
    }

    for (i = 0; i < vector_size(v); i++)
    {
        vector_set(v, i, vector_get(v, i) * 2);
    }

    for (i = 0; i < vector_size(v); i++)
    {
        printf("%d\n", vector_get(v, i));
    }

    vector_destroy(v);

    return 0;
}