#pragma once
#include<stdlib.h>
#include<stdio.h>

struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;

typedef int ET;		//ElementType

AvlTree MakeEmpty(AvlTree T);
Position Find(ET X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ET X, AvlTree T);
AvlTree Delete(ET X, AvlTree T);
ET Retrieve(Position P);


