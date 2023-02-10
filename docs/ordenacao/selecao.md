# Seleção

## Overview

Os algoritmos de inserção, bolha e seleção possuem complexidade $O(n^2)$.

- Inserção
- Bolha
- Seleção

Os algoritmos quicksort, mergesort e heapsort possuem complexidade $O(n\cdot log\ n)$.

- Quicksort
- Mergesort
- Heapsort

> A ordenação, utilizando algoritmos linearítimicos, compensa para uma grande quantidade de buscas (muito mais que n buscas), compensa. Ordenar e buscar tem custo $O(n\cdot log n + log n)$.

Os algoritmos shell, contagem e distribuição possuem complexidade $O(n)$. Esses três algoritmos partem de alguma premissa em relação aos dados a serem ordenados.

- Shell
- Contagem
- Distribuição

## Ordenação por inserção

Dado um vetor `v[0...n-1]` com n elementos:

Ideia: Para cada i de `0...n-1` insere-se `v[i]` na posição correta do subvetor `v[0...i]`.

Exemplo:

```
    [4, -3, 2, 7, 1]
1º Passo: i = 0, não há nenhum elemento em v[0...i];
2º Passo: i = 1, como -3 é menor que 4, inserimos -3 na posição 0.
    [-3, 4, 2, 7, 1]
3º Passo: i = 2, como 2 é menor que 4, movemos 4 para frente. Como e é maior que -3, essa é posição final dele.
    [-3, 2, 4, 7, 1]
4º Passo: 
    [-3, 2, 4, 7, 1]
5º Passo:
    [-3, 2, 4, 1, 7]
    [-3, 2, 1, 4, 7]
    [-3, 1, 2, 1, 7]
```

O pior caso ocorre quando o elemento retirado é comparado com todos a esquerda, o que acontece quando o vetor está ordenado no sentido contrário ao desejado. Nesse caso, será feita a seguinte quantidade de comparações:

$1 + 2 + ... + n-1 = \frac{n\cdot(a_n+a_1)}{2}=\frac{(n-1)\cdot n}{2} \Rightarrow O(n^2)$.

O melhor caso ocorre quando o elemento retirado é maior que o antecessor (vetor em ordem crescente). Nesse caso a complexidade é linear. $\Rightarrow O(n)$.

Caso médio: $O(n^2)$

<!-- ### Implementação

```c
void insercao(int *v, int n){

}

``` -->

## Ordenação por seleção

Ideia: Para cada i, de 0 a n-1, selecione o menor elemento do subvetor v[i...n-1] e insira-o em v[i].

O custo de encontrar o menor elemento do subvetor tem custo $O(n)$, e o custo da ordenação por seleção é de $O(n^2)$.

## Estabilidade

Dizemos que um algoritmo de ordenação é **estável** se ele conserva a ordem relativa de elementos iguais.

O algoritmo de ordenação por inserção é estável. A demonstração pode ser feita por indução sobre o tamanho do vetor. Já o de seleção, não é estável.

Exemplo: considerando o vetor $[4_a, 2, 4_b, 1]$, temos que a ordenação pelo algoritmo da seleção geraria $[1, 2, 4_b, 4_a]$.
