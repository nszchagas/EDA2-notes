#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p)
{
    if (p->prox != NULL)
    {
        p->prox = p->prox->prox;
        return 1;
    }
    return 0;
}

void remove_elemento(celula *le, int x)
{
    celula *noAtual = le;
    while (noAtual->prox != NULL)
    {
        if (noAtual->prox->dado == x)
        {
            remove_depois(noAtual);
            return;
        }
        noAtual = noAtual->prox;
    }
}

void remove_todos_elementos(celula *le, int x)
{
    celula *noAtual = le->prox;
    celula *prev = le;
    while (noAtual != NULL)
    {
        if (noAtual->dado == x)
        {
            prev->prox = noAtual->prox;
            noAtual = prev->prox;
        }
        else
        {
            prev = noAtual;
            noAtual = noAtual->prox;
        }
    }
}