# Ordenação - Merge Sort

## Intercalação de vetores ordenados

Dados vetores crescentes `v[e...meio-1]` e `v[meio...d-1]`, queremos rearranjar `v[e...d-1]` em ordem crescente. Para isso, utilizamos o algoritmo representado abaixo. A iteração inicia com o primeiro elemento de cada subvetor, realiza a comparação entre eles, e insere o menor elemento entre eles na primeira posição do vetor auxiliar. A cada iteração, incrementa-se o índice de apenas um dos vetores auxiliares. Quando atinge-se a metade do vetor, percorrendo a primeira metade, ou o final, percorrendo a segunda, encerra-se o laço e os elementos que não haviam sido colocados no vetor auxiliar são inseridos. Por fim, desaloca-se da memória o vetor auxiliar.

```c
static void intercala(int *v, int e, int meio, int d)
{
    int *aux = malloc((d - e + 1) * sizeof(int));
    int i = e;
    int j = meio + 1;
    int k = 0;
    while (i <= meio && j <= d)
    {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    // Colocar no auxiliar o que ficar faltando após a primeira iteração.

    while (i <= meio)
        aux[k++] = v[i++];

    while (j <= d)
        aux[k++] = v[j++];

    for (int m = 0, i = e; i <= d; m++, i++)
        v[i] = aux[m];
    free(aux);
}
```

> Observação:
>
> A palavra reservada `static` indica que a função tem caráter auxiliar e não deve ser invocada diretamente.
>

## MergeSort

O algoritmo Merge Sorte parte da premissa de dividir e conquistar, o vetor é dividido em subvetores, a partir do elemento central, iterativamente, cada metade é ordenada e intercalada. O algoritmo executa recursivamente até atingir o caso base, onde o elemento da esquerda possui um índice maior ou igual ao índice do elemento da direita, ou seja, até o caso em que o subvetor resultante possua tamanho 0 ou 1.

```c
void merge_sort(int *v, int e, int d)
{
    if (e >= d)
        return;
    int meio = (e + d) / 2;
    merge_sort(v, e, meio);
    merge_sort(v, meio + 1, d);
    intercala(v, e, meio, d);
}

```

O custo de intercalar $n$ elementos é $O(n)$. A árvore de recursão possui $log\ n$ níveis, em que $n$ é a quantidade de elementos do vetor. O custo de intercalar todos os elementos em um nível é de $O(n)$.

> O custo do algoritmo Merge Sorte é: $O(n\cdot log\ n)$.
