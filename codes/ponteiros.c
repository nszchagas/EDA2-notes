#include <stdio.h>
#include <stdlib.h>

void troca(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

void hm(int minutos, int *h, int *m)
{
    *h = minutos / 60;
    *m = minutos - *h * 60;
}

void mm(int *v, int n, int *minimo, int *maximo)
{
    int min = v[0];
    int max = v[0];
    for (int j = 0; j < n; j++)
    {
        if (v[j] > max)
            max = v[j];
        if (v[j] < min)
            min = v[j];
    }
    *minimo = min;
    *maximo = max;
}

int main(void)
{

    int tamanho = 10;
    int *v = malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++)
    {
        if (i % 2 == 0)
            *(v + i) = 4;
        else
            v[i] = 7;
    }
    printf("[");
    for (int i = 0; i < tamanho - 1; i++)
    {
        printf("%d, ", v[i]);
    }
    printf("%d]\n", v[tamanho - 1]);
}