#include <stdio.h>
#include "somples/simples.h"
#include "dupla/dupla.h"
#include "circular/circular.h"

int main()
{
  int select = 0;
  int proximo_id = 1;
  No *pereciveis = NULL;
  NoDupla *nao_pereciveis = NULL;
  NoCircular *promocoes = NULL;

  do
  {
    printf("\n========================================\n");
    printf("          ESTOQUE DA LOJA\n");
    printf("========================================\n");
    printf("1. Gerenciar Pereciveis (Simples)\n");
    printf("2. Gerenciar Nao Pereciveis (Dupla)\n");
    printf("3. Gerenciar Promocoes (Circular)\n");
    printf("0. Sair\n");
    printf("========================================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
      menu_simples(&pereciveis, &proximo_id);
      break;
    case 2:
      menu_dupla(&nao_pereciveis, &proximo_id);
      break;
    case 3:
      menu_circular(&promocoes, &proximo_id);
      break;
    case 0:
      printf("Encerrando programa...\n");
      break;
    default:
      printf("Opcao invalida.\n");
      break;
    }
  } while (select != 0);

  esvaziarLista(&pereciveis);
  esvaziarListaDupla(&nao_pereciveis);
  esvaziarListaCircular(&promocoes);

  return 0;
}
