#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

void menu_principal() {

    Individuo *lista = NULL;
    NoFila *fila = NULL;
    NoABB *abb = NULL;

    int N;

    printf("Informe o numero de pessoas a serem inseridas: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {

        Individuo *nova_pessoa = (Individuo*) malloc(sizeof(Individuo));
        nova_pessoa->prox = NULL;

        printf("\n> Informe os dados da pessoa %d\n", i+1);

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


    }

    int input;

    do {
        printf("\n> Digite 1 para imprimir a lista simplesmente encadeada: ");
        scanf("%d", &input);
    } while (input != 1);

    printf("\n> Lista Simplesmente Encadeada\n");
    imprimir_lista(lista);

    input = 0;

    do {
        printf("\n> Digite 1 para imprimir a fila ordenada por prioridade: ");
        scanf("%d", &input);
    } while (input != 1);

    printf("\n> Fila Ordenada por Prioridade\n");
    imprimir_fila(fila);

    input = 0;

    do {
        printf("\n> Digite 1 para imprimir a arvore binaria de busca (ABB): ");
        scanf("%d", &input);
    } while (input != 1);

    printf("\n> Arvore Binaria de Busca (ABB)\n");
    imprimir_abb(abb);

    input = 0;

    do {
        printf("\n> Digite 1 para encerrar o programa: ");
        scanf("%d", &input);
    } while (input != 1);

    liberar_lista(lista);
    liberar_fila(fila);
    liberar_abb(abb);

}
