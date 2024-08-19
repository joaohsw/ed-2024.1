#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "menu.h"

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

NoFila* inserir_na_fila(NoFila *head, Individuo *pessoa) {
    NoFila *novo_no = (NoFila*) malloc(sizeof(NoFila));
    novo_no->pessoa = pessoa;
    novo_no->prox = NULL;

    if (head == NULL) {
        return novo_no;
    } else {
        NoFila *atual = head;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
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

void menu_principal() {
    Individuo *lista = NULL;
    NoFila *fila = NULL;
    NoABB *abb = NULL;

    int input;

    while(1) {
        printf("1. Registrar pessoa\n");
        printf("2. Imprimir lista\n");
        printf("3. Imprimir fila\n");
        printf("4. Imprimir ABB\n");
        printf("5. Sair\n");
        printf("Informe a opcao: ");
        scanf("%d", &input);

        switch(input) {
            case 1: {
                Individuo *nova_pessoa = (Individuo*) malloc(sizeof(Individuo));
                nova_pessoa->prox = NULL;

                printf("Informe o CPF: ");
                scanf("%ld", &nova_pessoa->cpf);
                printf("Informe o nome: ");
                scanf(" %[^\n]s", nova_pessoa->nome);
                printf("Informe a idade: ");
                scanf("%d", &nova_pessoa->idade);
                printf("Informe o fator de prioridade (1-5): ");
                scanf("%d", &nova_pessoa->fator_prioridade);

                lista = inserir_na_lista(lista, nova_pessoa);
                fila = inserir_na_fila(fila, nova_pessoa);
                abb = inserir_na_abb(abb, nova_pessoa);
                break;
            }
            case 2:
                imprimir_lista(lista);
                break;
            case 3:
                imprimir_fila(fila);
                break;
            case 4:
                imprimir_abb(abb);
                break;
            case 5:
                exit(0);
            default:
                printf("Opcao invalida\n");
        }
    }
}
