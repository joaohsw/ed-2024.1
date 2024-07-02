#ifndef HEAP_H
#define HEAP_H

#define TAMANHO_MAX 100

typedef struct {
    int dados[TAMANHO_MAX];
    int tamanho;
} HeapBinaria;

void inicializar_heap(HeapBinaria *heap);
void inserir(HeapBinaria *heap, int valor);
int remover_raiz(HeapBinaria *heap);
void imprimir_heap(HeapBinaria *heap);

#endif
