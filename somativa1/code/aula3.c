#include <stdio.h>

void print_vetor(int *v, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

void insercao(int *v, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int element = v[i];
        int j;
        for (j = i - 1; j >= 0 && v[j] > element; --j)
        {
            v[j + 1] = v[j];
        }

        v[j + 1] = element;
    }
}
int main()
{
    int v[] = {1, 7, -3, 2, 9};
    print_vetor(v, 5);
    insercao(v, 5);
    print_vetor(v, 5);

    return 0;
}