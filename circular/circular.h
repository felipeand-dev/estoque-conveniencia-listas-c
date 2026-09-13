#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "../produtos.h"

typedef struct NoCircular
{
  Produto produto;
  struct NoCircular *proximo;
} NoCircular;

int menu_circular(NoCircular **lista, int *proximo_id);
int inserirInicioCircular(NoCircular **lista, Produto produto);
int inserirFimCircular(NoCircular **lista, Produto produto);
int removerInicioCircular(NoCircular **lista);
int removerFimCircular(NoCircular **lista);
int removerPorIdCircular(NoCircular **lista, int id);
void buscarPorNomeCircular(NoCircular *lista, char nome[]);
int atualizarPorIdCircular(NoCircular *lista, int id, int quantidade);
void exibirListaCircular(NoCircular *lista);
int contarProdutosCircular(NoCircular *lista);
void esvaziarListaCircular(NoCircular **lista);

#endif
