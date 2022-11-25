#include <stdlib.h>
#include <stdio.h>

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

void merge_sort(int *v, int e, int d)
{
    if (e >= d)
        return;
    int meio = (e + d) / 2;
    merge_sort(v, e, meio);
    merge_sort(v, meio + 1, d);
    intercala(v, e, meio, d);
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
    int v[] = {-1, 10, -7, -50, 210};
    int tamanho = 5;
    print_vetor(v, tamanho);
    merge_sort(v, 0, tamanho - 1);
    print_vetor(v, tamanho);
    return 0;
}