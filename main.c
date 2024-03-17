#include <stdio.h>
#include "vector.h"

int main()
{
    int i;

    Vector *v = vector_construct();

    printf("OK!\n");

    for (i = 0; i < 25; i++)
    {
        vector_push_back(v, i + 1);
    }

    for (i = 0; i < 25; i++)
    {
        printf("%d\n", v->data[i]);
    }

    vector_destroy(v);

    return 0;
}