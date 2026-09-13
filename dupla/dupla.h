#ifndef DUPLA_H
#define DUPLA_H

#include "../produtos.h"

typedef struct NoDupla
{
  Produto produto;
  struct NoDupla *anterior;
  struct NoDupla *proximo;
} NoDupla;

int menu_dupla(NoDupla **lista, int *proximo_id);
int inserirInicioDupla(NoDupla **lista, Produto produto);
int inserirFimDupla(NoDupla **lista, Produto produto);
int removerInicioDupla(NoDupla **lista);
int removerFimDupla(NoDupla **lista);
int removerPorIdDupla(NoDupla **lista, int id);
void buscarPorNomeDupla(NoDupla *lista, char nome[]);
int atualizarPorIdDupla(NoDupla *lista, int id, int quantidade);
void exibirListaDupla(NoDupla *lista);
void exibirReverso(NoDupla *lista);
int contarProdutosDupla(NoDupla *lista);
void esvaziarListaDupla(NoDupla **lista);

#endif
