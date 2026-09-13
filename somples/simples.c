#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simples.h"

void menu_list(void)
{
  printf("\n");
  printf("========================================\n");
  printf("          GERENCIAR PERECIVEIS\n");
  printf("========================================\n");
  printf("1. Inserir produto no inicio\n");
  printf("2. Inserir produto no fim\n");
  printf("3. Remover produto do inicio\n");
  printf("4. Remover produto do fim\n");
  printf("5. Remover produto por ID\n");
  printf("6. Buscar produto por nome\n");
  printf("7. Atualizar quantidade por ID\n");
  printf("8. Exibir todos os produtos\n");
  printf("9. Contar produtos\n");
  printf("10. Esvaziar lista\n");
  printf("0. Voltar\n");
  printf("========================================\n");
}

int inserirInicio(No **lista, Produto produto)
{
  No *novo = malloc(sizeof(No));

  if (novo == NULL)
  {
    printf("Falha na alocacao de memoria.\n");
    return 1;
  }

  novo->produto = produto;
  novo->proximo = *lista;
  *lista = novo;

  return 0;
}

int inserirFim(No **lista, Produto produto)
{
  No *novo = malloc(sizeof(No));
  No *auxiliar = *lista;

  if (novo == NULL)
  {
    printf("Falha na alocacao de memoria.\n");
    return 1;
  }

  novo->produto = produto;
  novo->proximo = NULL;

  if (*lista == NULL)
  {
    *lista = novo;
    return 0;
  }

  while (auxiliar->proximo != NULL)
  {
    auxiliar = auxiliar->proximo;
  }

  auxiliar->proximo = novo;
  return 0;
}

int removerInicio(No **lista)
{
  No *auxiliar;

  if (*lista == NULL)
  {
    printf("A lista esta vazia.\n");
    return 1;
  }

  auxiliar = *lista;
  *lista = (*lista)->proximo;
  free(auxiliar);

  printf("Produto removido com sucesso.\n");
  return 0;
}

int removerFim(No **lista)
{
  No *auxiliar = *lista;
  No *anterior = NULL;

  if (*lista == NULL)
  {
    printf("A lista esta vazia.\n");
    return 1;
  }

  while (auxiliar->proximo != NULL)
  {
    anterior = auxiliar;
    auxiliar = auxiliar->proximo;
  }

  if (anterior == NULL)
  {
    *lista = NULL;
  }
  else
  {
    anterior->proximo = NULL;
  }

  free(auxiliar);
  printf("Produto removido com sucesso.\n");
  return 0;
}

int removerPorId(No **lista, int id)
{
  No *auxiliar = *lista;
  No *anterior = NULL;

  while (auxiliar != NULL && auxiliar->produto.id != id)
  {
    anterior = auxiliar;
    auxiliar = auxiliar->proximo;
  }

  if (auxiliar == NULL)
  {
    printf("Produto nao encontrado.\n");
    return 1;
  }

  if (anterior == NULL)
  {
    *lista = auxiliar->proximo;
  }
  else
  {
    anterior->proximo = auxiliar->proximo;
  }

  free(auxiliar);
  printf("Produto removido com sucesso.\n");
  return 0;
}

void buscarPorNome(No *lista, char nome[])
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

int atualizarPorId(No *lista, int id, int quantidade)
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

void exibirLista(No *lista)
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

int contarProdutos(No *lista)
{
  int quantidade = 0;

  while (lista != NULL)
  {
    quantidade++;
    lista = lista->proximo;
  }

  return quantidade;
}

void esvaziarLista(No **lista)
{
  No *auxiliar;

  while (*lista != NULL)
  {
    auxiliar = *lista;
    *lista = (*lista)->proximo;
    free(auxiliar);
  }
}

int menu_simples(No **lista, int *proximo_id)
{
  int select = 0;

  do
  {
    menu_list();
    printf("Escolha uma opcao: ");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
    {
      Produto produto = criarProduto(*proximo_id);
      if (inserirInicio(lista, produto) == 0)
      {
        (*proximo_id)++;
        printf("Produto adicionado com sucesso.\n");
      }
    }
    break;
    case 2:
    {
      Produto produto = criarProduto(*proximo_id);
      if (inserirFim(lista, produto) == 0)
      {
        (*proximo_id)++;
        printf("Produto adicionado com sucesso.\n");
      }
    }
    break;
    case 3:
      removerInicio(lista);
      break;
    case 4:
      removerFim(lista);
      break;
    case 5:
    {
      int id = 0;
      printf("Digite o ID do produto: ");
      scanf("%d", &id);
      removerPorId(lista, id);
    }
    break;
    case 6:
    {
      char nome[51];
      printf("Digite o nome ou parte do nome: ");
      scanf(" %50[^\n]", nome);
      buscarPorNome(*lista, nome);
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
      atualizarPorId(*lista, id, quantidade);
    }
    break;
    case 8:
      exibirLista(*lista);
      break;
    case 9:
      printf("Quantidade de produtos: %d\n", contarProdutos(*lista));
      break;
    case 10:
      esvaziarLista(lista);
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
