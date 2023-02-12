#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

typedef struct No
{
    int dado;
    struct No *esq, *dir;
} No;

typedef No *p_no;
typedef No *p_fila;

void print_arvore(p_no raiz)
{
    if (raiz != NULL)
    {
        printf("%d", raiz->dado);
        printf(" ---> (%d, %d)\n",
               (raiz->esq != NULL) ? raiz->esq->dado : -1,
               (raiz->dir != NULL) ? raiz->dir->dado : -1);
        print_arvore(raiz->esq);
        print_arvore(raiz->dir);
    }
}

//--8<-- [start:criar]
// Cria um nó na árvore, com dado e filhos esquerdo e direito.
p_no criar_arvore(int dado, p_no esq, p_no dir)
{
    p_no raiz = malloc(sizeof(p_no));
    raiz->dado = dado;
    raiz->esq = esq;
    raiz->dir = dir;
    return raiz;
}
//--8<-- [end:criar]

// --8<-- [start:procurar]
// Escolhe um tipo de varredura e faz a busca.
// Em ordem: esquerda, raiz, direita
p_no procurar_no(p_no raiz, int valor)
{
    p_no esq;
    if (raiz == NULL || raiz->dado == valor)
        return raiz;
    esq = procurar_no(raiz->esq, valor);
    if (esq != NULL)
        return esq;
    return procurar_no(raiz->dir, valor);
}
// --8<-- [end:procurar]

// --8<-- [start:numero]
// Faz a contagem do número de nós dos filhos e acrescenta a raiz.
int numero_nos(p_no raiz)
{
    if (raiz == NULL)
        return 0;
    return numero_nos(raiz->esq) + numero_nos(raiz->dir) + 1;
}
// --8<-- [end:numero]

// --8<-- [start:altura]
int altura(p_no raiz)
{
    int esq, dir;
    if (raiz == NULL)
        return 0;
    esq = altura(raiz->esq);
    dir = altura(raiz->dir);
    return 1 + (esq > dir ? esq : dir);
}
// --8<-- [end:altura]

// --8<-- [start:preordem]
// Pré ordem visita os nós na ordem: raiz, esquerda, direita.
void pre_ordem(p_no raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->dado);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}
// --8<-- [end:preordem]

// --8<-- [start:posordem]
// Pós ordem visita os nós na ordem: esquerda, direita, raiz.
void pos_ordem(p_no raiz)
{
    if (raiz != NULL)
    {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->dado);
    }
}
// --8<-- [end:posordem]

// --8<-- [start:inordem]
// Em ordem visita os nós na ordem: esquerda, raiz, direita.
void in_ordem(p_no raiz)
{
    if (raiz != NULL)
    {
        in_ordem(raiz->esq);
        printf("%d ", raiz->dado);
        in_ordem(raiz->dir);
    }
}
// --8<-- [end:inordem]

// @TODO: implementar filas para em_largura
// --8<-- [start:emlargura]
// Em largura visita os nós, por nível, da esquerda pra direita.
void em_largura(p_no raiz)
{
    p_fila f;
    f = criar_fila();
    enfileirar(f, raiz);
    while (!fila_vazia(f))
    {
        raiz = desenfileirar(f);
        if (raiz != NULL)
        {
            enfileirar(f, raiz->esq);
            enfileirar(f, raiz->dir);
            printf("%d ", raiz->dado); /*visita raiz*/
        }
    }
    destruir_fila(f);
}
// --8<-- [end:emlargura]

int main()
{
    p_no raiz;
    p_no n11, n12, n21, n22, n24, n34, n38;

    n34 = criar_arvore(17, NULL, NULL);
    n38 = criar_arvore(10, NULL, NULL);

    n21 = criar_arvore(2, NULL, NULL);
    n22 = criar_arvore(5, NULL, n34);
    n24 = criar_arvore(8, NULL, n38);

    n11 = criar_arvore(12, n21, n22);
    n12 = criar_arvore(7, NULL, n24);

    raiz = criar_arvore(6, n11, n12);

    p_no busca = procurar_no(raiz, 7);

    printf("----- Árvore inserida ----- \n\nEstrutura: nó (esq, dir)\n\n");

    print_arvore(raiz);

    printf("\n\n--------  Percursos  --------\n");
    printf("\nPré ordem: ");
    pre_ordem(raiz);
    printf("\nEm ordem: ");
    in_ordem(raiz);
    printf("\nPós ordem: ");
    pos_ordem(raiz);
    printf("\nEm largura: ");
    em_largura(raiz);

    printf("\n\n---------  SPECS  ---------\n\nAltura: %d\nQuantidade de nós:%d\n\n", altura(raiz), numero_nos(raiz));
    printf("---------------------------");
    return 0;
}
