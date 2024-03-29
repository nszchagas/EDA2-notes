#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le)
{
    celula *noImpresso;
    noImpresso = le;
    while (noImpresso->prox != NULL)
    {
        printf("%d -> ", noImpresso->prox->dado);
        noImpresso = noImpresso->prox;
    }
    printf("NULL\n");
}

void imprime_rec(celula *le)
{
    if (le->prox == NULL)
    {
        printf("NULL\n");
        return;
    }
    else
    {
        printf("%d -> ", le->prox->dado);
    }
    imprime_rec(le->prox);
}

celula *busca(celula *le, int x)
{
    celula *noAtual = le;
    while (noAtual->prox != NULL)
    {
        if (noAtual->prox->dado == x)
            return noAtual->prox;
        noAtual = noAtual->prox;
    }
    return NULL;
}

celula *busca_rec(celula *le, int x)
{
    if (le->prox == NULL)
        return NULL;
    else if (le->prox->dado == x)
        return le->prox;
    else
        return busca_rec(le->prox, x);
}

void insere_inicio(celula *le, int x)
{
    celula *novoNo;
    novoNo = malloc(sizeof(celula));
    novoNo->dado = x;
    novoNo->prox = le->prox;
    le->prox = novoNo;
}

void insere_antes(celula *le, int x, int y)
{
    celula *noAtual = le;
    celula *novoNo = malloc(sizeof(celula));
    novoNo->dado = x;
    while (noAtual->prox != NULL && noAtual->prox->dado != y)
        noAtual = noAtual->prox;

    novoNo->prox = noAtual->prox;
    noAtual->prox = novoNo;
}

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

void remove_todos_elementos_2(celula *le, int x)
{
    celula *elem = le;
    while (elem->prox != NULL)
    {
        celula *lixo = elem->prox;
        if (elem->prox != NULL)
        {
            if (lixo->dado == x)
            {
                elem->prox = lixo->prox;
                free(lixo);
            }
            elem = elem->prox;
        }
    }
}

int main()
{
    celula *le;
    le = malloc(sizeof(celula));
    insere_inicio(le, 5);
    insere_inicio(le, 1);
    insere_inicio(le, 1);

    imprime(le);
    remove_todos_elementos_2(le, 5);
    imprime(le);

    return 0;
}
