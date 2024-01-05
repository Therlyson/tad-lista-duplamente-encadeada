# Trabalho de Implementação 03 - TAD Lista Duplamente Encadeada - Estrutura de Dados 1

## IDE UTILIZADA: Visual Studio Code

## Aluno: Therlyson Ryan Souza Santos

## TAD - Introdução

Este código em C implementa um Tipo Abstrato de Dados (TAD) para uma lista duplamente encadeada, focada na manipulação de uma coleção de cidades. 

O código é organizado em três arquivos principais: `DLList.h`, `DLList.c` e `main.c`

Arquivo excutável: app.exe

## Funcionalidades do TAD Lista Duplamente Encadeada

1. **`dllCreate`**
   - *Descrição*: Cria uma nova lista duplamente encadeada.
   - *Retorno*: Retorna um ponteiro para a lista criada ou NULL em caso de falha.

2. **`dllInsertFirst`**
   - *Descrição*: Insere uma cidade no início da lista.
   - *Parâmetros*:
     - `l`: Ponteiro para a lista.
     - `cidade`: Ponteiro para a estrutura Cidade a ser inserida.
   - *Retorno*: Retorna TRUE se a operação foi bem-sucedida, FALSE caso contrário.

3. **`dllRemoveSpec`**
   - *Descrição*: Remove uma cidade específica da lista com base no nome.
   - *Parâmetros*:
     - `l`: Ponteiro para a lista.
     - `nome`: Nome da cidade a ser removida.
     - `cmp`: Função de comparação para encontrar a cidade na lista.
   - *Retorno*: Retorna um ponteiro para a cidade removida ou NULL se não encontrada.

4. **`dllGetSpec`**
   - *Descrição*: Obtém uma cidade específica da lista com base no nome.
   - *Parâmetros*:
     - `l`: Ponteiro para a lista.
     - `nome`: Nome da cidade a ser consultada.
     - `cmp`: Função de comparação para encontrar a cidade na lista.
   - *Retorno*: Retorna um ponteiro para a cidade encontrada ou NULL se não encontrada.

5. **`dllCidadesTotais`**
   - *Descrição*: Obtém uma lista de todos os nomes de cidades presentes na lista.
   - *Parâmetros*:
     - `l`: Ponteiro para a lista.
   - *Retorno*: Retorna um array de strings com os nomes das cidades ou NULL se a lista estiver vazia.

6. **`drainOutList`**
   - *Descrição*: Esvazia a lista, liberando a memória associada a cada cidade.
   - *Parâmetros*:
     - `l`: Ponteiro para a lista.
   - *Retorno*: Retorna TRUE se a operação foi bem-sucedida (lista esvaziada) ou FALSE caso contrário.

7. **`listDestroy`**
   - *Descrição*: Libera a memória associada à lista, incluindo suas cidades.
   - *Parâmetros*:
     - `l`: Ponteiro para a lista.
   - *Retorno*: Retorna TRUE se a operação foi bem-sucedida (lista destruída) ou FALSE caso contrário.


## Como executar o programa no Visual Studio Code:

1. Para o programa ser executado, basta criar uma pasta no PC e adicionar todos os arquivos na mesma pasta (`main.c`, `DLList.c`, `DLList.h`, `DLList.o`, `app.exe`)

2. Após isso abre o Visual Studio Code -> File -> open Folder, abri a pasta que tá os arquivos.

3. Logo após basta ir no Terminal -> new terminal, no terminal digite: `./app`

4. Pronto, agora o programa está funcionando corretamente.

5. Compilação: Se deseja compilar o programa, utilize o seguinte comando no terminal: `gcc -o app DLList.c main.c`

6. Logo após é só executar novamente utilizando: `./app`


## Estrutura Produto

A estrutura Cidade é definida como:
```c
typedef struct _cidade_{
  char nome[50];
  int qtd_habitantes;
  float pibPerCapita;
} Cidade;