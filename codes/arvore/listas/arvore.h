#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *esq, *dir;
} No;
typedef No *p_no;

p_no criar_arvore(int dado, p_no esq, p_no dir);

p_no procurar_no(p_no raiz, int valor);
int numero_nos(p_no raiz);
int altura(p_no raiz);

// Percursos
void pre_ordem(p_no raiz);
void pos_ordem(p_no raiz);
void in_ordem(p_no raiz);
void em_largura(p_no raiz);