# Implementação de Listas Encadeadas - C

Algoritmos de listas encadeadas em C.

## Estrutura de célula/nó

Nós armazenando um dado inteiro e um ponteiro para o próximo nó.

```c
#include <stdio.h> // Utilizada para operações de I/O
#include <stdlib.h> // Utilizada para manipular ponteiros

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;
```

## Impressão de uma Lista Encadeada

A lista pode ser impressa iterativamente, buscando o nó seguinte ao nó atual até o final da lista `p->prox == NULL` ou recursivamente, considerando que cada pedaço da lista encadeada é uma lista encadeada.

```c

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
    if (le->prox == NULL) // Caso base da recursão: 
    // quando a célula passada é o último item da lista.
    {
        printf("NULL\n");
        return;
    }
    else
        printf("%d -> ", le->prox->dado);
    imprime_rec(le->prox); 
}
```

## Busca na Lista Encadeada

O algoritmo que retorna o nó cujo dado é o valor buscado pode ser implementada iterativamente ou recursivamente.

```c
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
```

## Inserção na Lista Encadeada

Para inserir no início da lista encadeada, cria-se um novo nó, com o dado desejado, que apontará para o primeiro elemento da lista. Em seguida, a cabeça da lista `le` deve apontar para o novo nó criado.

```c
void insere_inicio(celula *le, int x)
{
    celula *novoNo;
    novoNo = malloc(sizeof(celula));
    novoNo->dado = x;
    novoNo->prox = le->prox;
    le->prox = novoNo;
}
```

Para inserir um elemento no nó anterior ao que contém um determinado valor, ou no final da lista caso não seja encontrado o valor, deve-se criar um novo nó, com o valor desejado, e fazer a busca pelo nó que contém o valor procurado. A busca pode ser feita mantendo-se o ponteiro do nó atual na posição anterior ao nó cujo dado está sendo avaliado, ao encontrar esse valor, faz-se o novo nó apontar para o próximo nó apontado pelo no atual e em seguida o nó atual (anterior ao valor procurado) apontar para o novo nó.

```c
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
```

## Remoção de elementos

Para remover o elemento seguinte ao nó passado como parâmetro, basta fazer o nó atual apontar para dois nós a frente e em seguida desalocar o nó deletado.

```c
int remove_depois(celula *p)
{
    if (p->prox != NULL)
    {
        celula *lixo;
        lixo = p->prox;
        p->prox = p->prox->prox;
        free(lixo); // Desaloca o nó deletado.
        return 1;
    }
    return 0;
}
```

Para remover um determinado nó cujo dado seja igual ao passado por parâmetro, faz-se a mescla da busca com a remoção.

```c
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
```

Algoritmo para remover todas as ocorrências de um dado em uma lista encadeada.

```c
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
```
