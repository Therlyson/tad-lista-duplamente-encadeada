#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLList.h"

#define TRUE 1
#define FALSE 0

//Nome do aluno: Therlyson Ryan Souza Santos

int cmp(void *a, void *b) {
    Cidade *cidade = (Cidade*)b;
    char *x = (char *)a;
    char *y = cidade->nome;

    if(strcmp(x, y) == 0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int cmp2(void *a, void *b) {
    Cidade *cidade = (Cidade*)b;
    int *x = (int *)a;
    int i = *x;
    int y = cidade->qtd_habitantes;

    if(i == y){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int cmp3(void *a, void *b) {
    Cidade *cidade = (Cidade*)b;
    float *x = (float *)a;
    float i = *x;
    float y = cidade->pibPerCapita;

    if(i == y){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int main(){
    DLList *list = NULL;
    int opcao = 0;
    
    while(1){
        printf("\n\t========= Menu =========\n");
        printf("1 - Criar lista\n");
        printf("2 - Inserir cidade na lista\n");
        printf("3 - Consultar cidade na lista\n");
        printf("4 - Mostrar todas as cidades da lista\n");
        printf("5 - Remover cidade da lista\n");
        printf("6 - Esvaziar lista\n");
        printf("7 - Destruir lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n");


        if(opcao == 1){
            list = dllCreate();
            if(list == NULL){
                printf("ERRO AO CRIAR LISTA");
            }
            else{
                printf("Lista criada com sucesso!\n");
            }
        }

        else if (opcao == 2) {
            Cidade *cidade = (Cidade*)malloc(sizeof(Cidade));
            printf("Digite o nome da cidade: ");
            fgets(cidade->nome, sizeof(cidade->nome), stdin);
            printf("Digite a quantidade de habitantes da cidade: ");
            scanf("%d", &(cidade->qtd_habitantes));
            printf("Digite o PIB per capita da cidade: ");
            scanf("%f", &(cidade->pibPerCapita));
            fflush(stdin);
            int inserindo = dllInsertFirst(list, cidade);
            if (inserindo) {
                printf("Cidade inserida com sucesso!\n");
            } else {
                printf("ERRO AO INSERIR CIDADE\n");
            }   
        }

        else if(opcao == 3){
            int op;
            void *get = NULL;
            printf("1 - CONSULTAR POR NOME\n2 - CONSULTAR POR QUANTIDADE DE HABITANTES\n3 - CONSULTAR POR PIB\nEscolha sua opcao: ");
            scanf("%d", &op);
            fflush(stdin);

            if(op==1){
                char nome[50];
                printf("\nDigite a cidade que deseja consultar: ");
                fgets(nome, sizeof(nome), stdin);
                fflush(stdin);
                get = dllGetSpec(list, nome, cmp);
            }
            else if(op==2){
                int *qtd = (int*)malloc(sizeof(int));  // Alocar memória
                printf("\nDigite a quantidade de habitantes da cidade que deseja consultar: ");
                scanf("%d", qtd);
                get = dllGetSpec(list, qtd, cmp2);
            }
            else if(op==3){
                float *pib = (float*)malloc(sizeof(float));  // Alocar memória
                printf("\nDigite o PIB da cidade que deseja consultar: ");
                scanf("%f", pib);
                get = dllGetSpec(list, pib, cmp3);
            }
            
            Cidade *cidade = (Cidade*)get;                
            if(cidade != NULL){
                printf("\nCidade encontrada:\n");
                printf("Nome da cidade: %s", cidade->nome);
                printf("Quantidade de habitantes: %d\n", cidade->qtd_habitantes);
                printf("Pib per capita: %.2f\n", cidade->pibPerCapita);
            }
            else{
                printf("Cidade nao encontrada.\n");
            }
        }

        else if (opcao == 4) {
            char **cidadesList = dllCidadesTotais(list);

            // Imprimir os nomes
            if(cidadesList != NULL){
                printf("Cidades presentes na lista:\n");
                int i = 0;
                while (cidadesList[i] != NULL) {
                    printf("- %s\n", cidadesList[i]);
                    free(cidadesList[i]);
                    i++;
                }
                free(cidadesList);
            }
            else{
                printf("Nao ha cidades na lista.\n");
            }
            
        }

        else if(opcao == 5){
            int op;
            void *remove = NULL;
            printf("1 - REMOVER POR NOME\n2 - REMOVER POR QUANTIDADE DE HABITANTES\n3 - REMOVER POR PIB\nEscolha sua opcao: ");
            scanf("%d", &op);
            fflush(stdin);

            if(op==1){
                char nome[50];
                printf("\nDigite a cidade que deseja remover: ");
                fgets(nome, sizeof(nome), stdin);
                fflush(stdin);
                remove = dllRemoveSpec(list, nome, cmp);
            }
            else if(op==2){
                int *qtd = (int*)malloc(sizeof(int)); 
                printf("\nDigite a quantidade de habitantes da cidade que deseja remover: ");
                scanf("%d", qtd);
                remove = dllRemoveSpec(list, qtd, cmp2);
            }
            else if(op==3){
                float *pib = (float*)malloc(sizeof(float)); 
                printf("\nDigite o PIB da cidade que deseja consultar: ");
                scanf("%f", pib);
                remove = dllRemoveSpec(list, pib, cmp3);
            }

            Cidade *cidade = (Cidade*)remove;
            if(cidade != NULL){
                printf("\nCidade removida com sucesso!!\n");
                printf("  Nome da cidade: %s", cidade->nome);
                printf("  Quantidade de habitantes: %d\n", cidade->qtd_habitantes);
                printf("  Pib per capita: %.2f\n", cidade->pibPerCapita);
                free(cidade);
            }
            else{
                printf("Cidade nao encontrada.\n");
            }
        }

        else if(opcao == 6){
            int drain = drainOutList(list);
            if(drain == FALSE){
                printf("ERRO AO ESVAZIAR LISTA!\n");
            }
            else{
                printf("Lista vazia!\n");
            }
        }

        else if(opcao == 7){  //corrigir essa função pois da erro ao destruir e tentar fazer outras coisas depois
            int destroy = listDestroy(list);
            if(destroy == TRUE){
                printf("LISTA DESTRUIDA!\n");
                list = NULL;
            }
            else{
                printf("ERRO AO DESTRUIR LISTA, ESVAZIE PRIMEIRO!\n");
            }
            
        }

        else if(opcao == 0){
            printf("PROGRAMA ENCERRADO COM SUCESSO!\n");
            break;
        }
        
        else{
            printf("Voce digitou uma opcao invalida!\n");
        }
    } 
}