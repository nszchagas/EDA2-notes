# Endereços e Ponteiros

## Endereços

A memória RAM de qualquer computador é uma sequência de bytes. A posição (0, 1, 2, ...) que um byte ocupa nessa sequência é o seu endereço. Cada tipo de dado ocupa um determinado espaço na memória, dados do tipo `char` ocupam 1 byte, enquanto inteiros (`int`) ocupam 4. Um número decimal de precisão dupla (`double`) ocupa, geralmente, 8 bytes. O número exatos de bytes ocupados por um tipo é dado pelo operador `sizeof` em c.

```c
struct
{
    int x, y, z;
} ponto;

int main()
{
    printf("Size of ponto: %ld\n", sizeof(ponto));
            // Imprime 12, já que há 3*4 bytes.
    return 0;
}

```

O endereço de uma variável, em C, pode ser obtido pelo operador `&`. Para fazer a impressão de um endereço na console, é necessário fazer um casting:

```c
    int i = 1234;
    printf(" i = %d\n", i);             // i = 1234
    printf("&i = %ld\n", (long int)&i); // &i = 140732356398116
    printf("&i = %p\n", (void *)&i);    // &i = 0x7ffece1c8c24
```

## Ponteiros

Um ponteiro é um tipo especial de variável que armazena um endereço de memória. Um ponteiro pode ter o endereço `NULL`, que indica um endereço inválido.

> :material-information-outline: A macro `NULL` está definida na interface `stdlib.h` e seu valor é zero na maioria dos computadores, é armazenada em uma posição pré-fixada.

Dado um ponteiro p, armazenando o endereço de i, dizemos que p é uma referência à variável, e tem-se que `*p == i` e `&i == p`.

> :material-information-outline: A existência de ponteiros possibiliza que sejam realizadas operações entre eles.

Há vários tipos de ponteiros, como ponteiros para bytes, para inteiros, para ponteiros para inteiros, etc. Esses ponteiros podem ser declarados da seguinte forma:

```c
    int *p1; // Ponteiro para inteiro.
    int **p2; // Ponteiro de ponteiro que aponta para inteiro.
    float *p3; // Ponteiro para float.
```

A relação entre ponteiros e endereços pode ser observada no exemplo a seguir.

```c
    int i; int *p;
    i = 1234; p = &i;
    printf("*p = %d\n", *p);                // Imprime o valor de i.
                                            // Output: *p = 1234
    printf("&i = p = %ld\n", (long int)p);  // Imprime o endereço de i.
                                            // &i = p = 140723065261676
    printf("&i = p = %p\n", (void *)p);     // Imprime o endereço (hex) de i.
                                            // &i = p = 0x7ffca4510e6c
    printf("&p = %p\n", (void *)&p);        // Imprime o endereço do ponteiro p.
                                            // &p = 0x7ffca4510e70
```

### Aplicações

```c
void troca(int *i, int *j)
{
    int temp = *i; // Variável temporária recebe o valor apontado por i.
    *i = *j; // Endereço apontado por i recebe o valor apontado por j.
    *j = temp; // Endereço apontado por j recebe o valor temp.
}
```

### Exercícios

1. Um ponteiro pode ser usado para dizer a uma função onde ela deve depositar o resultado de seus cálculos. Escreva uma função hm que converta minutos em horas-e-minutos. A função recebe um inteiro mnts e os endereços de duas variáveis inteiras, digamos h e m, e atribui valores a essas variáveis de modo que m seja menor que 60 e que 60*h + m seja igual a mnts. Escreva também uma função main que use a função hm.

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    void hm(int minutos, int *h, int*m)
    {
        *h = minutos / 60;
        *m = minutos - *h * 60;
    }

    int main(void)
    {
        int minutos = 210;
        int h, m;

        hm(210, &h, &m);
        printf("hh:mm = %02d:%02d\n", h, m); // hh:mm = 03:30

        return EXIT_SUCCESS;
    } 
    ```

2. Escreva uma função mm que receba um vetor inteiro `v[0..n-1]` e os endereços de duas variáveis inteiras, digamos min e max, e deposite nessas variáveis o valor de um elemento mínimo e o valor de um elemento máximo do vetor.  Escreva também uma função main que use a função mm.

    ```c
    #include <stdio.h>
    #include <stdlib.h>


    void mm(int *v, int n, int *minimo, int *maximo)
    {
        int min = v[0];
        int max = v[0];
        for (int j = 0; j < n; j++)
        {
            if (v[j] > max)
                max = v[j];
            if (v[j] < min)
                min = v[j];
        }
        *minimo = min;
        *maximo = max;
    }

    int main(void)
    {
        int v[] = {-10, 5, -20, 43, 217897, 123};
        int min, max;

        mm(v, 6, &min, &max);
        printf("min: %d, max: %d\n", min, max); // min: -20, max: 217897
        return EXIT_SUCCESS;
    }
    ```

## Aritmética de Endereços

Os elementos de um vetor são armazenados em bytes consecutivos da memória do computador, para facilitar o acesso, já que acessar uma determinada posição de um vetor tem complexidade $O(1)$. Se cada elemento de um vetor ocupa s bytes na memória, a diferença entre os endereços de dois elementos consecutivos é de s bytes. Por exemplo, caso o v[0] esteja no endereço 1000 de memória, o v[10] estará na posição 1040, já que cada posição do vetor ocupa 4 bytes na memória.

Exemplo em código:

```c
    int tamanho = 10;
    int *v = malloc(tamanho * sizeof(int)); // Alocamos 10 posições consecutivas na memória para . 

    for (int i = 0; i < tamanho; i++)
    {
        if (i % 2 == 0)
            *(v + i) = 4; // O endereço apontado por (v+i) recebe 4.
        else
            v[i] = 7; // O endereço apontado por (v+i) recebe 7.
    }
    printf("[");
    for (int i = 0; i < tamanho - 1; i++)
    {
        printf("%d, ", v[i]);
    }
    printf("%d]\n", v[tamanho - 1]); // [4, 7, 4, 7, 4, 7, 4, 7, 4, 7]

```

### Referências

[1] Material sobre Ponteiros, do Professor Paulo Feofiloff, disponível no [link](https://www.ime.usp.br/~pf/algoritmos/aulas/pont.html).
