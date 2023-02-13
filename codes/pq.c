#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//--8<-- [start:header]
typedef struct
{
    char nome[20];
    int chave;
} Item;

typedef struct
{
    Item *v;
    int n, tamanho;
} FP;
typedef FP *p_fp;

p_fp criar(int tam);
void inserir(p_fp fila, Item item);
Item extrair_maximo(p_fp fila);
int vazia(p_fp fila);
int cheia(p_fp fila);

void troca(Item *a, Item *b)
{
    Item t = *a;
    *a = *b;
    *b = t;
}

//--8<-- [end:header]

//--8<-- [start:heapheader]
void insere_no_heap(p_fp fila, Item item);
Item get_maximo_heap(p_fp fila);
void altera_prioridade(p_fp fila, int posicao, int novo_valor);

// Operações

void sobe_no_heap(p_fp fila, int k);
void desce_no_heap(p_fp fila, int k);

#define PAI(i) ((i - 1) / 2)
#define F_ESQ(i) (2 * i + 1)
#define F_DIR(i) (2 * i + 2)
//--8<-- [end:heapheader]

int pow_2(int k)
{
    int p = 1;
    for (int i = 0; i < k; i++)
        p *= 2;
    return p;
}
void nl()
{
    printf("\n");
}
void print_bonitinho(p_fp fila)
{
    int tam = fila->n;
    int i = 0, j;
    int nivel = 0, index = 0;
    while (1)
    {
        int tamanho_nivel = pow_2(nivel);
        for (int j = 0; j < tamanho_nivel; j++)
        {
            if (index >= tam)
            {
                printf("\n");
                return;
            }
            printf("%d ", fila->v[index].chave);
            index++;
        }
        nivel++;
        printf("\n");
    }
}
void print_item(Item item)
{
    printf("%s = %d ", item.nome, item.chave);
}
void print_fila(p_fp fila)
{
    for (int i = 0; i < fila->n; i++)
        print_item(fila->v[i]);
    printf("\n");
}

//--8<-- [start:criar]
p_fp criar(int tam)
{
    p_fp fila = malloc(sizeof(FP));
    fila->tamanho = tam;
    fila->v = malloc(sizeof(Item) * tam);
    fila->n = 0;
    return fila;
}
//--8<-- [end:criar]

//--8<-- [start:inserir]
void inserir(p_fp fila, Item item)
{
    fila->v[fila->n++] = item;
}
//--8<-- [end:inserir]

//--8<-- [start:extrairmaximo]
Item extrair_maximo(p_fp fila)
{

    int index = 0;
    for (int i = 0; i < fila->n; i++)
        if (fila->v[i].chave > fila->v[index].chave)

            index = i;

    troca(&fila->v[index], &fila->v[fila->n - 1]);
    fila->n--;
    return fila->v[fila->n];
}
//--8<-- [end:extrairmaximo]

//--8<-- [start:vazia]
int vazia(p_fp fila)
{
    return fila->n == 0;
}
//--8<-- [end:vazia]

//--8<-- [start:cheia]
int cheia(p_fp fila)
{
    return fila->tamanho - fila->n == 0;
}
//--8<-- [end:cheia]

//--8<-- [start:sobenoheap]
// Sobe um elemento das folhas em direção a raiz, de forma que
//       os filhos de um nó sejam sempre menores que ele.
void sobe_no_heap(p_fp fila, int k)
{

    if (k > 0 && fila->v[k].chave > fila->v[PAI(k)].chave)
    {
        troca(&fila->v[k], &fila->v[PAI(k)]);
        sobe_no_heap(fila, PAI(k));
    }
}
//--8<-- [end:sobenoheap]

//--8<-- [start:descenoheap]
void desce_no_heap(p_fp fila, int k)
{
    if (k < 0 || F_ESQ(k) >= fila->n || F_DIR(k) >= fila->n)
        return;
    Item f_esq, f_dir;
    int maior_filho;
    f_esq = fila->v[F_ESQ(k)];
    f_dir = fila->v[F_DIR(k)];

    if (fila->v[k].chave >= f_esq.chave && fila->v[k].chave >= f_dir.chave)
        return;
    else
    {
        maior_filho = (f_esq.chave >= f_dir.chave) ? F_ESQ(k) : F_DIR(k);

        troca(&fila->v[k], &fila->v[maior_filho]);
        desce_no_heap(fila, maior_filho);
    }
}
//--8<-- [end:descenoheap]

//--8<-- [start:inserenoheap]
void insere_no_heap(p_fp fila, Item item)
{
    if (fila->n <= fila->tamanho)
    {
        fila->v[fila->n++] = item;
        sobe_no_heap(fila, fila->n - 1);
    }
}
//--8<-- [end:inserenoheap]

//--8<-- [start:getmaximoheap]
// Trocamos o maior elemento v[0] com o último inserido[n-1] e ajustamos o heap.
Item get_maximo_heap(p_fp fila)
{
    Item max = fila->v[0];
    troca(&fila->v[0], &fila->v[fila->n - 1]);
    fila->n--;
    desce_no_heap(fila, 0);
    return max;
}
//--8<-- [end:getmaximoheap]

//--8<-- [start:alteraprioridade]
void altera_prioridade(p_fp fila, int posicao, int novovalor)
{
    int old_prior = fila->v[posicao].chave;

    fila->v[posicao].chave = novovalor;

    if (novovalor >= old_prior)
        sobe_no_heap(fila, posicao);
    else
        desce_no_heap(fila, posicao);
}
//--8<-- [end:alteraprioridade]

int main()
{
    int tam = 12;
    int valores[10] = {10, 9, 4, 7, 8, 3, 2, 6, 1, 5};
    p_fp fila = criar(tam);

    Item *item = malloc(sizeof(Item));
    for (int i = 0; i < 10; i++)
    {
        item->chave = valores[i];
        sprintf(item->nome, "v[%dº]", i);
        insere_no_heap(fila, *item);
    }
    item->chave = 11;
    sprintf(item->nome, "v[11º]");
    insere_no_heap(fila, *item);

    Item max = get_maximo_heap(fila);
    printf("Item máximo removido: ");
    print_item(max);
    nl();

    print_bonitinho(fila);

    altera_prioridade(fila, 2, 0);
    print_bonitinho(fila);
    nl();
    return 0;
}