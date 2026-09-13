#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dupla.h"

void menu_dupla_list(void)
{
  printf("\n");
  printf("========================================\n");
  printf("       GERENCIAR NAO PERECIVEIS\n");
  printf("========================================\n");
  printf("1. Inserir produto no inicio\n");
  printf("2. Inserir produto no fim\n");
  printf("3. Remover produto do inicio\n");
  printf("4. Remover produto do fim\n");
  printf("5. Remover produto por ID\n");
  printf("6. Buscar produto por nome\n");
  printf("7. Atualizar quantidade por ID\n");
  printf("8. Exibir todos os produtos\n");
  printf("9. Exibir produtos em reverso\n");
  printf("10. Contar produtos\n");
  printf("11. Esvaziar lista\n");
  printf("0. Voltar\n");
  printf("========================================\n");
}

int inserirInicioDupla(NoDupla **lista, Produto produto)
{
  NoDupla *novo = malloc(sizeof(NoDupla));

  if (novo == NULL)
  {
    printf("Falha na alocacao de memoria.\n");
    return 1;
  }

  novo->produto = produto;
  novo->anterior = NULL;
  novo->proximo = *lista;

  if (*lista != NULL)
  {
    (*lista)->anterior = novo;
  }

  *lista = novo;
  return 0;
}

int inserirFimDupla(NoDupla **lista, Produto produto)
{
  NoDupla *novo = malloc(sizeof(NoDupla));
  NoDupla *auxiliar = *lista;

  if (novo == NULL)
  {
    printf("Falha na alocacao de memoria.\n");
    return 1;
  }

  novo->produto = produto;
  novo->proximo = NULL;

  if (*lista == NULL)
  {
    novo->anterior = NULL;
    *lista = novo;
    return 0;
  }

  while (auxiliar->proximo != NULL)
  {
    auxiliar = auxiliar->proximo;
  }

  novo->anterior = auxiliar;
  auxiliar->proximo = novo;
  return 0;
}

int removerInicioDupla(NoDupla **lista)
{
  NoDupla *auxiliar;

  if (*lista == NULL)
  {
    printf("A lista esta vazia.\n");
    return 1;
  }

  auxiliar = *lista;
  *lista = (*lista)->proximo;

  if (*lista != NULL)
  {
    (*lista)->anterior = NULL;
  }

  free(auxiliar);
  printf("Produto removido com sucesso.\n");
  return 0;
}

int removerFimDupla(NoDupla **lista)
{
  NoDupla *auxiliar = *lista;

  if (*lista == NULL)
  {
    printf("A lista esta vazia.\n");
    return 1;
  }

  while (auxiliar->proximo != NULL)
  {
    auxiliar = auxiliar->proximo;
  }

  if (auxiliar->anterior == NULL)
  {
    *lista = NULL;
  }
  else
  {
    auxiliar->anterior->proximo = NULL;
  }

  free(auxiliar);
  printf("Produto removido com sucesso.\n");
  return 0;
}

int removerPorIdDupla(NoDupla **lista, int id)
{
  NoDupla *auxiliar = *lista;

  while (auxiliar != NULL && auxiliar->produto.id != id)
  {
    auxiliar = auxiliar->proximo;
  }

  if (auxiliar == NULL)
  {
    printf("Produto nao encontrado.\n");
    return 1;
  }

  if (auxiliar->anterior == NULL)
  {
    *lista = auxiliar->proximo;
  }
  else
  {
    auxiliar->anterior->proximo = auxiliar->proximo;
  }

  if (auxiliar->proximo != NULL)
  {
    auxiliar->proximo->anterior = auxiliar->anterior;
  }

  free(auxiliar);
  printf("Produto removido com sucesso.\n");
  return 0;
}

void buscarPorNomeDupla(NoDupla *lista, char nome[])
{
  int encontrou = 0;

  while (lista != NULL)
  {
    if (strstr(lista->produto.nome, nome) != NULL)
    {
      exibirProduto(&lista->produto);
      encontrou = 1;
    }

    lista = lista->proximo;
  }

  if (encontrou == 0)
  {
    printf("Nenhum produto encontrado.\n");
  }
}

int atualizarPorIdDupla(NoDupla *lista, int id, int quantidade)
{
  while (lista != NULL)
  {
    if (lista->produto.id == id)
    {
      atualizarQuantidade(&lista->produto, quantidade);
      printf("Quantidade atualizada com sucesso.\n");
      return 0;
    }

    lista = lista->proximo;
  }

  printf("Produto nao encontrado.\n");
  return 1;
}

void exibirListaDupla(NoDupla *lista)
{
  int quantidade = 0;

  if (lista == NULL)
  {
    printf("A lista esta vazia.\n");
    return;
  }

  while (lista != NULL)
  {
    quantidade++;
    printf("\nProduto %d\n", quantidade);
    exibirProduto(&lista->produto);
    lista = lista->proximo;
  }
}

void exibirReverso(NoDupla *lista)
{
  int quantidade = 0;

  if (lista == NULL)
  {
    printf("A lista esta vazia.\n");
    return;
  }

  while (lista->proximo != NULL)
  {
    lista = lista->proximo;
  }

  while (lista != NULL)
  {
    quantidade++;
    printf("\nProduto %d\n", quantidade);
    exibirProduto(&lista->produto);
    lista = lista->anterior;
  }
}

int contarProdutosDupla(NoDupla *lista)
{
  int quantidade = 0;

  while (lista != NULL)
  {
    quantidade++;
    lista = lista->proximo;
  }

  return quantidade;
}

void esvaziarListaDupla(NoDupla **lista)
{
  NoDupla *auxiliar;

  while (*lista != NULL)
  {
    auxiliar = *lista;
    *lista = (*lista)->proximo;
    free(auxiliar);
  }
}

int menu_dupla(NoDupla **lista, int *proximo_id)
{
  int select = 0;

  do
  {
    menu_dupla_list();
    printf("Escolha uma opcao: ");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
    {
      Produto produto = criarProduto(*proximo_id);
      if (inserirInicioDupla(lista, produto) == 0)
      {
        (*proximo_id)++;
        printf("Produto adicionado com sucesso.\n");
      }
    }
    break;
    case 2:
    {
      Produto produto = criarProduto(*proximo_id);
      if (inserirFimDupla(lista, produto) == 0)
      {
        (*proximo_id)++;
        printf("Produto adicionado com sucesso.\n");
      }
    }
    break;
    case 3:
      removerInicioDupla(lista);
      break;
    case 4:
      removerFimDupla(lista);
      break;
    case 5:
    {
      int id = 0;
      printf("Digite o ID do produto: ");
      scanf("%d", &id);
      removerPorIdDupla(lista, id);
    }
    break;
    case 6:
    {
      char nome[51];
      printf("Digite o nome ou parte do nome: ");
      scanf(" %50[^\n]", nome);
      buscarPorNomeDupla(*lista, nome);
    }
    break;
    case 7:
    {
      int id = 0;
      int quantidade = 0;
      printf("Digite o ID do produto: ");
      scanf("%d", &id);
      printf("Digite a nova quantidade: ");
      scanf("%d", &quantidade);
      atualizarPorIdDupla(*lista, id, quantidade);
    }
    break;
    case 8:
      exibirListaDupla(*lista);
      break;
    case 9:
      exibirReverso(*lista);
      break;
    case 10:
      printf("Quantidade de produtos: %d\n", contarProdutosDupla(*lista));
      break;
    case 11:
      esvaziarListaDupla(lista);
      printf("Lista esvaziada com sucesso.\n");
      break;
    case 0:
      break;
    default:
      printf("Opcao invalida.\n");
      break;
    }
  } while (select != 0);

  return 0;
}
