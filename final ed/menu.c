#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "menu.h"


void menu_principal() {
    Individuo *lista = NULL;
    NoFila *fila = NULL;
    NoABB *abb = NULL;

    int input;

    while(1) {
        printf("\n1. Registrar pessoa\n");
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
                fila = inserir_na_fila_por_prioridade(fila, nova_pessoa);
                abb = inserir_na_abb(abb, nova_pessoa);
                break;
            }
            case 2:
                printf("\n--- Lista Simplesmente Encadeada ---\n");
                imprimir_lista(lista);
                break;
            case 3:
                printf("\n--- Fila Ordenada por Prioridade ---\n");
                imprimir_fila(fila);
                break;
            case 4:
                printf("\n--- Árvore Binária de Busca (ABB) ---\n");
                imprimir_abb(abb);
                break;
            case 5:
                exit(0);
            default:
                printf("Opcao invalida\n");
        }
    }
}
