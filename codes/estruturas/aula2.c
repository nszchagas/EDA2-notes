#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} no;

void insere(no *p, int valor)
{
    no *novo = malloc(sizeof(no));
    novo->dado = valor;
    novo->proximo = p->proximo;
    p->proximo = novo;
}

int removeNo(no *p)
{
    no *lixo = p->proximo;
    if (lixo != NULL)
    {
        p->proximo = lixo->proximo;
        lixo->dado;
        free(lixo);
        return 0;
    }
    return -1;
}

void imprime(no *le)
{
    no *p = le->proximo;
    while (p != NULL)
    {
        printf("%d ->", p->dado);
        p = p->proximo;
    }

    printf("NULL");
}

no *busca(int valor, no *le)
{
    no *p;
    p = le;
    while (p != NULL && p->dado != valor)
        p = p->proximo;
    return p;
}

int main()
{
    // Criação da lista:
    no *le = malloc(sizeof(no));
    le->proximo = NULL;

    imprime(le);
    // insere(le, 2);
    // insere(le->proximo, 4);
    // insere(le, 5);
    // imprime(le); // [5, 2, 4]
    // removeNo(le->proximo);
    // imprime(le);
    return 0;
}
