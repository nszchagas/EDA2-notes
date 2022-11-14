#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le)
{
    celula *p = le->proximo;
    while (p != NULL)
    {
        printf("%d ->", p->dado);
        p = p->proximo;
    }

    printf("NULL");
}

void imprime_rec(celula *le)
{
}

void insere(no *p, int valor)
{
    celula *novo = malloc(sizeof(celula));
    novo->dado = valor;
    novo->proximo = p->proximo;
    p->proximo = novo;
}

int main()
{
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;

    imprime(le);

    return 0;
}