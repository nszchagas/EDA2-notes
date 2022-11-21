#include <stdlib.h>
#include <stdio.h>

typedef struct celula
{
    int valor;
    int index;

} celula;

void swap(int *vetor, int indexA, int indexB)
{
    int temp = vetor[indexA];
    vetor[indexA] = vetor[indexB];
    vetor[indexB] = temp;
}

void selection_sort(int *vetor, int tamanho)
{
    celula *menor;
    menor = malloc(sizeof(celula));
    for (int i = 0; i < tamanho; i++)
    {
        menor->index = i;
        menor->valor = vetor[i];

        for (int j = i; j < tamanho; j++)
            if (vetor[j] <= menor->valor)
            {
                menor->valor = vetor[j];
                menor->index = j;
            }
        if (i != menor->index)
            swap(vetor, i, menor->index);
    }
}

int main()
{
    int numeros[1000];

    int i = 0;
    int read;
    do
    {
        read = scanf("%d", numeros + i++);

    } while (read != EOF);
    i--; // Decrementa um do i já que o EOF foi guardado no vetor.

    selection_sort(numeros, i);
    for (int j = 0; j < i - 1; j++)
        printf("%d ", numeros[j]);
    printf("%d\n", numeros[i - 1]);

    return 0;
}