#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int dado;
    no *prox;
} no;

int linked_list_size(no *le)
{
    int size = 0;
    no *elem = le;
    while (elem->prox != NULL)
    {
        size++;
        elem = elem->prox;
    }
    return size;
}

int main()
{
    no *le = malloc(sizeof(no));
    no *no1 = malloc(sizeof(no));
    le->prox = no1;
    no1->dado = 5;
    no1->prox = NULL;

    printf("Size: %d", linked_list_size(le));

    return 0;
}