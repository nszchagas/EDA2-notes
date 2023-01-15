#include <stdlib.h>
#include <stdio.h>

int MAX_SIZE = 140000;

int hash(int value)
{
    return value % MAX_SIZE;
}


int main()
{
    int *array = malloc(MAX_SIZE * sizeof(int));
    int qtd_numbers;
    int num;
    scanf("%d", &qtd_numbers);
    for (int i = 0; i < qtd_numbers; i++)
    {
        scanf("%d", &num);
        printf("num: %d ", num);
        array[hash(num)] = num;
    }

    for (int j = 0; j < qtd_numbers; j++)
    {
        printf("%d ,", array[j]);
    }
    printf("\n");

    while (scanf("%d", &num) != EOF)
    {
        int h = hash(num);
        if (array[h] == num)
            printf("proibido ");
        else if (array[h] != num)
            printf("colisão ");
        else if (array[h] == 0)
            printf("não é proibido ");
    }
    return 0;
}