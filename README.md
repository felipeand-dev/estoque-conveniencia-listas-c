# Sistema de Estoque em C

Aplicacao de linha de comando para gerenciamento de estoque de uma loja de conveniencia. O projeto demonstra, na pratica, como diferentes tipos de listas encadeadas podem ser escolhidos de acordo com a necessidade de cada area do estoque.

Projeto desenvolvido para a disciplina de Estrutura de Dados, com foco em alocacao dinamica, ponteiros, modularizacao e analise de complexidade.

## Visao geral

O sistema organiza os produtos em tres areas:

| Area | Estrutura | Uso no sistema |
| --- | --- | --- |
| Pereciveis | Lista simplesmente encadeada | Produtos com reposicao na ordem de chegada |
| Nao pereciveis | Lista duplamente encadeada | Produtos que podem ser consultados para frente e para tras |
| Promocoes | Lista circular simplesmente encadeada | Produtos organizados em rodizio de ofertas |

Cada produto possui um ID unico, nome, quantidade e preco.

## Funcionalidades

Todas as listas oferecem:

- Insercao no inicio e no fim
- Remocao no inicio, no fim e por ID
- Busca por substring no nome do produto
- Atualizacao de quantidade por ID
- Exibicao dos produtos
- Contagem de elementos
- Esvaziamento com liberacao da memoria
- Mensagens para lista vazia, ID inexistente e opcao invalida

A lista duplamente encadeada tambem oferece exibicao em ordem reversa.

## Organizacao do projeto

```text
.
|-- main.c                 # Menu principal e controle das tres listas
|-- produtos.h             # Estrutura Produto e funcoes compartilhadas
|-- produtos.c
|-- somples/
|   |-- simples.h          # Interface da lista simplesmente encadeada
|   `-- simples.c
|-- dupla/
|   |-- dupla.h            # Interface da lista duplamente encadeada
|   `-- dupla.c
|-- circular/
|   |-- circular.h         # Interface da lista circular
|   `-- circular.c
|-- Makefile
`-- README.md
```

O nome da pasta `somples` foi mantido para preservar a organizacao original do projeto.

## Modelo de dados

```c
typedef struct
{
	int id;
	char nome[51];
	int quantidade;
	float preco;
} Produto;
```

O cadastro limita o nome a 50 caracteres. A validade e opcional na especificacao e, por isso, nao faz parte do cadastro atual.

## Como compilar

### Requisito

- GCC com suporte ao padrao C99
- GNU Make

### Build

```bash
make
```

O executavel `estoque` sera criado na raiz do projeto.

### Executar

```bash
./estoque
```

### Limpar arquivos gerados

```bash
make clean
```

## Analise de complexidade

Na notacao Big-O, `n` representa a quantidade de produtos armazenados. A notacao descreve como o custo de tempo ou memoria cresce conforme a entrada aumenta.

| Classe | Interpretacao |
| --- | --- |
| `O(1)` | Custo constante |
| `O(log n)` | Crescimento logaritmico |
| `O(n)` | Crescimento linear |
| `O(n log n)` | Comum em ordenacoes eficientes |
| `O(n^2)` | Crescimento quadratico |
| `O(2^n)` | Crescimento exponencial |
| `O(n!)` | Crescimento fatorial |

### Operacoes do projeto

| Operacao | Lista simples | Lista dupla | Lista circular |
| --- | ---: | ---: | ---: |
| Inserir no inicio | `O(1)` | `O(1)` | `O(n)` |
| Inserir no fim | `O(n)` | `O(n)` | `O(n)` |
| Remover do inicio | `O(1)` | `O(1)` | `O(n)` |
| Remover do fim | `O(n)` | `O(n)` | `O(n)` |
| Remover por ID | `O(n)` | `O(n)` | `O(n)` |
| Buscar por nome | `O(n)` | `O(n)` | `O(n)` |
| Atualizar por ID | `O(n)` | `O(n)` | `O(n)` |
| Exibir e contar | `O(n)` | `O(n)` | `O(n)` |
| Esvaziar | `O(n)` | `O(n)` | `O(n)` |

Nas listas dupla e circular, seria possivel reduzir algumas operacoes mantendo um ponteiro adicional para o ultimo no. Neste projeto, a implementacao percorre a estrutura ate encontrar esse no, deixando o funcionamento mais simples de acompanhar.

Todas as listas utilizam memoria `O(n)`, pois existe um no alocado dinamicamente para cada produto.

## Decisoes de implementacao

- A estrutura `Produto` e suas funcoes auxiliares ficam em um modulo compartilhado para evitar repetir o cadastro e a exibicao nas tres listas.
- O ID e gerado pelo menu principal e continua crescente mesmo depois que um produto e removido.
- Cada lista possui seu proprio tipo de no e seu proprio modulo, mantendo as regras de ponteiros separadas.
- A memoria e liberada ao esvaziar uma lista e tambem antes do encerramento do programa.
- A busca utiliza `strstr`, permitindo procurar tanto o nome completo quanto parte dele.


## Licenca

Projeto academico desenvolvido para fins educacionais.
