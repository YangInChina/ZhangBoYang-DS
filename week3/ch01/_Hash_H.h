#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef unsigned int Index;

Index Hash(const char* Key, int TablSize);

struct ListNode;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(const char* Key, HashTable H);
void Insert(const char* Key, HashTable H);
int Retrieve(Position P);
void Display(HashTable H);
