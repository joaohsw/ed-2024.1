#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct individuo {
    long int cpf;
    char nome[50];
    int idade;
    int fator_prioridade;
    struct individuo *prox;
} Individuo;

typedef struct no_fila {
    Individuo *pessoa;
    struct no_fila *prox;
} NoFila;

typedef struct no_abb {
    Individuo *pessoa;
    struct no_abb *esq, *dir;
} NoABB;

#endif
