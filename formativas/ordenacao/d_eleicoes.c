#include <stdio.h>
#include <stdlib.h>

typedef struct candidato
{
    int numero;
    int votos;

} candidato;

int QTD_PRESIDENTES = 100, QTD_SENADORES = 1000, QTD_FEDERAIS = 10000, QTD_ESTADUAIS = 100000;
candidato *presidentes, *senadores, *federais, *estaduais;

void intercala(candidato *array, int e, int m, int r)
{
    int size = r - e + 1;
    candidato *temp = malloc(size * sizeof(candidato));

    // Index, left index and r index.
    int i = 0, li = e, ri = m + 1;

    while (li <= m && ri <= r)
    {
        if (array[li].votos > array[ri].votos)
            temp[i++] = array[li++];
        else if (array[li].votos == array[ri].votos)
            if (array[li].numero > array[ri].numero)
                temp[i++] = array[li++];
            else
                temp[i++] = array[ri++];
        else
            temp[i++] = array[ri++];
    }
    while (li <= m)
        temp[i++] = array[li++];
    while (ri <= r)
        temp[i++] = array[ri++];

    for (int j = 0; j < i; j++)
        array[e + j] = temp[j];

    free(temp);
}

void mergesort(candidato *array, int e, int d)
{
    if (e >= d)
        return;
    int m = (d + e) / 2;
    mergesort(array, e, m);
    mergesort(array, m + 1, d);
    intercala(array, e, m, d);
}

void print_candidatos(int votos_pres, int qtd_senadores, int qtd_federais, int qtd_estaduais)
{
    if (presidentes[0].votos >= 0.51 * votos_pres)
        printf("%d\n", presidentes[0].numero);
    else
        printf("Segundo turno\n");

    for (int s = 0; s < qtd_senadores; s++)
        printf("%d ", senadores[s].numero);
    printf("\n");
    for (int f = 0; f < qtd_federais; f++)
        printf("%d ", federais[f].numero);
    printf("\n");
    for (int e = 0; e < qtd_estaduais; e++)
        printf("%d ", estaduais[e].numero);
    printf("\n");
}

int main()
{
    int qtd_sen, qtd_fed, qtd_est;
    int votos_pres = 0;
    scanf("%d %d %d", &qtd_sen, &qtd_fed, &qtd_est);
    int voto;
    int invalidos = 0, validos = 0;

    presidentes = malloc(QTD_PRESIDENTES * sizeof(candidato));
    senadores = malloc(QTD_SENADORES * sizeof(candidato));
    federais = malloc(QTD_FEDERAIS * sizeof(candidato));
    estaduais = malloc(QTD_ESTADUAIS * sizeof(candidato));

    while (scanf("%d", &voto) != -1)
    {
        if (voto < 0)
            invalidos++;
        else
        {
            validos++;

            if (voto % QTD_PRESIDENTES == voto)
            {
                votos_pres++;
                if (presidentes[voto].votos == 0)
                {
                    presidentes[voto].numero = voto;
                    presidentes[voto].votos = 1;
                }
                else
                    presidentes[voto].votos++;
            }
            else if (voto % QTD_SENADORES == voto)
            {
                if (senadores[voto].votos == 0)
                {
                    senadores[voto].numero = voto;
                    senadores[voto].votos = 1;
                }
                else
                    senadores[voto].votos++;
            }
            else if (voto % QTD_FEDERAIS == voto)
            {

                if (federais[voto].votos == 0)
                {
                    federais[voto].numero = voto;
                    federais[voto].votos = 1;
                }
                else
                    federais[voto].votos++;
            }
            else if (voto % QTD_ESTADUAIS == voto)
            {

                if (estaduais[voto].votos == 0)
                {
                    estaduais[voto].numero = voto;
                    estaduais[voto].votos = 1;
                }
                else
                    estaduais[voto].votos++;
            }
        }
    }
    printf("%d %d\n", validos, invalidos);

    // print_candidatos(presidentes, senadores, federais, estaduais);
    mergesort(presidentes, 0, QTD_PRESIDENTES);
    mergesort(senadores, 0, QTD_SENADORES);
    mergesort(federais, 0, QTD_FEDERAIS);
    mergesort(estaduais, 0, QTD_ESTADUAIS);
    print_candidatos(votos_pres, qtd_sen, qtd_fed, qtd_est);

    return 0;
}