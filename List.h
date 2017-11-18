#ifndef LIST_H
#define	LIST_H

#include "../NodeList/NodeList.h"

typedef struct List {
    NodeList *header, *last;
} List;

List *List_Create();

int List_IsEmpty(List *L);

NodeList *List_GetHeader(List *L);

NodeList *List_GetLast(List *L);

void List_InsertAsLast(List *L, NodeList *newNode);

void List_InsertAsHeader(List *L, NodeList *newNode);

void List_AddNext(List *L, NodeList *p, NodeList *newNode);
NodeList *List_Search(List *L, char codigo[],cmpfn f);
NodeList *List_GetPrevious(List *L, NodeList *node);
void List_RemoveNode(List *L, NodeList *node);
NodeList *List_RemoveFirst(List *L);
NodeList *List_RemoveLast(List *L);
int List_NodeExists(List *L, NodeList *node);
int List_GetSize(List *L);
void List_Delete(List **L);
void List_Print(List *L, printfn print);
#endif
