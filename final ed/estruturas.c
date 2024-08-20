#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"


Individuo* inserir_na_lista(Individuo *head, Individuo *nova_pessoa) {
    if (head == NULL) {
        return nova_pessoa;
    } else {
        Individuo *atual = head;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = nova_pessoa;
        return head;
    }
}

NoFila* inserir_na_fila_por_prioridade(NoFila *head, Individuo *pessoa) {
    NoFila *novo_no = (NoFila*) malloc(sizeof(NoFila));
    novo_no->pessoa = pessoa;
    novo_no->prox = NULL;

    if (head == NULL || pessoa->fator_prioridade < head->pessoa->fator_prioridade) {
        novo_no->prox = head;
        return novo_no;
    } else {
        NoFila *atual = head;
        while (atual->prox != NULL && atual->prox->pessoa->fator_prioridade <= pessoa->fator_prioridade) {
            atual = atual->prox;
        }
        novo_no->prox = atual->prox;
        atual->prox = novo_no;
        return head;
    }
}

NoABB* inserir_na_abb(NoABB *raiz, Individuo *pessoa) {
    if (raiz == NULL) {
        NoABB *novo_no = (NoABB*) malloc(sizeof(NoABB));
        novo_no->pessoa = pessoa;
        novo_no->esq = novo_no->dir = NULL;
        return novo_no;
    }

    if (pessoa->cpf < raiz->pessoa->cpf) {
        raiz->esq = inserir_na_abb(raiz->esq, pessoa);
    } else {
        raiz->dir = inserir_na_abb(raiz->dir, pessoa);
    }

    return raiz;
}

void imprimir_lista(Individuo *head) {
    Individuo *atual = head;
    while (atual != NULL) {
        printf("CPF: %ld, Nome: %s, Idade: %d, Prioridade: %d\n",
               atual->cpf, atual->nome, atual->idade, atual->fator_prioridade);
        atual = atual->prox;
    }
}

void imprimir_fila(NoFila *head) {
    NoFila *atual = head;
    while (atual != NULL) {
        printf("CPF: %ld, Nome: %s, Idade: %d, Prioridade: %d\n",
               atual->pessoa->cpf, atual->pessoa->nome, atual->pessoa->idade, atual->pessoa->fator_prioridade);
        atual = atual->prox;
    }
}

void imprimir_abb(NoABB *raiz) {
    if (raiz != NULL) {
        imprimir_abb(raiz->esq);
        printf("CPF: %ld, Nome: %s, Idade: %d, Prioridade: %d\n",
               raiz->pessoa->cpf, raiz->pessoa->nome, raiz->pessoa->idade, raiz->pessoa->fator_prioridade);
        imprimir_abb(raiz->dir);
    }
}
