#ifndef LISTDE_H
#define	LISTDE_H

#include "NodeListDE.h"

typedef struct ListDE {
    NodeListDE *header, *last;
} ListDE;

ListDE *ListDE_Create();

int ListDE_IsEmpty(ListDE *L);

NodeListDE *ListDE_GetHeader(ListDE *L);

NodeListDE *ListDE_GetLast(ListDE *L);

void ListDE_InsertAsLast(ListDE *L, NodeListDE *newNode);

void ListDE_InsertAsHeader(ListDE *L, NodeListDE *newNode);

void ListDE_AddNext(ListDE *L, NodeListDE *p, NodeListDE *newNode);
NodeListDE *ListDE_Search(ListDE *L, char codigo[],cmpfn f);
NodeListDE *ListDE_GetPrevious(List *L, NodeList *node);
void List_RemoveNode(List *L, NodeList *node);
NodeList *List_RemoveFirst(List *L);
NodeList *List_RemoveLast(List *L);
int List_NodeExists(List *L, NodeList *node);
int List_GetSize(List *L);
void List_Delete(List **L);
void List_Print(List *L, printfn print);
#endif
