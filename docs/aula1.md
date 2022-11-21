---
title: EDA1 - Aula 1
author: "Nicolas Chagas Souza"
date: 31/10/2022
geometry: left=2cm,right=2cm,top=1cm,bottom=2cm
output: pdf_document
---

## Revisando

Uma memória é um arranjado sequencial de espaços de 1 byte endereçados.

- Ponteiro: é um tipo especial que armazena endereços de memória.

> Por que existem ponteiros?
>
> Eles existem para que seja possível operar entre ponteiros.

O vetor ocupa posições sequenciais na memória para facilitar o acesso, já que, por exemplo, acessar a posição v[x] de um vetor tem complexidade O(1). Caso o v[0] esteja no endereço 1000 de memória, o v[10] estará na posição 1040, já que cada posição do vetor ocupa 4 bytes na memória.

Aritmética de ponteiros:

```c
    v[i] = v + i*sizeof(tipo de v)
    int *ptr;
    ptr + 10 => ptr + 10 * sizeof(tipo ptr)
```

- Para escrever na memória, utilizamos a seguinte sintaxe:

```c
int *prt;
*ptr = 10; // Atribui o valor 10 ao espaço de memória para o qual ptr aponta. 
```

- Ler

```c
    printf("%d\n", *ptr);
```

## NULL

O NULL é uma constante de valor 0 e é armazenada em uma posição pré-fixada na memória.
