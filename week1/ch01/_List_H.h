#pragma once

#include<stdlib.h>
#include<stdio.h>

struct Node;

typedef struct Node* PtrToNode;		//将结构体的Node类型的指针定义为PtrToNode;
typedef PtrToNode List;				//给PtrToNode起的别名
typedef PtrToNode Position;			//给PtrToNode起的别名

typedef int ElementType;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType x, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType x, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
