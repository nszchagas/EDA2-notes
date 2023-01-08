# Quicksort

O algoritmo quicksort possui complexidade $O(n\cdot log n)$ no caso médio e $O(n^2)$ no pior caso, que é quando os elementos do vetor estão arranjados na ordem inversa à desejada.

A ideia do algoritmo quicksort é particionar um vetor `v[l...r]` de forma que todos os elementos menores fiquem à esquerda do vetor e os maiores à direita.

A solução do problema parte da escolha de um pivô, digamos c. A ideia é que os elementos anteriores à c sejam menores que ele, e os posteriores maiores.

## Separação

A separação dos elementos de um pivô, em relação ao pivô, pode ser feita a seguinte maneira:

```c
int particiona(int *v, int e, int d)
{
    int pivot = v[d];
    int temp, j = e;
    for (int i = e; i < d; i++)
    {
        if (v[i] <= pivot)
        {
            temp = v[j], v[j] = v[i], v[i] = temp;
            j++;
        }
    }
    temp = v[j], v[j] = v[d], v[d] = temp;
    return j;
}
```

## Quicksort básico

Partindo da função `particiona`, podemos implementar o quicksort. A premissa do quicksort é dividir um vetor em duas partes, a partir do pivô, e ordená-los.

```c

void quicksort(int *v, int e, int d)
{
    if (d <= e)
        return;
    int j = particiona(v, e, d); 
    
    quicksort(v, e, j - 1);
    quicksort(v, j + 1, d);
}
```

## Mediana de 3

O algoritmo de quicksort pode ser otimizado pela escolha da mediana entre três valores como o pivô. Essa escolha evita que o pivô seja o maior ou menor valor do vetor. A forma clássica consiste em tomar a mediana entre os elementos `v[l]`, `v[(l+r)/2]` e `v[r]`. A função abaixo determina o valor da mediana e posiciona-a na posição `r` do vetor.

```c
void swap(int *array, int index1, int index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void median(int *v, int l, int r)
{
    int m = (r + l) / 2;
    if (v[l] <= v[m] && v[l] >= v[r] || v[l] >= v[m] && v[l] <= v[r])
        swap(v, l, r);
    if (v[r] <= v[m] && v[r] >= v[l] || v[r] >= v[m] && v[r] <= v[l])
        return; // already in right position
    if (v[m] <= v[r] && v[m] >= v[l] || v[m] >= v[r] && v[m] <= v[l])
        swap(v, m, r);
}
```

Dessa forma, o algoritmo quicksort pode ser otimizado da seguinte maneira:

```c
void quicksort(int *v, int e, int d)
{
    if (d <= e) return;
    // Posiciona o pivô na posição d
    median(v, e, d); 
    int j = particiona(v, e, d); 
    quicksort(v, e, j - 1);
    quicksort(v, j + 1, d);
}
```
