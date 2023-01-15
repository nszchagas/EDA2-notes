#include <stdio.h>
#include <stdlib.h>

typedef struct streak
{
    char letter;
    int size;
    int pos;
} streak;

int MAX_SIZE = 100000;
int main()
{
    char curr_char, prev_char;
    streak *s = malloc(sizeof(streak) * MAX_SIZE);
    streak *new_streak;

    curr_char = getchar();
    int pos = 0, i = 0;
    while (curr_char != EOF)
    {
        prev_char = curr_char;
        curr_char = getchar();
        if (curr_char != EOF)
        {
            if (prev_char == curr_char)
                s[i].size++;
            else
            {
                new_streak = malloc(sizeof(streak));
                new_streak->size = 0;
                new_streak->pos = pos;
                new_streak->letter = curr_char;
                s[i++] = *new_streak;
            }
        }
        pos++;
    }

    for (int j = 0; j < i; j++)
    {
        printf("i: %d, %d %c %d\n", j, s[j].size, s[j].letter, s[j].pos);
    }

    return 0;
}