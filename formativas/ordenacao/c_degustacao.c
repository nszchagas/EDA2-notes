#include <stdio.h>
#include <stdlib.h>

typedef struct sequencia
{
    int tamanho;
    char caractere;
    int inicio;

} sequencia;

void print_sequencia(sequencia s)
{
    printf("%d %c %d\n", s.tamanho, s.caractere, s.inicio);
}

void *intercalate(sequencia *s, int left, int middle, int right)
{
    int size = right - left + 1;
    sequencia *temp = malloc(size * sizeof(sequencia));

    int i = 0, li = left, ri = middle + 1;

    while (li <= middle && ri <= right)
    {
        if (s[li].tamanho >= s[ri].tamanho)
            temp[i++] = s[li++];
        else
            temp[i++] = s[ri++];
    }
    while (li <= middle)
        temp[i++] = s[li++];
    while (ri <= right)
        temp[i++] = s[ri++];

    for (int j = 0; j < i; j++)
        s[left + j] = temp[j];

    free(temp);
}

void mergesort(sequencia *s, int left, int right)
{
    if (left >= right)
        return;
    int middle = (right + left) / 2;

    mergesort(s, left, middle);
    mergesort(s, middle + 1, right);
    intercalate(s, left, middle, right);
}

int main()
{
    int TAM_MAX = 100000;

    sequencia *notas;

    notas = malloc(TAM_MAX * sizeof(sequencia));

    char leitura = getc(stdin);

    int i = 0, pos = 0;

    notas[i].tamanho = 1;
    notas[i].caractere = leitura;
    notas[i].inicio = pos;

    while (leitura != '\n')
    {
        leitura = getc(stdin);
        pos++;
        if (leitura != '\n')
        {

            if (notas[i].caractere == leitura)
                notas[i].tamanho++;
            else
            {
                i++;
                notas[i].inicio = pos;
                notas[i].caractere = leitura;
                notas[i].tamanho = 1;
            }
        }
    }

    mergesort(notas, 0, i);
    for (int j = 0; j <= i; j++)
        print_sequencia(notas[j]);

    return 0;
}