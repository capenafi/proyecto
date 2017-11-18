#include "List.h"
#include <stdlib.h>

HashTable *List_Create(){
	HashTable *newList = (HashTable*)malloc(sizeof(HashTable));
	newList->header = NULL;
	newList->last = NULL;
	return newList;
}


NodeList *List_GetHeader(List *L){
	return L->header;
}

NodeList *List_GetLast(List *L) {
	return L->last;
}

void List_InsertAsLast(List *L, NodeList *newNode){
	NodeList_SetNext(newNode, NULL);
	if (List_IsEmpty(L)) {
		L->header = newNode;
		L->last = newNode;
	}
	else {
		NodeList_SetNext(L->last, newNode);
		L->last = newNode;
	}
}

void List_InsertAsHeader(List *L, NodeList *newNode){
	if (L != NULL) {
		if (List_IsEmpty(L)){
			L->header = L->last = newNode;
		}
		else{
			NodeList_SetNext(newNode, L->header);
			L->header = newNode;
		}
	}
}

NodeList * List_Search(List *L, char codigo[], cmpfn cmp){
	NodeList *iterator;
	for (iterator = L->header; iterator != NULL; iterator = iterator->next){
		if (cmp(iterator->cont, value) == 0)
			return iterator;
	}
	return NULL;
}

NodeList * List_GetPrevious(List *L, NodeList *p){
	NodeList *iterator;
	for (iterator = L->header; iterator->next != NULL; iterator = iterator->next){
		if (iterator->next == p)
			return iterator;
	}
	return NULL;
}

int List_NodeExists(List *L, NodeList *p){
	NodeList *iterator;
	for (iterator = L->header; iterator != NULL; iterator = iterator->next){
		if (iterator == p) return 1;
	}
	return 0;
}

void List_AddNext(List *L, NodeList *p, NodeList *newNode){
	if (!List_NodeExists(L, p)) return;
	else if (p == L->last) List_InsertAsLast(L, newNode);
	else{
		newNode->next = p->next;
		p->next = newNode;
	}
}

void List_RemoveNode(List *L, NodeList *p){
	if (!List_NodeExists(L, p)) return;
	if (p == L->last) List_RemoveLast(L);
	else if (p == L->header) List_RemoveFirst(L);
	else{
		NodeList *ant = List_GetPrevious(L, p);
		ant->next = p->next;
		p->next = NULL;
	}
	return;
}

NodeList *List_RemoveFirst(List *L){
	NodeList *tmp;
	if (List_IsEmpty(L)) return NULL;
	tmp = L->header;
	if (L->header == L->last) L->last = NULL;
	L->header = L->header->next;
	tmp->next = NULL;
	return tmp;
}

NodeList *List_RemoveLast(List *L){
	NodeList *tmp;
	if (List_IsEmpty(L)) return NULL;
	tmp = L->last;
	if (L->header == L->last) L->header = L->last = NULL;
	else{
		NodeList *ant = List_GetPrevious(L, L->last);
		L->last = ant;
		ant->next = NULL;
	}
	return tmp;
}

int List_GetSize(List *L){
	int cont = 0;
	NodeList *iterator;
	for (iterator = L->header; iterator != NULL; iterator = iterator->next)
		cont++;
	return cont;
}
void List_Delete(List **L){
	free(*L);
}

NodeList *List_GetNodeByIndex(List *L, int index) {
	NodeList *iterator;
	int contador = 0;
	for (iterator = L->header; iterator != NULL; iterator = NodeList_GetNext(iterator)) {
		contador++;
		if (contador == index) {
			return iterator;
		}
	}
}

void List_Print(List *L, printfn print){

	NodeList *iterator;
	for (iterator = L->header; iterator != NULL;
		iterator = iterator->next) {
		print(NodeList_GetContent(iterator));
	}

	NodeList *viajero = L->header;
	while (viajero != NULL) {
		print(NodeList_GetContent(viajero));
		viajero = NodeList_GetNext(viajero);
	}
}
