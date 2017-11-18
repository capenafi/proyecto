#ifndef HASHTABLE_H
#define	HASHTABLE_H

#include "../NodeList/NodeList.h"

typedef struct HashTable {
    List hash[2017];
} HashTable;

HashTable *Hash_Create();

int _IsEmpty(HashTable *L);

List *GetListFrom(List *L,int index);

#endif
