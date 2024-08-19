#ifndef MENU_H
#define MENU_H

#include "estruturas.h"

void menu_principal();
Individuo* inserir_na_lista(Individuo *head, Individuo *nova_pessoa);
NoFila* inserir_na_fila(NoFila *head, Individuo *pessoa);
NoABB* inserir_na_abb(NoABB *raiz, Individuo *pessoa);
void imprimir_lista(Individuo *head);
void imprimir_fila(NoFila *head);
void imprimir_abb(NoABB *raiz);

#endif
