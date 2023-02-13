#include <stdlib.h>
#include <stdio.h>
//--8<-- [start:header]

typedef struct
{
    int **adj;
    int n;
} Grafo;

typedef Grafo *p_grafo;

p_grafo criar_grafo(int n);
void destruir_grafo(p_grafo g);

void insere_aresta(p_grafo g, int u, int v);
void remove_aresta(p_grafo g, int u, int v);
int tem_aresta(p_grafo g, int u, int v);
void imprime_arestas(p_grafo g);

int grau(p_grafo, int a);
int mais_popular(p_grafo g);

void imprime_recomendacoes(p_grafo g, int u);
//--8<-- [end:header]

//--8<-- [start:criar]
p_grafo criar_grafo(int n)
{
    p_grafo p = malloc(sizeof(Grafo));
    p->n = n;
    p->adj = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        p->adj[i] = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            p->adj[i][j] = 0;
    return p;
}
void destruir_grafo(p_grafo g)
{
    for (int i = 0; i < g->n; i++)
        free(g->adj[i]);
    free(g->adj);
    free(g);
}
//--8<-- [end:criar]

//--8<-- [start:arestas]
void insere_aresta(p_grafo g, int u, int v)
{
    if (u < g->n && v < g->n)
    {
        g->adj[u][v] = 1;
        g->adj[v][u] = 1;
    }
}
void remove_aresta(p_grafo g, int u, int v)
{
    if (u < g->n && v < g->n)
    {
        g->adj[u][v] = 0;
        g->adj[v][u] = 0;
    }
}
int tem_aresta(p_grafo g, int u, int v)
{
    if (u < g->n && v < g->n)
        return g->adj[u][v];
    return -1;
}
//--8<-- [end:arestas]

//--8<-- [start:leitura]
p_grafo le_grafo()
{
    p_grafo g;

    int tam, qtd, u, v;
    scanf("%d %d", &tam, &qtd);
    g = criar_grafo(tam);
    for (int i = 0; i < qtd; i++)
    {
        scanf("%d %d", &u, &v);
        insere_aresta(g, u, v);
    }
    return g;
}

void imprime_arestas(p_grafo g)
{
    int u, v;
    for (u = 0; u < g->n; u++)
        for (v = u + 1; v < g->n; v++)
            if (g->adj[u][v])
                printf("{%d, %d}\n", u, v);
}
//--8<-- [end:leitura]

//--8<-- [start: grau]
int grau(p_grafo g, int u)
{
    int grau = 0;
    for (int i = 0; i < g->n; i++)
        grau += g->adj[u][i];
    return grau;
}

int mais_popular(p_grafo g)
{
    int mais_popular = 0;
    int maior_grau = grau(g, mais_popular);
    int grau_c;
    for (int i = 0; i < g->n; i++)
    {
        grau_c = grau(g, i);
        if (maior_grau < grau_c)
        {
            mais_popular = i;
            maior_grau = grau_c;
        }
    }
    return mais_popular;
}
//--8<-- [end: grau]

//--8<-- [start: recomendacoes]
void imprime_recomendacoes(p_grafo g, int u)
{
    for (int i = 0; i < g->n; i++)
        if (tem_aresta(g, u, i))
            for (int j = 0; j < g->n; j++)
                if (tem_aresta(g, i, j) && j != u && !tem_aresta(g, u, j))
                    printf("%d ", j);
}
//--8<-- [end: recomendacoes]
int main()
{
    p_grafo g = le_grafo();
    printf("Grau do 4: %d\n", grau(g, 4));
    printf("Mais popular: %d\n", mais_popular(g));
    imprime_arestas(g);
    printf("Recomendações para o 3:\n");
    imprime_recomendacoes(g, 3);
    destruir_grafo(g);
    return 0;
}