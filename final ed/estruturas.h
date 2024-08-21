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


Individuo* inserir_na_lista(Individuo *head, Individuo *nova_pessoa);
NoFila* inserir_na_fila_por_prioridade(NoFila *head, Individuo *pessoa);
NoABB* inserir_na_abb(NoABB *raiz, Individuo *pessoa);
void imprimir_lista(Individuo *head);
void imprimir_fila(NoFila *head);
void imprimir_abb(NoABB *raiz);
void liberar_lista(Individuo *head);
void liberar_fila(NoFila *head);
void liberar_abb(NoABB *raiz);

#endif
