#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//--8<-- [start:header]
typedef struct
{
    char nome[20];
    int chave;
} Item;

typedef struct
{
    Item *v;
    int n, tamanho;
} FP;
typedef FP *p_fp;

p_fp criar(int tam);
void inserir(p_fp fila, Item item);
Item extrair_maximo(p_fp fila);
int vazia(p_fp fila);
int cheia(p_fp fila);

void troca(Item *a, Item *b)
{
    Item t = *a;
    *a = *b;
    *b = t;
}
//--8<-- [end:header]

//--8<-- [start:criar]
p_fp criar(int tam)
{
    p_fp fila = malloc(sizeof(FP));
    fila->tamanho = tam;
    fila->v = malloc(sizeof(Item) * tam);
    fila->n = 0;
    return fila;
}
//--8<-- [end:criar]

//--8<-- [start:inserir]
void inserir(p_fp fila, Item item)
{
    fila->v[fila->n++] = item;
}
//--8<-- [end:inserir]

//--8<-- [start:extrairmaximo]
Item extrair_maximo(p_fp fila)
{

    int index = 0;
    for (int i = 0; i < fila->n; i++)
        if (fila->v[i].chave > fila->v[index].chave)

            index = i;

    troca(&fila->v[index], &fila->v[fila->n - 1]);
    fila->n--;
    return fila->v[fila->n];
}
//--8<-- [end:extrairmaximo]

//--8<-- [start:vazia]
int vazia(p_fp fila)
{
    return fila->n == 0;
}
//--8<-- [end:vazia]

//--8<-- [start:cheia]
int cheia(p_fp fila)
{
    return fila->tamanho - fila->n == 0;
}
//--8<-- [end:cheia]

void print_item(Item item)
{
    printf("[%d] %s\n", item.chave, item.nome);
}
void print_fila(p_fp fila)
{
    for (int i = 0; i < fila->n; i++)
        print_item(fila->v[i]);
}

int main()
{
    int tam = 4;
    Item *it1 = malloc(sizeof(Item));
    it1->chave = 10;
    strcpy(it1->nome, "primeiro");

    Item *it2 = malloc(sizeof(Item));
    it2->chave = 5;
    strcpy(it2->nome, "segundo");

    Item *it3 = malloc(sizeof(Item));
    it3->chave = -6;
    strcpy(it3->nome, "terceiro");

    p_fp fila = criar(tam);
    printf("Fila vazia? (%d) Tamanho: %d preenchido: %d\n",
           vazia(fila), fila->tamanho, fila->n);
    inserir(fila, *it1);
    inserir(fila, *it2);
    inserir(fila, *it3);
    it3->chave = 12;
    inserir(fila, *it3);

    printf("Fila cheia? (%d) Tamanho: %d preenchido: %d\n",
           cheia(fila), fila->tamanho, fila->n);
    printf("Fila vazia? (%d) Tamanho: %d preenchido: %d\n",
           vazia(fila), fila->tamanho, fila->n);

    print_fila(fila);
    Item max = extrair_maximo(fila);
    printf("Item máximo removido: ");
    print_item(max);
    printf("Fila cheia? (%d) Tamanho: %d preenchido: %d\n",
           cheia(fila), fila->tamanho, fila->n);
}