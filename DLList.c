#include "DLList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

DLList *dllCreate(){
    DLList *l;
    l = (DLList*)malloc(sizeof(DLList));
    if(l!=NULL){
        l->first = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}

int dllInsertFirst(DLList *l, Cidade *cidade){
    DLNode *newnode, *next;
    if(l!=NULL && cidade != NULL){
        newnode = (DLNode*)malloc(sizeof(DLNode));
        if(newnode != NULL){
            newnode->data = cidade;
            newnode->prev = NULL;
            newnode->next = l->first;
            next = l->first;
            if(next != NULL){
               next->prev = newnode;
            }
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *)){
    DLNode *newnode, *spec, *next, *prev;
    void *data;
    int stat;
    if(l!=NULL){
        if(l->first != NULL){
            spec = l->first;
            stat = cmp(key, spec->data);
            while(stat != TRUE && spec->next != NULL){
                spec = spec->next;
                stat = cmp(key, spec->data);
            }

            if(stat==TRUE){
                data = spec->data;
                prev = spec->prev;
                next = spec->next;

                if(next != NULL){
                    next->prev = prev;
                }
                if(prev!=NULL){
                    prev->next = next;
                }
                else{
                    l->first=next;
                }
                free(spec);
                return data;
            }
        }
    }
    return NULL;
}


void *dllGetSpec(DLList *l, void *key,int (*cmp)(void *, void *)){
    DLNode *newnode, *spec, *next, *prev;
    void *data;
    int stat;
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            stat = cmp(key, spec->data);
            while(stat != TRUE && spec->next != NULL){
                spec = spec->next;
                stat = cmp(key, spec->data);
            }

            if(stat==TRUE){
                if(stat==TRUE){
                    return spec->data;
                }
            }
        }
    }
    return NULL;
}


char** dllCidadesTotais(DLList *l){
    DLNode *spec;
    char *cidades;
    int cont = 0;
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            while(spec != NULL){
                cont++;
                spec = spec->next;
            }

            char **cidades = (char**)malloc(sizeof(char*)*(cont+1)); //necessário para na última posição colocar null
            if(cidades != NULL){
                spec = l->first;
                for(int i=0; i<cont; i++){
                    Cidade *city = (Cidade*)spec->data;
                    cidades[i] = strdup(city->nome);
                    spec = spec->next;
                }
                cidades[cont] = NULL;
                return cidades;
            }
        }
    }
    return NULL;
}


int drainOutList(DLList *l){
    DLNode *spec, *next;
    if(l!=NULL){
        if(l->first != NULL){
            spec = l->first;
            while(spec != NULL){
                next = spec->next;
                free(spec->data);
                free(spec);
                spec = next;
            }
            l->first = NULL;
            return TRUE;
        }
    }
    return FALSE;
}


int listDestroy(DLList *l){
    if(l != NULL){
        if(l->first == NULL){
            free(l);    
            return TRUE;
        }
    }
    return FALSE;
}