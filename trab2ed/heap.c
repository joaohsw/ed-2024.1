#include <stdio.h>
#include "heap.h"

void inicializar_heap(HeapBinaria *heap) {
    heap->tamanho = 0;
}

void inserir(HeapBinaria *heap, int valor) {
    if (heap->tamanho >= TAMANHO_MAX) {
        printf("Heap cheia!\n");
        return;
    }
    
    heap->dados[heap->tamanho] = valor;
    int i = heap->tamanho;
    heap->tamanho++;
    
    while (i != 0 && heap->dados[(i - 1) / 2] < heap->dados[i]) {
        int temp = heap->dados[i];
        heap->dados[i] = heap->dados[(i - 1) / 2];
        heap->dados[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int remover_raiz(HeapBinaria *heap) {
    if (heap->tamanho <= 0) {
        printf("Heap vazia!\n");
        return -1;
    }
    
    int raiz = heap->dados[0];
    heap->dados[0] = heap->dados[heap->tamanho - 1];
    heap->tamanho--;
    
    int i = 0;
    while (2 * i + 1 < heap->tamanho) {
        int filho_esquerdo = 2 * i + 1;
        int filho_direito = 2 * i + 2;
        int maior = i;
        
        if (filho_esquerdo < heap->tamanho && heap->dados[filho_esquerdo] > heap->dados[maior]) {
            maior = filho_esquerdo;
        }
        
        if (filho_direito < heap->tamanho && heap->dados[filho_direito] > heap->dados[maior]) {
            maior = filho_direito;
        }
        
        if (maior == i) {
            break;
        }
        
        int temp = heap->dados[i];
        heap->dados[i] = heap->dados[maior];
        heap->dados[maior] = temp;
        
        i = maior;
    }
    
    return raiz;
}

void imprimir_heap(HeapBinaria *heap) {
    for (int i = 0; i < heap->tamanho; i++) {
        printf("No: %d ", heap->dados[i]);
        if (2 * i + 1 < heap->tamanho) {
            printf("Filho Esquerdo: %d ", heap->dados[2 * i + 1]);
        } else {
            printf("Filho Esquerdo: NULL ");
        }
        
        if (2 * i + 2 < heap->tamanho) {
            printf("Filho Direito: %d\n", heap->dados[2 * i + 2]);
        } else {
            printf("Filho Direito: NULL\n");
        }
    }
}
