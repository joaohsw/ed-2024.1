#include <stdio.h>
#include "menu.h"

void exibir_menu(HeapBinaria *heap) {
    int escolha, valor;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir Heap\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                printf("Insira o valor: ");
                scanf("%d", &valor);
                inserir(heap, valor);
                break;
            case 2:
                valor = remover_raiz(heap);
                if (valor != -1) {
                    printf("Removido: %d\n", valor);
                }
                break;
            case 3:
                imprimir_heap(heap);
                break;
            case 4:
                return;
            default:
                printf("Opcao invalida!\n");
        }
    }
}
