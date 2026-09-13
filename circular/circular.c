#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular.h"

void menu_circular_list(void)
{
  printf("\n");
  printf("========================================\n");
  printf("         GERENCIAR PROMOCOES\n");
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

int inserirInicioCircular(NoCircular **lista, Produto produto)
{
  NoCircular *novo = malloc(sizeof(NoCircular));
  NoCircular *ultimo;

  if (novo == NULL)
  {
    printf("Falha na alocacao de memoria.\n");
    return 1;
  }

  novo->produto = produto;

  if (*lista == NULL)
  {
    novo->proximo = novo;
    *lista = novo;
    return 0;
  }

  ultimo = *lista;
  while (ultimo->proximo != *lista)
  {
    ultimo = ultimo->proximo;
  }

  novo->proximo = *lista;
  ultimo->proximo = novo;
  *lista = novo;
  return 0;
}

int inserirFimCircular(NoCircular **lista, Produto produto)
{
  NoCircular *novo = malloc(sizeof(NoCircular));
  NoCircular *ultimo;

  if (novo == NULL)
  {
    printf("Falha na alocacao de memoria.\n");
    return 1;
  }

  novo->produto = produto;

  if (*lista == NULL)
  {
    novo->proximo = novo;
    *lista = novo;
    return 0;
  }

  ultimo = *lista;
  while (ultimo->proximo != *lista)
  {
    ultimo = ultimo->proximo;
  }

  novo->proximo = *lista;
  ultimo->proximo = novo;
  return 0;
}

int removerInicioCircular(NoCircular **lista)
{
  NoCircular *ultimo;
  NoCircular *auxiliar;

  if (*lista == NULL)
  {
    printf("A lista esta vazia.\n");
    return 1;
  }

  auxiliar = *lista;

  if (auxiliar->proximo == auxiliar)
  {
    *lista = NULL;
  }
  else
  {
    ultimo = auxiliar;
    while (ultimo->proximo != *lista)
    {
      ultimo = ultimo->proximo;
    }

    *lista = auxiliar->proximo;
    ultimo->proximo = *lista;
  }

  free(auxiliar);
  printf("Produto removido com sucesso.\n");
  return 0;
}

int removerFimCircular(NoCircular **lista)
{
  NoCircular *anterior = NULL;
  NoCircular *auxiliar = *lista;

  if (*lista == NULL)
  {
    printf("A lista esta vazia.\n");
    return 1;
  }

  while (auxiliar->proximo != *lista)
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
    anterior->proximo = *lista;
  }

  free(auxiliar);
  printf("Produto removido com sucesso.\n");
  return 0;
}

int removerPorIdCircular(NoCircular **lista, int id)
{
  NoCircular *anterior = NULL;
  NoCircular *auxiliar = *lista;

  if (*lista == NULL)
  {
    printf("A lista esta vazia.\n");
    return 1;
  }

  do
  {
    if (auxiliar->produto.id == id)
    {
      if (auxiliar->proximo == auxiliar)
      {
        *lista = NULL;
      }
      else
      {
        if (anterior == NULL)
        {
          NoCircular *ultimo = auxiliar;
          while (ultimo->proximo != *lista)
          {
            ultimo = ultimo->proximo;
          }
          *lista = auxiliar->proximo;
          ultimo->proximo = *lista;
        }
        else
        {
          anterior->proximo = auxiliar->proximo;
        }
      }

      free(auxiliar);
      printf("Produto removido com sucesso.\n");
      return 0;
    }

    anterior = auxiliar;
    auxiliar = auxiliar->proximo;
  } while (auxiliar != *lista);

  printf("Produto nao encontrado.\n");
  return 1;
}

void buscarPorNomeCircular(NoCircular *lista, char nome[])
{
  NoCircular *auxiliar = lista;
  int encontrou = 0;

  if (lista != NULL)
  {
    do
    {
      if (strstr(auxiliar->produto.nome, nome) != NULL)
      {
        exibirProduto(&auxiliar->produto);
        encontrou = 1;
      }

      auxiliar = auxiliar->proximo;
    } while (auxiliar != lista);
  }

  if (encontrou == 0)
  {
    printf("Nenhum produto encontrado.\n");
  }
}

int atualizarPorIdCircular(NoCircular *lista, int id, int quantidade)
{
  NoCircular *auxiliar = lista;

  if (lista != NULL)
  {
    do
    {
      if (auxiliar->produto.id == id)
      {
        atualizarQuantidade(&auxiliar->produto, quantidade);
        printf("Quantidade atualizada com sucesso.\n");
        return 0;
      }

      auxiliar = auxiliar->proximo;
    } while (auxiliar != lista);
  }

  printf("Produto nao encontrado.\n");
  return 1;
}

void exibirListaCircular(NoCircular *lista)
{
  NoCircular *auxiliar = lista;
  int quantidade = 0;

  if (lista == NULL)
  {
    printf("A lista esta vazia.\n");
    return;
  }

  do
  {
    quantidade++;
    printf("\nProduto %d\n", quantidade);
    exibirProduto(&auxiliar->produto);
    auxiliar = auxiliar->proximo;
  } while (auxiliar != lista);
}

int contarProdutosCircular(NoCircular *lista)
{
  NoCircular *auxiliar = lista;
  int quantidade = 0;

  if (lista != NULL)
  {
    do
    {
      quantidade++;
      auxiliar = auxiliar->proximo;
    } while (auxiliar != lista);
  }

  return quantidade;
}

void esvaziarListaCircular(NoCircular **lista)
{
  NoCircular *auxiliar;
  NoCircular *proximo;

  if (*lista == NULL)
  {
    return;
  }

  auxiliar = (*lista)->proximo;
  while (auxiliar != *lista)
  {
    proximo = auxiliar->proximo;
    free(auxiliar);
    auxiliar = proximo;
  }

  free(*lista);
  *lista = NULL;
}

int menu_circular(NoCircular **lista, int *proximo_id)
{
  int select = 0;

  do
  {
    menu_circular_list();
    printf("Escolha uma opcao: ");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
    {
      Produto produto = criarProduto(*proximo_id);
      if (inserirInicioCircular(lista, produto) == 0)
      {
        (*proximo_id)++;
        printf("Produto adicionado com sucesso.\n");
      }
    }
    break;
    case 2:
    {
      Produto produto = criarProduto(*proximo_id);
      if (inserirFimCircular(lista, produto) == 0)
      {
        (*proximo_id)++;
        printf("Produto adicionado com sucesso.\n");
      }
    }
    break;
    case 3:
      removerInicioCircular(lista);
      break;
    case 4:
      removerFimCircular(lista);
      break;
    case 5:
    {
      int id = 0;
      printf("Digite o ID do produto: ");
      scanf("%d", &id);
      removerPorIdCircular(lista, id);
    }
    break;
    case 6:
    {
      char nome[51];
      printf("Digite o nome ou parte do nome: ");
      scanf(" %50[^\n]", nome);
      buscarPorNomeCircular(*lista, nome);
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
      atualizarPorIdCircular(*lista, id, quantidade);
    }
    break;
    case 8:
      exibirListaCircular(*lista);
      break;
    case 9:
      printf("Quantidade de produtos: %d\n", contarProdutosCircular(*lista));
      break;
    case 10:
      esvaziarListaCircular(lista);
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
