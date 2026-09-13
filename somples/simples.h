#ifndef SIMPLES_H
#define SIMPLES_H

#include "../produtos.h"

typedef struct No
{
	Produto produto;
	struct No *proximo;
} No;

void menu_list(void);
int menu_simples(No **lista, int *proximo_id);
int inserirInicio(No **lista, Produto produto);
int inserirFim(No **lista, Produto produto);
int removerInicio(No **lista);
int removerFim(No **lista);
int removerPorId(No **lista, int id);
void buscarPorNome(No *lista, char nome[]);
int atualizarPorId(No *lista, int id, int quantidade);
void exibirLista(No *lista);
int contarProdutos(No *lista);
void esvaziarLista(No **lista);

#endif
