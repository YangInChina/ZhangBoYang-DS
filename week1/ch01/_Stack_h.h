#pragma once

#include<stdlib.h>
#include<stdio.h>

struct Node;

typedef struct Node* PtrToNode;		//将结构体的Node类型的指针定义为PtrToNode;
typedef PtrToNode Stack;				//给PtrToNode起的别名

typedef int ElementType;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
