#include <stdlib.h>
#include <stdio.h>

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

/*
Intercalates the elements of an array that is sorted from left to middle and middle+1 to right.

Input array  = [0, 1, 3, -5, 2, 9], left = 0, right = 5, middle = 2
Result: array = [-5, 0, 1, 2, 3, 9]

*/
void *intercalate(int *array, int left, int middle, int right)
{
    int size = right - left + 1;
    int *temp = malloc(size * sizeof(int));

    // Index, left index and right index.
    int i = 0, li = left, ri = middle + 1;

    while (li <= middle && ri <= right)
    {
        if (array[li] <= array[ri])
            temp[i++] = array[li++];
        else
            temp[i++] = array[ri++];
    }
    while (li <= middle)
        temp[i++] = array[li++];
    while (ri <= right)
        temp[i++] = array[ri++];

    for (int j = 0; j < i; j++)
        array[left + j] = temp[j];

    free(temp);
}

void mergesort(int *array, int left, int right)
{
    if (left >= right)
        return;
    int middle = (right + left) / 2;

    mergesort(array, left, middle);
    mergesort(array, middle + 1, right);
    intercalate(array, left, middle, right);
}

int main()
{
    int MAX_SIZE = 100000;
    int size = 0;
    int *array = malloc(MAX_SIZE * sizeof(int));
    while (scanf("%d", &array[size]) != EOF)
        size++;
    mergesort(array, 0, size - 1);

    printf("\n");
    print_array(array, size);

    return 0;
}
