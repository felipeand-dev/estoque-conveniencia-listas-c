#include <stdio.h>
#include "produtos.h"

Produto criarProduto(int id)
{
  Produto produto;

  produto.id = id;

  printf("\n===== CADASTRO DE PRODUTO =====\n");
  printf("ID: %d\n", produto.id);
  printf("Nome: ");
  scanf(" %50[^\n]", produto.nome);
  printf("Quantidade: ");
  scanf("%d", &produto.quantidade);
  printf("Preco: R$");
  scanf("%f", &produto.preco);

  return produto;
}

void exibirProduto(const Produto *produto)
{
  printf("\nID: %d\n", produto->id);
  printf("Nome: %s\n", produto->nome);
  printf("Quantidade: %d\n", produto->quantidade);
  printf("Preco: R$ %.2f\n", produto->preco);
}

void atualizarQuantidade(Produto *produto, int quantidade)
{
  produto->quantidade = quantidade;
}
