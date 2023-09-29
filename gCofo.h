#ifndef __GCOFO_H_
#define __GCOFO_H_

typedef struct _jogador_
{
    int id;
    char nome[30];
    float salario;
} Jogador;

typedef struct _gcofo_
{
    int numItens;
    int maxItens;
    int cur;
    void **item;
} gCofo;

gCofo *gcofCreate(int max_itens);
int gcofInsert(gCofo *gc, void *item);
void *gcofRemove(gCofo *gc, void *key, int (*cmp)(void *, void *));
void *gcofQuery(gCofo *gc, void *key, int (*cmp)(void *, void *));
void *gcofGetFirst(gCofo *gc);
void *gcofGetNext(gCofo *gc);
int gcofDestroy(gCofo *gc);
int getNumItens(gCofo *gc);

#endif
