#ifndef NODELISTDE_H
#define	NODELISTDE_H


typedef struct NodeListDE{
	char *codigo;
	struct NodeListDE *reciente;
	struct NodeListDE *antiguo;
} NodeListDE;

NodeListDE *NodeListDE_Create(char *codigo);

void NodeListDE_SetContent(NodeListDE *node, char *codigo);

char * NodeListDE_GetContent(NodeListDE *node);

void NodeListDE_SetNext(NodeListDE *node, NodeListDE *next);

NodeListDE *NodeListDE_GetNext(NodeListDE *node);

void NodeLisDEt_SetBefore(NodeListDE *node, NodeListDE *next);

NodeListDE *NodeListDE_GetBefore(NodeListDE *node);
#endif
