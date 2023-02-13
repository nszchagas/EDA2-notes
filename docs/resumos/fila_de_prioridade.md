# Fila de Prioridade

Uma fila de prioridade é uma estrutura de dados com duas operações básicas:

- Inserir um novo elemento
- Remover o elemento com maior chave (prioridade)

> :material-information-outline: Pilhas e filas assemelham-se às filas de prioridade, na primeira o elemento de maior prioridade é o último inserido, e nas filas o contrário acontece.

## Implementação

```c title="header.c" linenums="1"
--8<--
pq/pq.c:header
--8<--
```

> A troca de elementos será frequente, então para facilitar a leitura do código, foi implementada a função troca.

### Criação da fila prioridade

A criação da fila de prioridade consiste basicamente em alocar memória para as estruturas e definir o tamanho com e quantidade de valores preenchidos.

```c title="criar.c" linenums="1"
--8<--
pq/pq.c:criar
--8<--
```

### Inserção

A inserção é simples e feita no final do vetor.

```c title="inserir.c" linenums="1"
--8<--
pq/pq.c:inserir
--8<--
```

> :material-information-outline: A complexidade do algoritmo é $O(1)$.

### Remoção do máximo

O algoritmo percorre o vetor, guardando o índice do maior valor encontrado até o momento. No final, é feita a troca do último elemento do vetor `fprio->v[fprio->n-1]` com o maior valor encontrado `fprio->v[max]`. Então, o valor de `n` é decrementado, pois um item foi removido, e o valor removido é retornado.

```c title="extrair_maximo.c" linenums="1"
--8<--
pq/pq.c:extrairmaximo
--8<--
```

> :material-information-outline: A complexidade da extração do máximo é $O(n)$.

Os custos das operações inserção e extração são invertidas caso se deseje manter o vetor ordenado.

### Cheia vs Vazia

```c title="vazia.c" linenums="1"
--8<--
pq/pq.c:vazia
--8<--
```

```c title="cheia.c" linenums="1"
--8<--
pq/pq.c:cheia
--8<--
```

## Referências

[1] Fila de Prioridade - Notas de aula do professor Rafael C. S. Schouery, disponíveis no [link](https://www.ic.unicamp.br/~rafael/cursos/2s2019/mc202/).
