#include "heap.h"
#include "menu.h"

int main() {
    
    HeapBinaria heap;
    inicializar_heap(&heap);
    exibir_menu(&heap);
    
    return 0;
}
