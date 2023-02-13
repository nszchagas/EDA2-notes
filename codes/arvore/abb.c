#include <stdio.h>
#include <stdlib.h>

//--8<-- [start:header]
typedef struct No
{
    int chave;
    struct No *esq, *dir;
} No;

typedef No *p_no;

// Inicialização
p_no criar_arvore();
void destruir_arvore(p_no raiz);

p_no inserir(p_no raiz, int chave);
p_no remover(p_no raiz, int chave);
p_no buscar(p_no raiz, int chave);
p_no buscar_iterativo(p_no raiz, int chave);

p_no minimo(p_no raiz);
p_no maximo(p_no raiz);

p_no sucessor(p_no raiz);

p_no criar_arvore()
{
    p_no raiz = malloc(sizeof(No));
    return raiz;
}

// A destruição tem que ser feita
// das folhas para cima.
void destruir_arvore(p_no raiz)
{
    if (raiz != NULL)
    {
        if (raiz->esq != NULL)
            destruir_arvore(raiz->esq);
        if (raiz->dir != NULL)
            destruir_arvore(raiz->dir);
    }
    free(raiz);
}
//--8<-- [end:header]

//--8<-- [start:inserir]
p_no inserir(p_no raiz, int chave)
{

    if (raiz == NULL)
    {
        raiz = malloc(sizeof(No));
        raiz->chave = chave;
        raiz->esq = raiz->dir = NULL;
        return raiz;
    }
    if (chave < raiz->chave)
        raiz->esq = inserir(raiz->esq, chave);
    else
        raiz->dir = inserir(raiz->dir, chave);
    return raiz;
}

p_no remover_sucessor(p_no raiz)
{
    p_no min = raiz->dir;
    p_no pai = raiz;
    while (min->esq != NULL)
    {
        pai = min;
        min = min->esq;
    }
    if (pai->esq == min)
        pai->esq = min->dir;
    else
        pai->dir = min->dir;
    raiz->chave = min->chave;
}

p_no remover(p_no raiz, int chave)
{
    if (raiz != NULL)
    {
        if (chave < raiz->chave)
            raiz->esq = remover(raiz->esq, chave);
        else if (chave > raiz->chave)
            raiz->dir = remover(raiz->dir, chave);
        else if (raiz->esq == NULL)
            return raiz->dir;
        else if (raiz->dir == NULL)
            return raiz->esq;
        else
            remover_sucessor(raiz);
    }
    return raiz;
}
//--8<-- [end:inserir]

//--8<-- [start:buscar]
p_no buscar(p_no raiz, int chave)
{
    if (raiz != NULL)
    {
        if (raiz->chave == chave)
            return raiz;
        if (raiz->chave > chave)
            return buscar(raiz->esq, chave);
        else
            return buscar(raiz->dir, chave);
    }
    return NULL;
}

p_no buscar_iterativo(p_no raiz, int chave)
{
    while (raiz != NULL && chave != raiz->chave)
        if (chave < raiz->chave)
            raiz = raiz->esq;
        else
            raiz = raiz->dir;
    return raiz;
}
//--8<-- [end:buscar]

//--8<-- [start:minimo]
p_no minimo(p_no raiz)
{
    p_no minimo = raiz;
    while (minimo->esq != NULL)
        minimo = minimo->esq;
    return minimo;
}

p_no minimo_rec(p_no raiz)
{
    if (raiz == NULL || raiz->esq == NULL)
        return raiz;
    return minimo_rec(raiz->esq);
}
//--8<-- [end:minimo]

//--8<-- [start:maximo]
p_no maximo(p_no raiz)
{
    p_no maximo = raiz;
    while (maximo->dir != NULL)
        maximo = maximo->dir;
    return maximo;
}

p_no maximo_rec(p_no raiz)
{
    if (raiz == NULL || raiz->dir == NULL)
        return raiz;
    return maximo_rec(raiz->dir);
}
//--8<-- [end:maximo]

//--8<-- [start:sucessor]
// Retorna o próximo nó na ordenação.
p_no sucessor(p_no raiz)
{
    if (raiz != NULL && raiz->dir != NULL)
        return minimo(raiz->dir);
    return NULL;
}
//--8<-- [end:sucessor]

void print_arvore(p_no raiz)
{
    if (raiz != NULL)
    {
        printf("%d", raiz->chave);
        printf(" ---> (%d, %d)\n",
               (raiz->esq != NULL) ? raiz->esq->chave : -1,
               (raiz->dir != NULL) ? raiz->dir->chave : -1);
        print_arvore(raiz->esq);
        print_arvore(raiz->dir);
    }
}
void in_ordem(p_no raiz)
{
    if (raiz != NULL)
    {
        in_ordem(raiz->esq);
        printf("%d ", raiz->chave);
        in_ordem(raiz->dir);
    }
}
int main()
{
    p_no arvore = inserir(NULL, 5);
    inserir(arvore, 7);
    inserir(arvore, 3);
    inserir(arvore, 16);
    inserir(arvore, 9);

    for (int i = 0; i < 6; i++)
        inserir(arvore, 2 * i);

    print_arvore(arvore);

    printf("\nSubárvore com raiz no resultado do busca(arvore, 3): \n");
    print_arvore(buscar(arvore, 3));

    printf("\nSubárvore com raiz no resultado do minimo(arvore): \n");
    print_arvore(minimo(arvore));

    printf("\nSubárvore com raiz no resultado do maximo(arvore): \n");
    print_arvore(maximo(arvore));

    printf("\nSubárvore com raiz no resultado do sucessor(raiz->dir (7)): \n");
    print_arvore(sucessor(arvore->dir));

    printf("\nÁrvore após remover 7: \n");
    remover(arvore, 7);

    print_arvore(arvore);
}
