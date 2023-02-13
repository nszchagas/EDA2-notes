# Heap

## Definição

O **heap de máximo** é uma árvore em que os filhos de cada nó são menores ou iguais ao pai. Simetricamente, no **heap de mínimo** os filhos são maiores ou iguais ao pai. Essa estrutura possui a propriedade de alocar o maior (ou menor) elemento na raiz da árvore.

> Um heap não é uma árvore binária de busca, nele os dados estão bem menos estruturados, pois o interesse está apenas em encontrar o maior (ou menor) valor.

<center>
![](/assets/heap_09_56_26.png)

Figura 1: Heap de Máximo. Fonte: [1]
</center>

## Implementação

O Heap pode ser representado na forma de [arvore binária completa](arvores_binarias.md#arvore-binaria-completa), utilizando vetores.

```c title="heap.c" linenums="1"
--8<--
pq.c:heapheader
--8<--
```

### Subindo e Descendo no Heap

```c title="sobenoheap.c" linenums="1"
--8<--
pq.c:sobenoheap
--8<--
```

```c title="descenoheap.c" linenums="1"
--8<--
pq.c:descenoheap
--8<--
```

### Inserção

```c title="heap.c" linenums="1"
--8<--
pq.c:inserenoheap
--8<--
```

> A inserção custa $O(log\ n)$, pois subimos no máximo até a raiz.

### Extraindo o máximo

```c title="getmaximoheap.c" linenums="1"
--8<--
pq.c:getmaximoheap
--8<--
```

> Extrair o valor máximo custa $O(log\ n)$, pois descemos no máximo a altura da árvore.

### Mudando a prioridade

Se a prioridade do item aumentar, precisamos subir arrumando, caso contrário, descer arrumando.

```c title="alteraprioridade.c" linenums="1"
--8<--
pq.c:alteraprioridade
--8<--
```

Para alterar a prioridade precisamos saber a posição do item no heap, e a busca por essa posição tem custo  $O(n)$. Podemos melhorar esse custo incluindo um campo `id` com valores de `0` a `n-1` nos itens, criando um vetor de `n` posições como parte do `heap` armazenando a posição de cada item no `heap`, então podemos recuperar essa posição em $O(1)$.

## Referências

[1] Fila de Prioridade e Heap - Notas de aula do professor Rafael C. S. Schouery, disponíveis no [link](https://www.ic.unicamp.br/~rafael/cursos/2s2019/mc202/).
