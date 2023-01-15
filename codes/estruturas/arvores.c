#include <stdio.h>
#include <stdlib.h>

void erd(int *r)
{
    if (r != NULL)
    {
    }
}

int main()
{
    int size = 10;

    for (int i = 1; i < size; i++)
        scanf("%d %d %d", &nodes[i].key, &nodes[i].left_i, &nodes[i].right_i);

    for (int i = 1; i < size; i++)
    {

        printf("%d %d %d %d\n", i, nodes[i].key, nodes[i].left_i, nodes[i].right_i);
    }

    return 0;
}