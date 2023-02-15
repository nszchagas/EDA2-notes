---
title: EDA2 - Aula 2 - Listas Encadeadas
author: "Nicolas Chagas Souza"
date: 04/11/2022
geometry: left=2cm,right=2cm,top=1cm,bottom=2cm
output: pdf_document
---

## Notação O(n)

### Definição

> Dizemos que um algoritmo consome tempo $ O(f(n)) $, onde f é uma função e n é algo que caracteriza a entrada, significa dizer que o algoritmo consome, no máximo, $ c \cdot f (n)$ operações, para quaisquer $ n\geq n_0 $, onde $ c>0 $ e $ n_0 \geq 0$.

### Funções clássicas consideradas

- Quantidade constante de operações: $f(n) = 1 \rightarrow O(1)$
- Logarítmico: $f(n) = log\ n$
- Linear: $f(n) = n$
- Linearítmico / quase linear: $f(n) = n \cdot log\ n$
- Polinomial: $ f(n)=n^k,\ k\geq2 $
- Exponenciais:
  - $f(n)=k^n , k \geq 2$
  - $f(n)=n^n, n!$

Exemplo:

A função abaixo retorna o maior elemento do vetor v de tamanho n.

```c
int maior(int v[], int n){ // A passagem do vetor v também poderia ser feita como int *v. 

int maior = v[0];
for (int i = 0; i < n ; i++)
    if (v[i]>maior)
        maior = v[i];
return maior;
}
```

Para analisar a complexidade de um algoritmo fazemos a contagem de quantas operações o algoritmo faz em cada linha.

```c
int maior(int v[], int n){

int maior = v[0]; // Uma operação
for (int i = 0; i < n ; i++) // São feitas 2n-1 operações.
    if (v[i]>maior) // n-1 iterações do for.
        maior = v[i]; // Algo <= a n-1
return maior; 
}
```

Ao todo, o algoritmo tem complexidade: $O(n)$.

## Listas Encadeadas

São utilizadas para armazenar uma coleção de elementos. É uma alternativa aos vetores.

Comparativos entre listas e vetores

| Listas encadeadas | Vetores |
| - | - |
| Não precisa de espaço contíguo na memória | Requer um espaço contíguo na memória |
| Acesso: O(n) |  Acesso: O(1) |
| Inserção de novo elemento: O(1) | Inserção: O(n) |

> Trade off: O uso de listas encadeadas facilita a inserção de novos elementos, mas dificulta o acesso.

### Implementação de listas encadeadas

A lista será composta pelo encadeamento de nós (ou células), compostas por um dado e um apontador para o próximo nó. Todos os elementos devem ser do mesmo tipo.

![](/assets/listas_encadeadas_16_59_54.png)

```c
    typedef struct no {
        int dado;
        struct no *proximo;
    } no;
```

- Dado uma célula `no`, acessamos o valor do seu conteúdo com `no.dado`.
- Se `p` é o endereço de um nó, acessamos o conteúdo deste nó por `p->dado` e o endereço do próximo nó por `p->proximo`.  
- Se `p` é o endereço do último nó da lista, então `p->proximo==NULL`.
- Essa estrutura de dados também pode ser chamada de lista simplesmente encadeada.
- A principal variação da lista encadeada é a lista duplamente encadeada, em que cada nó há dois apontadores: para o nó anterior e para o nó seguinte.
- Na lista vazia o elemento head (cabeça) aponta para NULL ou aponta para si mesmo (lista circular).

#### Endereço de uma lista encadeada

O endereço de uma lista encadeada (le) é o endereço de seu primeiro nó.

- Observe que listas são entidades recursivas, se `le` é uma lista encadeada, então `le->prox` também é.

```c
    int main(){
    // Criação da lista:
    no *le = malloc(sizeof(no)); 
    le->proximo = NULL; // Ou le->proximo = le; (lista circular)
    }
```

#### Inserção em uma lista encadeada

1. Alocar o novo nó.
2. O novo nó deve apontar para o sucessor.
3. O antecessor do novo nó deve apontar para ele.

```c
void insere(no *p, int valor)
{
    no *novo = malloc(sizeof(no));
    novo->dado = valor;
    novo->proximo = p->proximo;
    p->proximo = novo;
}
```

### Remoção em uma lista encadeada

Apontamos para o nó anterior ao elemento que será removido e retorna o valor que foi removido.

```c
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

```

#### Imprimindo uma lista usando recursão

```c
void printList(no *le)
{
    no *p;
    printf("[ ");
    for (p = le->proximo; p != NULL; p = p->proximo)
        printf("%d ", p->dado);
    printf("]\n");
}
```

### Referência

[1] Material sobre Listas Encadeadas, do Professor Paulo Feofiloff, disponível no [link](https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html).
