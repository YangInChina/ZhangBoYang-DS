#pragma once
#include<stdlib.h>
#include<stdio.h>

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitalizeTable(int TableSize);
//void DestroyTable(HashTable H);
Position Find(const char* Key, HashTable H);
void Insert(const char* Key, HashTable H);
//const char* Retrieve(HashTable H);

Index Hash(const char* Key, int TablSize);
