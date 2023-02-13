# Árvore Binária de Busca

## Motivação

As operações de inserção, remoção e busca em estruturas de dados costumam ter custos complementares, proveniente de um *tradeoff* na hora de implementação.

<center>

| Operação | Lista Duplamente Encadeada | Vetor Não Ordenado | Vetor Ordenado | Árvore Binária de Busca |
| :-: | :-: | :-: | :-: | :-: |
| Inserção e Remoção |  $O(1)$ | :material-sticker-alert-outline: $O(1)$  | $O(n)$ | $O(log\ n)$
| Busca | $O(n)$ | $O(n)$ |  $O(n\cdot log\ n)$ | $O(log\ n)$

<div style="text-align: center">
<p>
Tabela 1: Custo das Operações. Fonte: [1]
</p>
</div>
</center>

:material-sticker-alert-outline: A inserção e remoção em vetores não ordenados pode ter custo $O(1)$ ao inserir sempre no final e remover fazendo a troca com a última posição.

As Árvores Binárias de Busca, na sua versão mais sofisticada, oferecem operações de inserção, remoção e busca com custo $O(log\ n)$.

## Definição

Uma árvore binária tal que cada nó $r$ com subárvores esquerda $T_e$ e direita $T_d$ satisfaz:

- $e<r, \forall\ e \in T_e$

- $d>r, \forall\ d \in T_d$

é uma **árvore binária de busca**.

![](../assets/arvore_binaria_16_23_41.png)
<div style="text-align: center">
<p>
Figura 1: Exemplo de árvore binária de busca. Fonte: [1]
</p>
</div>

## Propriedades

Uma árvore binária de busca satisfaz a seguinte propriedade:

> A impressão dos elementos em um percurso em-ordem (esquerda-raiz-direita) gera uma lista ordenada.

No exemplo da Figura 1, o percurso em ordem gera a seguinte saída: `1, 3, 4, 5, 7, 8, 10, 12, 13, 14`.

O percurso em ordem é feito da seguinte maneira:

```c title="in_ordem.c" linenums="1"
--8<--
arvore.c:inordem
--8<--
```

A complexidade do algoritmo de percurso em ordem é $O(n)$, onde $n$ é a quantidade de nós de uma árvore, uma vez que o função é executada $2\cdot n$ vezes.

## Implementação

```c title="arvore_binaria_de_busca.c" linenums="1"
--8<--
abb.c:header
--8<--
```

### Inserção e Remoção

Antes de fazer a inserção, devemos determinar onde inserir o valor, fazendo uma busca por ele. Então, inserimos ele na posição ele deveria estar.

O algoritmo insere na árvore recursivamente e devolve um ponteiro para a raiz da nova árvore.

```c title="insercao_e_remocao.c" linenums="1"
--8<--
abb.c:inserir
--8<--
```

### Busca

A ideia é semelhante à busca binária, ou o valor procurado está na raiz da árvore, ou é menor, ou é maior. Se for menor, estará na subárvore da esquerda, se for maior, na da direita.

```c title="buscar.c" linenums="1"
--8<--
abb.c:buscar
--8<--
```

A complexidade da busca em uma árvore de `n` níveis, se a árvore estiver balanceada, é $O(log n)$, e no pior caso a árvore assemelha-se à uma lista encadeada, o que faz a busca ter complexidade $O(n^2)$. Isso ocorre quando os dados estão ordenados, então um novo nó sempre será inserido do mesmo lado, esquerdo, caso decrescente, direito, quando crescente.

> No caso médio, a árvore tende a ser balanceada, já que cada elemento inserido tem 50% de chance de estar à esquerda ou à direita da raiz.

### Mínimo

Basta andar a árvore sempre à esquerda, até encontrar um nó que não tenha filhos a esquerda.

```c title="minimo.c" linenums="1"
--8<--
abb.c:minimo
--8<--
```

### Máximo

Basta andar a árvore sempre à direita, até encontrar um nó que não tenha filhos a direita.

```c title="maximo.c" linenums="1"
--8<--
abb.c:maximo
--8<--
```

### Sucessor

```c title="sucessor.c" linenums="1"
--8<--
abb.c:sucessor
--8<--
```

## Referências

[1] Árvores Binárias de Busca - Notas de aula do professor Rafael C. S. Schouery, disponíveis no [link](https://www.ic.unicamp.br/~rafael/cursos/2s2019/mc202/).
