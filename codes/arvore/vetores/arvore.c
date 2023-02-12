#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *dado;
    int tam;
} tree;

#define esq_i(n) (2 * n + 1);
#define dir_i(n) (2 * n + 2);

void print_arvore(tree raiz)
{
}

//--8<-- [start:criar]
void insere_folha(int dado, p_no esq, p_no dir)
{
}
//--8<-- [end:criar]

// --8<-- [start:procurar]
int procurar_no(p_no raiz, int valor)
{
}
// --8<-- [end:procurar]

// --8<-- [start:numero]
int numero_nos(p_no raiz)
{
}
// --8<-- [end:numero]

// --8<-- [start:altura]
int altura(p_no raiz)
{
}
// --8<-- [end:altura]

int main()
{
    

    n34 = criar_arvore(17, NULL, NULL);
    n38 = criar_arvore(10, NULL, NULL);

    n21 = criar_arvore(2, NULL, NULL);
    n22 = criar_arvore(5, NULL, n34);
    n24 = criar_arvore(8, NULL, n38);

    n11 = criar_arvore(5, n21, n22);
    n12 = criar_arvore(7, NULL, n24);

    raiz = criar_arvore(6, n11, n12);

    p_no busca = procurar_no(raiz, 7);

    printf("----- Árvore inserida ----- \n\nEstrutura: nó (esq, dir)\n\n");

    print_arvore(raiz);
    printf("\n\n---------  SPECS  ---------\n\nAltura: %d\nQuantidade de nós:%d\n\n", altura(raiz), numero_nos(raiz));
    printf("---------------------------");
    return 0;
}
