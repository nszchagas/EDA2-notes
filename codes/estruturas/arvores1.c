#include <stdio.h>
#include <stdlib.h>

#define Item int

typedef struct no
{
    Item dado;
    struct no *esq, *dir;
} no;

// Criação da árvore será das folhas para a raiz, criando-se a árvore esquerda, árvore direita e a raiz delas.
// * Quando já sabemos todos os elementos da árvore.

no *criar_arvore(Item dado, no *esq, no *dir)
{
    no *raiz = malloc(sizeof(no));
    raiz->esq = esq;
    raiz->dir = dir;
    raiz->dado = dado;
    return raiz;
}

no *busca_elemento(no *raiz, Item valor)
{ // Escolhe um tipo de varredura e faz a busca.
    // Pré ordem: raiz, esquerda, direita
    if (raiz != NULL)
        if (raiz->dado == valor)
            return raiz;
        else
        {
            no *esq = busca_elemento(raiz->esq, valor);
            if (esq != NULL)
                return esq;
            else
                return busca_elemento(raiz->dir, valor);
        }
    return NULL;
}

int qtd_nos(no *raiz)
{
    if (raiz == NULL)
        return 0;
    // Acrescenta a raiz na contagem
    return qtd_nos(raiz->esq) + qtd_nos(raiz->dir) + 1;
}

int get_altura(no *raiz)
{
    if (raiz == NULL)
        return 0;
    int esq = get_altura(raiz->esq);
    int dir = get_altura(raiz->dir);
    return 1 + (esq >= dir) ? esq : dir;
}

void print_no(no *no)
{
    int esq, dir;
    if (no != NULL)
        printf("%d ", no->dado);
}

void print_arvore(no *raiz)
{
    if (raiz != NULL)
    {
        print_no(raiz);
        print_arvore(raiz->esq);
        print_arvore(raiz->dir);
    }
}

int main()
{
    no *n45;
    no *n33;
    no *n21, *n22, *n23, *n24;
    no *n11, *n12;
    no *raiz;

    n45 = criar_arvore(12, NULL, NULL);

    n33 = criar_arvore(1, n45, NULL);

    n21 = criar_arvore(-2, NULL, NULL);
    n22 = criar_arvore(10, n33, NULL);
    n23 = criar_arvore(7, NULL, NULL);
    n24 = criar_arvore(8, NULL, NULL);

    n11 = criar_arvore(3, n21, n22);
    n12 = criar_arvore(5, n23, n24);

    raiz = criar_arvore(2, n11, n12);

    print_arvore(raiz);

    no *busca = busca_elemento(raiz, -6);
    print_no(busca);

    printf("\nqtd nos: %d", qtd_nos(raiz));
    printf("\naltura: %d", get_altura(raiz));

    return 0;
}
