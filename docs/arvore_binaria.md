# Árvore Binária de Busca

## Definição

É uma árvore tal que cada nó $r$ com subárvores esquerda $T_e$ e direita $T_d$ satisfaz:

- $e<r, \forall e \in T_e$

- $d>r, \forall d \in T_d$

![](assets/arvore_binaria_16_23_41.png)
<div style="text-align: center">
<p>
Figura 1: Exemplo de árvore binária de busca. Fonte: [1]
</p>
</div>

```c
typedef struct No {
    int chave;
    struct No *esq, *dir, *pai;
} No;

typedef No *p_no;

```

## Busca

A ideia é semelhante à busca binária, ou o valor procurado está na raiz da árvore, ou é menor, ou é maior. Se for menor, estará na subárvore da esquerda, se for maior, na da direita.

### Algoritmo recursivo

```c
p_no buscar(p_no raiz, int chave){
    if (raiz == NULL || chave == raiz->chave)
        return raiz;
    if (chave < raiz->chave)
        return buscar(raiz->esq, chave);
    else
        return buscar(raiz->dir, chave);
}
```

### Algoritmo iterativo

```c
p_no buscar_iterativo(p_no raiz , int chave) {
    while (raiz != NULL && chave != raiz ->chave)
    if (chave < raiz ->chave)
        raiz = raiz ->esq;
    else
        raiz = raiz ->dir;
    return raiz;
}
```

A complexidade da busca, se a árvore estiver balanceada, a complexidade é $O(log n)$, e no pior caso a árvore assemelha-se à uma lista encadeada, o que faz a busca ter complexidade $O(n)$. Isso ocorre quando os dados estão ordenados, então um novo nó sempre será inserido do mesmo lado, esquerdo, caso decrescente, direito, quando crescente.

> No caso médio, a árvore tende a ser balanceada, já que cada elemento inserido tem 50% de chance de estar à esquerda ou à direita da raiz.

## Inserção

Antes de fazer a inserção, devemos determinar onde inserir o valor, fazendo uma busca por ele. Então, inserimos ele na posição ele deveria estar.

O algoritmo insere na árvore recursivamente e devolve um ponteiro para a raiz da nova árvore.

```c
p_no inserir (p_no raiz, int chave){
    p_no novo;
    if (raiz == NULL) {
        novo = malloc(sizeof(No));
        novo->esq = novo -> dir = NULL;
        novo->chave=chave;
        return novo;
    }
    if (chave < raiz->chave)
        raiz->esq = inserir(raiz->esq, chave);
    else 
        raiz->dir = inserir(raiz->dir, chave);
    return raiz;
}
```

## Mínimo

Basta andar a árvore sempre à esquerda, até encontrar um nó que não tenha filhos a esquerda.

### Algoritmo Recursivo

```c
p_no minimo(p_no raiz){
    if (raiz == NULL || raiz->esq == NULL)
        return raiz;
    return minimo(raiz->esq);
}

```

### Algoritmo Iterativo

```c
p_no minimo_iterativo(p_no raiz) {
    while (raiz != NULL && raiz ->esq != NULL)
        raiz = raiz ->esq;
    return raiz;
}
```

> O algoritmo para achar o máximo é simétrico.


https://www.ic.unicamp.br/~rafael/cursos/2s2018/mc202/slides/unidade18-arvore-de-busca.pdf