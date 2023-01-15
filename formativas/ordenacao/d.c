#include <stdlib.h>
#include <stdio.h>

typedef struct candidate
{
    int number;
    int votes;

} candidate;

int main()
{
    int PRESIDENT_NUMBERS = 100,
        SENATOR_NUMBERS = 1000,
        FED_DEP_NUMBERS = 10000,
        EST_DEP_NUMBERS = 100000;

    candidate *presidents = malloc(PRESIDENT_NUMBERS * sizeof(candidate));
    candidate *senators = malloc(SENATOR_NUMBERS * sizeof(candidate));
    candidate *fed_dep = malloc(FED_DEP_NUMBERS * sizeof(candidate));
    candidate *est_dep = malloc(EST_DEP_NUMBERS * sizeof(candidate));

    return 0;
}