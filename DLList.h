#ifndef _DLLIST_H_
#define _DLLIST_H_

typedef struct _dlnode_{
    struct _dlnode_ *prev;
    struct _dlnode_ *next;
    void *data;
}DLNode;

typedef struct _dllist_{
    DLNode *first;
    DLNode *cur;
}DLList;

typedef struct _cidade_{
  char nome[50];
  int qtd_habitantes;
  float pibPerCapita;
} Cidade;


DLList *dllCreate();

int dllInsertFirst(DLList *l, Cidade *cidade);

void *dllRemoveSpec( DLList *l, void *key, int (*cmp)(void *, void *));

void *dllGetSpec(DLList *l, void *key, int (*cmp)(void *, void *));

char** dllCidadesTotais(DLList *l);

int drainOutList(DLList *l);

int listDestroy(DLList *l);


#endif