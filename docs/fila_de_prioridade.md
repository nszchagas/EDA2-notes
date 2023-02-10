# Fila de Prioridade

Uma fila de prioridade é uma estrutura de dados com duas operações básicas:

- Inserir um novo elemento
- Remover o elemento com maior chave (prioridade)

> :material-information-outline: Pilhas e filas assemelham-se às filas de prioridade.

A implementação será armazenando elementos em um vetor.

## Implementação - Vetores

### Função troca

A troca de elementos será frequente, então para facilitar a leitura do código, foi implementada a função troca.

```c
void troca (int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
```

```c
typedef struct {
    char nome[20];
    int chave;
} Item;

typedef struct {
    Item *v;
    int n, tamanho;
} FP; // Fila de prioridades, que contém um vetor com tamanho=tamanho e n elementos preenchidos.

typedef FP * p_fp;

```

### Criação da fila prioridade

A criação da fila de prioridade consiste basicamente em alocar memória para as estruturas e definir o tamanho com e quantidade de valores preenchidos.

```c
p_fp criar_filaprioridade(int tam){
    p_fp fprio = malloc(sizeof(FP));
    fprio->v = malloc(tam * sizeof(Item));
    fprio->n=0;
    fprio->tamanho = tam;
    return fprio;
}
```

### Inserção

A inserção é simples e feita no final do vetor.

```c
void insere(p_fp fprio, Item item){
    fprio->v[fprio->n] = item;
    fprio->n++;
}
```

> :material-information-outline: A complexidade do algoritmo é $O(1)$.

### Remoção do máximo

O algoritmo percorre o vetor, guardando o índice do maior valor encontrado até o momento. No final, é feita a troca do último elemento do vetor `fprio->v[fprio->n-1]` com o maior valor encontrado `fprio->v[max]`. Então, o valor de `n` é decrementado, pois um item foi removido, e o valor removido é retornado.

```c
Item extrai_maximo(p_fp fprio){
    int j, max=0;
    for (j=1; j < fprio->n; j++)
        if (fprio->v[max].chave < fprio->v[j].chave)
            max = j;
    troca(&(fprio->v[max]), &(fprio->v[fprio->n-1]));
    fprio->n--;
    return fprio->v[fprio->n];
    
}
```

> :material-information-outline: A complexidade da extração do máximo é $O(n)$.

Os custos das operações inserção e extração são invertidas caso se deseje manter o vetor ordenado.

## Árvore Binária Completa

Uma árvore binária é dita completa se todos os níveis, exceto o último, estão cheios e os nós do último nível estão o mais à esquerda possível.

Uma árvore binária completa com n nós tem $\left \lceil log(n+1) \right \rceil = O(log n)$ níveis.

Podemos representar árvores binárias utilizando vetores.

https://www.ic.unicamp.br/~rafael/cursos/2s2018/mc202/slides/unidade21-fila-de-prioridade.pdf