// Gabriel Belo Pereira dos Reis
#include <stdio.h>
#include <stdlib.h>
#include "gCofo.h"

#define TRUE 1
#define FALSE 0

gCofo *gcofCreate(int max_itens)
{
    gCofo *gc;
    if (max_itens > 0)
    {
        gc = (gCofo *)malloc(sizeof(gCofo));
        if (gc != NULL)
        {
            gc->item = (void **)malloc(sizeof(void *) * max_itens);
            if (gc->item != NULL)
            {
                gc->numItens = 0;
                gc->maxItens = max_itens;
                gc->cur = -1;
                return gc;
            }
            free(gc);
        }
    }
    return NULL;
}

int gcofDestroy(gCofo *gc)
{
    if (gc != NULL)
    {
        if (gc->numItens == 0)
        {
            free(gc->item);
            free(gc);
            return TRUE;
        }
    }
    return FALSE;
}

int gcofInsert(gCofo *gc, void *item)
{
    if (gc != NULL)
    {
        if (gc->numItens < gc->maxItens)
        {
            gc->item[gc->numItens] = item;
            gc->numItens++;
            return TRUE;
        }
    }
    return FALSE;
}

void *gcofGetFirst(gCofo *gc)
{
    void *elms;
    if (gc != NULL)
    {
        if (gc->numItens > 0)
        {
            elms = gc->item[0];
            gc->cur = 0;
            return elms;
        }
    }
    return NULL;
}

void *gcofGetNext(gCofo *gc)
{
    void *elms;
    if (gc != NULL)
    {
        if (gc->numItens > 0 && gc->cur < gc->numItens - 1)
        {
            gc->cur++;
            elms = gc->item[gc->cur];
            return elms;
        }
    }
    return NULL;
}

void *gcofQuery(gCofo *gc, void *key, int (*cmp)(void *A1, void *B1))
{
    int stat, i;
    if (gc != NULL)
    {
        if (gc->numItens > 0)
        {
            for (i = 0; i < gc->numItens; i++)
            {
                stat = cmp(gc->item[i], key);
                if (stat == TRUE)
                {
                    return gc->item[i];
                }
            }
        }
    }
    return NULL;
}

void *gcofRemove(gCofo *c, void *key, int (*cmp)(void *, void *))
{
    int i, j;
    void *data;
    int stat;
    if (c != NULL)
    {
        if (c->numItens > 0)
        {
            i = 0;
            stat = cmp(key, c->item[i]);
            for (i = 0; i < c->numItens; i++)
            {
                stat = cmp((void *)key, (void *)c->item[i]);
                if (stat == TRUE)
                {
                    break;
                }
            }
            if (stat == TRUE)
            {
                data = c->item[i];
                for (j = i; j < c->numItens - 1; j++)
                {
                    c->item[j] = c->item[j + 1];
                }
                c->numItens--;
                return data;
            }
        }
    }
    return NULL;
}
