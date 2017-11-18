#include "NodeList.h"
#include <stdlib.h>

NodeList *NodeList_Create(char *codigo){
	NodeList *newNode = (NodeList*)malloc(sizeof(NodeList));
	newNode->next = NULL;
	newNode->cont = codigo;
	return newNode;
}
void NodeList_SetContent(NodeList *node,char *codigo){
	node->cont = codigo;
}
char[] NodeList_GetContent(NodeList *node){
	return node->cont;
}
void NodeList_SetNext(NodeList *node, NodeList *next){
	node->next = next;
}
NodeList *NodeList_GetNext(NodeList *node){
	return node->next;
}
