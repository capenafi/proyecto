#include "NodeListDE.h"
#include <stdlib.h>

NodeListDE *NodeListDE_Create(char *codigo){
	NodeListDE *newNode = (NodeListDE*)malloc(sizeof(NodeListDE));
	newNode->nuevo = NULL;
	newNode->antiguo =NULL;
	newNode->cont = codigo;
	return newNode;
}
void NodeListDE_SetContent(NodeListDE *node,char *codigo){
	node->cont = codigo;
}
char[] NodeListDE_GetContent(NodeListDE *node){
	return node->cont;
}
void NodeListDE_SetNext(NodeListDE *node, NodeListDE *next){
	node->next = next;
}
NodeListDE *NodeListDE_GetNext(NodeListDE *node){
	return node->next;
}
