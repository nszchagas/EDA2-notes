#include <stdlib.h>
#include <stdio.h>

int particiona(int *v, int e, int d)
{
    int j = e;
    int pivo = v[d];
    int temp;
    for (int i = e; i < d; i++)
        if (v[i] <= pivo)
            temp = v[j], v[j++] = v[i], v[i] = temp;
    temp = v[j], v[j] = v[d], v[d] = temp;
    return j;
}

void swap(int *array, int index1, int index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void median(int *v, int e, int d)
{
    int m = (e + d) / 2;

    int temp;
    if (v[e] >= v[m] && v[e] <= v[d] || v[e] <= v[m] && v[e] >= v[d])
        temp = v[e], v[e] = v[d], v[d] = temp;
    if (v[m] <= v[e] && v[m] >= v[d] || v[m] >= v[e] && v[m] <= v[d])
        temp = v[m], v[m] = v[d], v[d] = temp;
    if (v[d] >= v[e] && v[d] <= v[m] || v[d] <= v[e] && v[d] >= v[m])
        return;
}

void quicksort(int *v, int e, int d)
{
    while (e < d)
    {
        median(v, e, d);
        int j = particiona(v, e, d);
        if (j - e < d - e)
        {
            quicksort(v, e, j - 1);
            e = j + 1;
        }
        else
        {
            quicksort(v, j + 1, d);
            d = j - 1;
        }
    }
}

/*
    Organiza o vetor de forma que v[i] <= v[k] para todo i < k.
*/
int quickselect(int *v, int e, int d, int k)
{

    if (k > 0 && k <= d - e + 1)
    {
        int index = particiona(v, e, d);

        if (index - e == k - 1)
            return v[index];
        if (index - e > k - 1)
            return quickselect(v, e, index - 1, k);
        return quickselect(v, index + 1, d, k - index + e - 1);
    }
    return __INT_MAX__;
}

int main()
{
    int qtd, pag, prod_pag, begin, end;
    int *produtos;

    if (scanf("%d %d %d", &qtd, &pag, &prod_pag))
    {
        produtos = malloc(qtd * sizeof(int));
        for (int i = 0; i < qtd; i++)
            if (scanf("%d", produtos + i))
                ;

        begin = pag * prod_pag;
        end = begin + prod_pag - 1;

        if (end > qtd - 1)
            end = qtd - 1;

        quickselect(produtos, 0, qtd - 1, begin);
        quickselect(produtos, begin + 1, qtd - 1, end);
        quicksort(produtos, begin, end);
        for (int j = begin; j <= end; j++)
            printf("%d\n", produtos[j]);
    }
    return 0;
}