# Grafos

Königsberg (hoje Kaliningrado, Rússia) tinha 7 pontes e acreditava-se que era possível passear por toda a cidade atravessando cada ponte exatamente uma vez.

<center>
![](/assets/estrutura_14_32_11.png)

Figura 1: Motivação. Fonte: [1]
</center>

Leonhard Euler, em 1736, modelou o problema como um grafo, provou que tal passeio não é possível e fundou a teoria dos grafos.

## Definição

Um **grafo** é um conjunto de objetos ligados, por **arestas**, entre si, chamados de **vértices**.

<center>

![](/assets/grafos_16_19_53.png)
<div style="text-align: center">
<p>
Figura 2: Representação de um Grafo. Fonte:[1]
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

![](/assets/grafos_16_28_06.png)
<div style="text-align: center">
<p>
Figura 3: Representação do grafo em uma matriz de adjacências. Fonte: [1]
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

### Grau

O grau de um vértice é a quantidade de arestas que saem dele.

Para calcular o grau de um vértice, basta percorrer a quantidade de `1` na linha (ou coluna) correspondente ao vértice.

```c  title="grau.c" linenums="1"
--8<--
grafos.c:grau
--8<--
```

### Recomendações

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

## Grafos Dirigidos

Um **grafo dirigido (dígrafo)** possui um conjunto de vértices conectados por **arcos**, que são arestas dirigidas, i. e., arestas que indicam início e fim.

<center>
![](/assets/estrutura_14_09_10.png)

Figura 4: Grafo Dirigidos. Fonte: [1]
</center>

Matematicamente, um dígrafo $G$ é um par $(V,A)$ formado pelos conjuntos de vértices $V$ e arestas $A$.

- Representamos um arco ligando $u,v\in\ V$ como $(u,v)$, onde $u$ é a **cauda** do arco e $v$ a **cabeça**.
- Podemos ter laços da forma $(u,u)$
- Existe no máximo um arco $(u,v)$ em $A$.

> :material-information-outline: Um grafo pode ser visto como um dígrafo se considerarmos cada aresta como  dois arcos.
> A implementação por matriz de adjacências já considera os dois arcos, então nesse caso pode ocorrer: `adj[u][v] != adj[v][u]`, já que `adj[u][v]` indica um arco de $u$ para $v$.

## Número de Arestas

<center>
![](/assets/estrutura_14_16_54.png)

Figura 5: Grafo com a quantidade máxima de arestas. Fonte: [1]
</center>

Um grafo com $n$ vértices pode ter no máximo $\binom{n}{2} = \frac{n(n-1)}{2} = O(n^2)$ arestas. E dizemos que um grafo é **esparso** quando ele possui bem menos (em outra ordem de grandeza) do que essa quantidade de arestas.

Exemplos de grafos esparsos:

- Grafos cujos vértices tem o mesmo grau $d$ constante, possuem $\frac{nd}{2} = O(n)$ arestas.
- Grafos com $O(n\ log\ n)$ arestas.

## Listas de Adjacências

<center>
![](/assets/estrutura_14_20_43.png)

Figura 6: Representação do grafo por lista de adjacências. Fonte: [1]
</center>

```c title="header.c" linenums="1"
--8<--
tad_grafo.c:header
--8<--
```

### Inicialização

```c title="inicializacao.c" linenums="1"
--8<--
tad_grafo.c:inicializacao
--8<--
```

### Manipulação de Arestas

```c title="arestas.c" linenums="1"
--8<--
tad_grafo.c:arestas
--8<--
```

## Comparação Listas vs Matrizes

Espaço necessário para o armazenamento:

- Matriz: $O(n^2)$
- Listas: $O(n + |E|)$

:material-information-outline: $n=|V|$, onde V é o conjunto das arestas (ou arcos).

Comparativo de tempo:
<center>

| Operação             | Matriz | Listas    |
| -------------------- | ------ | --------- |
| Inserir              | $O(1)$ | $O(1)$    |
| Remover              | $O(1)$ | $O(d(v))$ |
| Aresta Existe?       | $O(1)$ | $O(d(v))$ |
| Percorrer Vizinhança | $O(n)$ | $O(d(v))$ |

</center>
## O problema das Pontes de Königsberg

<center>
![](/assets/estrutura_14_33_29.png)

Figura 7: Grafos para o problema das Pontes. Fonte: [1]
</center>

A estrutura da Figura 1 é chamada de **multigrafo**, nela é possível ter arestas paralelas (ou múltiplas), existe um multiconjunto de arestas e pode ser representada por listas de adjacência.

## Referências

[1] Grafos (Estrutura) - Notas de aula do professor Rafael C. S. Schouery, disponíveis no [link](https://www.ic.unicamp.br/~rafael/cursos/2s2019/mc202/).
