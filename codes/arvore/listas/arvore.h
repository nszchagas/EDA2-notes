typedef struct No
{
    int dado;
    struct No *esq, *dir;
} No;

No *criar_arvore(int dado, No *esq, No *dir);
No *procurar_no(No *raiz, int valor);
int numero_nos(No *raiz);
int altura(No *raiz);