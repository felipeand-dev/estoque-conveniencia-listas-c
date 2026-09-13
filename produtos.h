#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct
{
  int id;
  char nome[51];
  int quantidade;
  float preco;
} Produto;

Produto criarProduto(int id);
void exibirProduto(const Produto *produto);
void atualizarQuantidade(Produto *produto, int quantidade);

#endif
