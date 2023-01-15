#include <stdio.h>
#include <stdlib.h>

int QTD_SUBMISSOES = 8;
typedef struct submission
{
    int size;
    int *times;

} submission;

submission *intercala2(submission x, submission y)
{
    int *aux = malloc((x.size + y.size) * sizeof(int));
    submission *s = malloc(sizeof(submission));
    s->size = x.size + y.size;
    s->times = aux;
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < x.size && j < y.size)
    {
        if (x.times[i] <= y.times[j])
            s->times[k++] = x.times[i++];
        else
            s->times[k++] = y.times[j++];
    }
    while (i < x.size)
        s->times[k++] = x.times[i++];
    while (j < y.size)
        s->times[k++] = y.times[j++];

    return s;
}

submission intercala4(submission a, submission b, submission c, submission d)
{
    submission *e = malloc(sizeof(submission)), *f = malloc(sizeof(submission));
    e = intercala2(a, b);
    f = intercala2(c, d);
    return *intercala2(*e, *f);
}

submission intercala8(submission *s)
{
    return *intercala2(intercala4(s[0], s[1], s[2], s[3]), intercala4(s[4], s[5], s[6], s[7]));
}

int main()
{
    int tamanho;
    submission *vetor = malloc(QTD_SUBMISSOES * sizeof(submission));
    for (int i = 0; i < QTD_SUBMISSOES; i++)
    {
        scanf("%d", &tamanho);
        submission *temp = malloc(sizeof(submission));
        vetor[i] = *temp;
        vetor[i].size = tamanho;
        vetor[i].times = malloc(tamanho * sizeof(int));
        for (int j = 0; j < tamanho; j++)
            scanf("%d", &vetor[i].times[j]);
    }

    submission *a = malloc(sizeof(submission));
    *a = intercala8(vetor);
    for (int j = 0; j < a->size; j++)
        printf("%d ", a->times[j]);
}
