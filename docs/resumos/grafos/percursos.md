
# Percursos

## Caminho

Um caminho de `s` para `t` em um grafo é:

- Uma sequência sem repetição de vértices vizinhos
- Começando em `s` e terminando em `t`

Formalmente, um caminho de `s` para `t` em um grafo é:

- Uma sequência de vértices $v_0, v_1, ..., v_k$ onde $v_0=s$ e $v_k=t$
- $\{v_i, v_{i+1}\}$ é uma aresta $\forall 0\leq i \leq k-1$
- $v_i\neq v_j \forall 0 \leq i < j \leq k$

$k$ é o comprimento do caminho, a quantidade de vértices do caminho - 1.

## Componentes Conexas

Um grafo pode ser dividido em várias "partes", chamadas de **componentes conexas**.

<center>
![](/assets/percursos_15_01_09.png)

Figura 1: Componentes Conexas. Fonte: [1]
</center>

Um par de vértices está na mesma componente se, e somente se, existe caminho entre eles. Não há caminho entre vértices de componentes distintas.

Um grafo **conexo** tem apenas uma componente conexa.


