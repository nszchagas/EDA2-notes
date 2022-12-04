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

int *intercala_disjuntos(int *x, int *y, int sx, int sy)
{
    int *aux = malloc((sx + sy) * sizeof(int));
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < sx && j < sy)
    {
        if (x[i] <= y[j])
            aux[k++] = x[i++];
        else
            aux[k++] = y[j++];
    }
    while (i < sx)
        aux[k++] = x[i++];
    while (j < sy)
        aux[k++] = y[j++];
    return aux;
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
    int w[] = {2, 5, 10, 20};

    int tamanho = 5;
    int tamanhow = 4;

    print_vetor(v, tamanho);
    intercala(v, 0, 0, 0);
    // merge_sort(v, 0, tamanho - 1);
    print_vetor(v, tamanho);
    int *t = malloc((tamanho + tamanhow) * sizeof(int));

    t = intercala_disjuntos(v, w, tamanho, tamanhow);

    print_vetor(t, tamanho + tamanhow);

    return 0;
}