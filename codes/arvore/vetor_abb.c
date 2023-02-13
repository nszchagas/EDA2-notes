#include <stdio.h>
#include <stdlib.h>

//--8<-- [start:header]

#define item int

typedef struct
{
    item *content;
    int size;
} tree;

typedef tree *p_tree;

#define PAI(n) ((int)n / 2)
#define ESQ(n) (2 * n + 1)
#define DIR(n) (2 * n + 2)

void criar_arvore(p_tree tree, int height);
int inserir(p_tree tree, item value, int start);
//--8<-- [end:header]

int pow_2(int n)
{
    int x = 1;
    for (int i = 0; i < n; i++)
        x *= 2;
    return x;
}
//--8<-- [start:inserir]

int inserir(p_tree tree, item value, int start)
{
    for (int i = start; i < tree->size; i++)
    {
        if (tree->content[i] == -1)
        {
            tree->content[i] = value;
            return i;
        }
        if (value < tree->content[i])
            return inserir(tree, value, ESQ(i));
        if (value > tree->content[i])
            return inserir(tree, value, DIR(i));
    }
    return -1;
}
//--8<-- [end:inserir]

//--8<-- [start:criar]
void criar_arvore(p_tree tree, int height)
{
    int size = pow_2(height);
    tree->size = size;
    tree->content = malloc(size * sizeof(item));
    for (int i = 0; i < tree->size; i++)
    {
        tree->content[i] = -1;
    }
}
//--8<-- [end:criar]

void print_tree(p_tree t)
{
    for (int i = 0; i < t->size; i++)
    {
        if (t->content[i] != -1)
            printf("v[%d] = %d ", i, t->content[i]);
    }
    printf("\n");
}

int main()
{
    p_tree tree = malloc(sizeof(tree));
    int max_height = 6;
    criar_arvore(tree, max_height);

    inserir(tree, 10, 0);
    inserir(tree, 4, 0);
    inserir(tree, 17, 0);
    inserir(tree, 5, 0);
    inserir(tree, 16, 0);
    inserir(tree, 21, 0);

    for (int i = 0; i < 5; i++)
    {
        inserir(tree, i * 3, 0);
    }

    print_tree(tree);
}
