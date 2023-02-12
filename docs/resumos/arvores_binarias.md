# Árvores Binárias

Uma árvore é um conjunto de elementos interligados entre si de forma que um elemento é a **raiz** e os demais se dividem em $n\geq0$, subconjuntos disjuntos chamados subárvores.

Os elementos da árvore são chamados de **nós** e as ligações entre eles são chamadas de **arestas**. O nó que não possui pai é dito **nó raiz** e os nós sem filhos são ditos **folhas**. O **grau** de um nó é a quantidade de subárvores que se originam dele.

Se uma árvore for tal que $grau(n)\leq2\ \forall\ n\ \in\ Árvore$, então dizemos que ela é uma **árvore binária**.

Níveis são "gerações" de nós na árvore, e a **altura** de uma árvore é o seu maior nível. Em uma árvore binária, um nível $k$ pode ter no máximo $2^k$ nós. O crescimento dos nós, conforme aumentamos o nível, é exponencial.

O  máximo de nós numa árvore de altura $h$ é: $2^0+2^1+...+2^h = 2^{k+1}-1$, pela soma dos termos da PG de razão 2.

## Propriedades

Uma árvore de altura $h$ tem no mínimo $h$ e no máximo $2^h-1$ nós.

<center>
![](/assets/arvores_binarias_14_57_03.png)

Figura 1: Árvores de altura 3 com o mínimo e máximo de nós. Fonte: [1]
 </center>

Se a árvore tem $n\geq1$ nós, então a altura é no mínimo $\lfloor log_2(n+1) \rfloor$, quando a árvore é completa, e no máximo $n$, quando cada nó não-terminal tem apenas um filho.

## Igualdade

Duas árvores são iguais se possuírem os mesmos dados e mesma estrutura. Árvores com os mesmos dados, mas estruturas diferentes, são ditas isomorfas.

## Implementação

A implementação pode ser feita por meio de listas encadeadas ou vetores, ambas implementações tem vantagens e desvantagens, o uso de listas encadeadas pode diminuir a performance durante a varredura da árvore, pois os nós não estão salvos em posições sequenciais da memória, em contrapartida a inserção em uma árvore na estrutura de vetor é mais trabalhosa e pode exigir redimensionamento.

### Listas Encadeadas

Cada nó da lista encadeada (Figura 2) possui a estrutura apresentada no trecho de Código 2.

<center>
![](/assets/arvores_binarias_15_00_32.png)

Figura 2: Implementação de árvore utilizando lista encadeada. Fonte: [1]
 </center>

```c
#define Item int
typedef struct no
{
    Item dado;
    struct no *esq, *dir;
} no;
```

<center>

:octicons-code-24: Código 2: Estrutura dos nós de uma árvore usando lista encadeada. Fonte: [2]

</center>

:material-information-outline: A definição de `Item` por macro permite a alteração do tipo em tempo de compilação, com a flag `-D`, utilizando o gcc. Esse tipo de implementação fornece maior versatilidade no código.

```shell
gcc -o  a.out -DItem=float a.c
```

### Vetores

A árvore é distribuída em um vetor de forma que dada uma raiz na posição `i`, seus filhos esquerdo e direito estão nas posições `2*i+1` e `2*i+2`, respectivamente.

Observe que como uma árvore binária de com `k` níveis tem, no máximo `2^k` nós, sabendo a altura da árvore é possível alocar o tamanho certo do vetor.

<center>
![](/assets/arvores_12_31_11.png)

Figura 3: Exemplo de árvore (binária de busca). Fonte: [2]
 </center>

A árvore da Figura 3 ocuparia o vetor `v` da maneira representada a seguir, onde `-1` indica posições desocupadas do vetor.

```c
// Posição:       0  1  2  3  4  5  6  7
            v = [ 6, 5, 7, 2, 5,-1, 8,-1]
```

As funções que calculam as posições dos pais e filhos podem ser definidas pelas seguintes macros:

```c

#define PAI(n) ((int) n / 2)
#define ESQ(n) (2 * n + 1)
#define DIR(n) (2 * n + 2)

```

O vetor pode ser encapsulado em uma struct contendo também o seu tamanho:

```c
#define item int

typedef struct
{
    item *content;
    int size;
} tree;

typedef tree *p_tree;

void init_tree(p_tree tree, int height)
{
    int size = pow_2(height);
    tree->size = size;
    tree->content = malloc(size * sizeof(item));
    
    for (int i = 0; i < tree->size; i++)
        tree->content[i] = -1;
}
```

## Varredura

Árvores são estruturas de dados não lineares, pois há várias formas distintas de percorrer seus elementos. As três formas padrão são:

- Em ordem (esquerda-raiz-direita)
- Pré-ordem (raiz-esquerda-direita)
- Pós-ordem (esquerda-direita-raiz)

### Pós ordem

O algoritmo para a varredura **pós ordem** visita:

1. A subárvore esquerda da raiz, em ordem e-d-r
2. A subárvore direita da raiz, em ordem e-d-r
3. A raiz

<center>
![](/assets/arvores_binarias_15_09_18.png)

Figura 4: Ordem de visitação dos nós em pós-ordem. Fonte: [1]
</center>

### Pré ordem

O algoritmo para a varredura **pré ordem** visita:

1. A raiz
2. A subárvore esquerda da raiz, em ordem r-e-d
3. A subárvore direita da raiz, em ordem r-e-d

<center>
![](/assets/arvores_binarias_15_09_40.png)

Figura 5: Ordem de visitação dos nós em pré-ordem. Fonte: [1]
</center>

### Em ordem

O algoritmo para a varredura **em ordem** visita:

1. A subárvore esquerda da raiz, em ordem e-r-d
2. A raiz
3. A subárvore direita da raiz, em ordem e-r-d

A implementação pode ser feita por meio da recursão (Código 1).

<center>
![](/assets/arvores_binarias_15_08_43.png)

Figura 6: Ordem de visitação dos nós em ordem. Fonte: [1]
</center>

```title="Pseudo código - varredura em ordem" linenums="1"
 varredura-em-ordem(r)
 if r != NIL
   varredura-em-ordem(r.esquerda)
   print r.chave
   varredura-em-ordem(r.direita)
```

<center>

:octicons-code-24: Código 1: Varredura em ordem. Fonte: [2]

</center>

### Em largura

O percurso em largura visita os nós por níveis, da esquerda para a direita.
<center>
![](/assets/arvores_binarias_15_34_19.png)

Figura 7: Percurso em Largura. Fonte: [1]
</center>

## Referências

[1] Árvores Binárias - Notas de aula do professor Rafael C. S. Schouery, disponíveis no [link](https://www.ic.unicamp.br/~rafael/cursos/2s2019/mc202/).
[2] Introduction to Algorithms, 3rd edition.
