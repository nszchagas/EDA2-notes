# Grafos

## Definição

Um **grafo** é um conjunto de objetos ligados, por **arestas**, entre si, chamados de **vértices**.

<center>

![](../assets/grafos_16_19_53.png)
<div style="text-align: center">
<p>
Figura 1: Representação de um Grafo. Fonte:[1]
</p>
</div>
</center>

Essa estrutura pode ser utilizada para a modelagem de problemas envolvendo redes sociais, mapas, páginas na internet, redes de computadores, circuitos eletrônicos, dentre outros.

:material-information-outline: Matematicamente, um grafo $G$ é um par ordenado $\left (V,E\right)$ onde:

- V é o conjunto dos vértices do grafo;
  - Exemplo: $V={0, 1, 2, 3, 4, 5}
- E é o conjunto de arestas do grafo;
  - Representamos uma aresta ligando $u, v\in V$ como $\{u,v\}$.
  - Pra toda aresta $\{u,v\}$ tem-se $u\neq v$;
  - Existe no máximo uma aresta $\{u, v\} \in E$;
  - $E=\{\{0,1\}\, \{0, 4\}, \{5, 3\}, \{1, 2\}, \{2, 5\}, \{4, 5\}, \{3, 2\}, \{1, 4\}\}$

Dizemos que os vértices 0 e 4 são **adjacentes**, e 0, 1 e 5 formam a **vizinhança** (conjunto de adjacência) do vértice 4.

## Matriz de Adjacências

Um grafo pode ser representado por uma matriz de adjacências.

Se o grafo tem `n` vértices, teremos vértices numerados de `0` a `n-1` e a matriz com dimensão $n \times n$.

A matriz forma-se da seguinte maneira:

- `adjacencia[u][v] = (u e v vizinhos)? 1 : 0`;

<center>

![](../assets/grafos_16_28_06.png)
<div style="text-align: center">
<p>
Figura 2: Representação do grafo em uma matriz de adjacências. Fonte: [1]
</p>
</div>
</center>

A matriz de adjacência é simétrica, pois $A_{i,j} = A_{j,i} \forall i, j \in [0, n-1]$.

> :material-information-outline:
> Ressalvas ao utilizar matrizes:
> A representação do grafo em matriz gera um desperdício de memória, pois bastaria guardar metade dos valores.
> Há um alto consumo de memória, a depender do tamanho do n.
> A matriz guarda as ligações e não ligações entre os vértices, mas poderia guardar apenas as ligações.

## Implementação

A estrutura do grafo com matriz de adjacências `adj` e `n` vértices é dada por:

```c title="grafo.c" linenums="1"
--8<--
grafos.c:header
--8<--
```

### Inicialização e destruição

```c title="criar.c" linenums="1"
--8<--
grafos.c:criar
--8<--
```

### Manipulando arestas

```c title="manipulando_arestas.c" linenums="1"
--8<--
grafos.c:arestas
--8<--
```

### Lendo e imprimindo um Grafo

```c  title="leitura.c" linenums="1"
--8<--
grafos.c:leitura
--8<--
```

## Grau

O grau de um vértice é a quantidade de arestas que saem dele.

Para calcular o grau de um vértice, basta percorrer a quantidade de `1` na linha (ou coluna) correspondente ao vértice.

```c  title="grau.c" linenums="1"
--8<--
grafos.c:grau
--8<--
```

## Recomendações

No contexto das redes sociais, é comum que sejam recomendados amigos para os membros da rede. Por exemplo, podemos sugerir novos amigos para Ana (Figura 2), baseando-nos nas conexões que ela já possui.

<center>
![](/assets/grafos_13_43_01.png)

Figura 2: Recomendação de amigos. Fonte: [1]
</center>

Essa recomendação pode ser feita com o algoritmo a seguir.

```c  title="recomendacoes.c" linenums="1"
--8<--
grafos.c:recomendacoes
--8<--
```

## Percursos

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

Um par de vértices está na mesma componente se, e somente se, existe caminho entre eles. Não há caminho entre vértices de componentes distintas.

Um grafo **conexo** tem apenas uma componente conexa.
