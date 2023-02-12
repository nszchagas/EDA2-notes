typedef struct
{
    int *dado;
    int tam;

} arvore;


void criar_arvore(int x, p_no esq, p_no dir);
int procurar_no(p_no raiz, int x);
int numero_nos(p_no raiz);
int altura(p_no raiz);