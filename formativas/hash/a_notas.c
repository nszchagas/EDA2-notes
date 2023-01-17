#include <stdlib.h>
#include <stdio.h>

int MAX_SCORE = 1001; // maximum score + 1
typedef struct score
{
    int value;
    int frequency;

} score;

/* Returns the index of the right position for the pivot, in the array[right] position.
    Sorts based on the frequency.
*/
int partition(score *v, int left, int right)
{
    score pivot = v[right];
    int j = left;
    score temp;

    for (int i = left; i < right; i++)
    {

        if (v[i].frequency > pivot.frequency)
            temp = v[i], v[i] = v[j], v[j++] = temp;
        if (v[i].frequency == pivot.frequency && v[i].value > pivot.value)
            temp = v[i], v[i] = v[j], v[j++] = temp;
    }
    temp = v[j], v[j] = v[right], v[right] = v[j];
    return j;
}

void quicksort(score *array, int left, int right)
{
    if (left >= right)
        return;
    int j = partition(array, left, right);
    quicksort(array, left, j - 1);
    quicksort(array, j + 1, right);
}

int main()
{
    int qt_students;
    int curr_score;
    score *scores = malloc(MAX_SCORE * sizeof(score));

    scanf("%d", &qt_students);
    for (int i = 0; i < qt_students; i++)
    {
        scanf("%d", &curr_score);
        if (scores[curr_score].value == 0 && scores[curr_score].frequency == 0)
        {
            scores[curr_score].value = curr_score;
            scores[curr_score].frequency = 1;
        }
        else if (scores[curr_score].value == curr_score)
            scores[curr_score].frequency++;
        else
            printf("colisão!!!!!!!\n");
    }

    quicksort(scores, 0, MAX_SCORE);

    printf("%d", scores[0].value);
    return 0;
}