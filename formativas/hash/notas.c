#include <stdlib.h>
#include <stdio.h>

int MAX = 128021; // next prime number after max size
typedef struct score
{
    int value;
    int frequency;

} score;

int hash(int value)
{
    return value % MAX;
}

void *intercalate(score *array, int left, int middle, int right, char type)
{
    int size = right - left + 1;
    score *temp = malloc(size * sizeof(score));

    // Index, left index and right index.
    int i = 0, li = left, ri = middle + 1;

    while (li <= middle && ri <= right)
    {
        switch (type)
        {
        case 'F':
            if (array[li].frequency <= array[ri].frequency)
                temp[i++] = array[li++];
            else
                temp[i++] = array[ri++];
            break;
        case 'V':
            if (array[li].frequency >= array[ri].frequency)
                temp[i++] = array[li++];
            else
                temp[i++] = array[ri++];
            break;

        default:
            break;
        }
    }
    while (li <= middle)
        temp[i++] = array[li++];
    while (ri <= right)
        temp[i++] = array[ri++];

    for (int j = 0; j < i; j++)
        array[left + j] = temp[j];

    free(temp);
}

void mergesort(score *array, int left, int right, char type)
{
    if (left >= right)
        return;
    int middle = (right + left) / 2;

    mergesort(array, left, middle, type);
    mergesort(array, middle + 1, right, type);
    intercalate(array, left, middle, right, type);
}

void print_scores(score *v, int size)
{
    for (int i = 0; i < 10; i++)
    {
        printf("i = %d (v: %d, f: %d) \t", i, v[i].value, v[i].frequency);
    }
}

void sort(score *v, int size)
{
}

int main()
{
    int students;
    score *scores = malloc(MAX * sizeof(score));
    int num;
    score *temp_score = malloc(sizeof(score));
    scanf("%d", &students);

    for (int i = 0; i < students; i++)
    {
        scanf("%d", &num);
        int h = hash(num);
        if (scores[h].value != num)
        {

            temp_score->frequency = 1;
            temp_score->value = num;
            scores[h] = *temp_score;
        }
        else
        {
            scores[h].frequency++;
        }
    }
    printf("original order: ");
    print_scores(scores, MAX);
    printf("\n");
    printf("sorted by frequency: ");

    mergesort(scores, 0, MAX, 'F');
    printf("\n");
    print_scores(scores, MAX);
    printf("\n");

    if (scores[0].value == scores[1].value)
        mergesort(scores, 0, MAX, 'V');
    printf("sorted by value: ");
    print_scores(scores, MAX);
    return 0;
}