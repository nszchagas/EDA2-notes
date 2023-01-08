#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
int particiona_not_optimized(int *v, int e, int d)
{
    int *menores, *maiores;
    int size = d - e;
    menores = malloc(size * sizeof(int));
    maiores = malloc(size * sizeof(int));
    int pivot = v[d];
    int k, n;
    k = 0, n = 0;
    for (int i = e; i < d; i++)
    {
        if (v[i] < pivot)
        {
            menores[k++] = v[i];
        }
        else
        {
            maiores[n++] = v[i];
        }
    }

    int i = e;
    for (int m = 0; m < k + 1; m++)
        v[i++] = menores[m];

    int pos = i;
    v[i] = pivot;

    for (int p = 0; p < n; p++)
        v[i++] = maiores[p];

    free(maiores);
    free(menores);

    return pos;
}

void quicksort(int *v, int e, int d)
{
    if (d <= e)
        return;
    int j = particiona(v, e, d); // v[j] é chamado de pivô
    quicksort(v, e, j - 1);
    quicksort(v, j + 1, d);
}

void print_vetor(int *v, int size)
{
    printf("[");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d, ", v[i]);
    }
    printf("%d]\n", v[size - 1]);
}

int main()
{
    int v[] = {50, 7, -5, 87, 4};

    int tamanho = 5;
    print_vetor(v, tamanho);
    // int j = particiona_not_optimized(v, 0, tamanho - 1);
    quicksort(v, 0, tamanho - 1);
    print_vetor(v, tamanho);

    // printf("%d %d\n", j, k);

    // print_vetor(v, tamanho);
    // merge_sort(v, 0, tamanho - 1);
    // print_vetor(v, tamanho);

    return 0;
}