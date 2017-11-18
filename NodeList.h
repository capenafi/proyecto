#ifndef NODELIST_H
#define	NODELIST_H


typedef struct NodeList{
	char *codigo;
	struct NodeList *next;
} NodeList;

NodeList *NodeList_Create(char *codigo);

void NodeList_SetContent(NodeList *node, char *codigo);

char * NodeList_GetContent(NodeList *node);

void NodeList_SetNext(NodeList *node, NodeList *next);

NodeList *NodeList_GetNext(NodeList *node);

#endif
