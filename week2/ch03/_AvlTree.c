#include"_AvlTree_H.h"


int Max(int a,int b){
	if (a <= b) {
		return b; 
	}
	else {
		return a;
	}
}

struct AvlNode {
	ET Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

static int Height(Position P) {
	if (P == NULL)
		return - 1;
	else
		return P->Height;
}

AvlTree Insert(ET X, AvlTree T) {
	if (T == NULL) {
		T = (AvlTree)malloc(sizeof(struct AvlNode));
		if (T == NULL)
			throw"Out of space!!!";
		else {
			T->Element = X;
			T->Height = 0;
			T->Left = T->Right = NULL;
		}
	}
	else
	if (X < T->Element) {
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2) {
			if (X < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}


static Position SingleRotateWithLeft(Position K2) {
	Position K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), K2->Height) + 1;

	return K1;
};

static Position SingleRotateWithRight(Position K1) {
	Position K2;

	K2 = K1->Right;
	K1->Right = K2->Left;
	K2->Left = K1;

	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
	K2->Height = Max(K1->Height, Height(K2->Right)) + 1;

	Position K2;
};


static Position DoubleRotateWithLeft(Position K3) {
	K3->Left = SingleRotateWithRight(K3->Left);

	return SingleRotateWithLeft(K3);
};

static Position DoubleRotateWithRight(Position K1)//双旋转调整右左
{
	K1->Right = SingleRotateWithLeft(K1->Right);
	return SingleRotateWithRight(K1);
}

AvlTree MakeEmpty(AvlTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ET X, AvlTree T)
{
	if (T == NULL)
	{
		printf("Element not found\n");
		return NULL;
	}
	if (X < T->Element)
		return Find(X, T->Left);
	else if (X > T->Element)
		return Find(X, T->Right);
	else
		return T;
}

Position FindMin(AvlTree T)
{
	if (T == NULL)
	{
		printf("Element not found\n");
		return NULL;
	}
	if (T->Left)
		return FindMin(T->Left);
	else
		return T;
}

Position FindMax(AvlTree T)
{
	if (T == NULL)
	{
		printf("Element not found\n");
		return NULL;
	}
	if (T->Right)
		return FindMax(T->Right);
	else
		return T;
}

AvlTree Insert(int X, AvlTree T)
{
	if (T == NULL)
	{
		T = (AvlTree)malloc(sizeof(struct AvlNode));
		if (T == NULL)
		{
			printf("Malloc Error\n");
			exit(1);
		}
		T->Element = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			if (X < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}
	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (X > T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

AvlTree Delete(ET X, AvlTree T)
{
	Position temp;
	if (T == NULL)
	{
		printf("Element not found\n");
		return NULL;
	}
	else if (X < T->Element)
	{
		T->Left = Delete(X, T->Left);
	}
	else if (X > T->Element)
	{
		T->Right = Delete(X, T->Right);
	}
	else if (T->Left && T->Right)
	{
		temp = FindMin(T->Right);
		T->Element = temp->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else
	{
		temp = T;
		if (T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(temp);
	}

	if (T != NULL)
	{
		int balance = Height(T->Left) - Height(T->Right);
		if (balance == 2)
		{
			int balance2 = Height(T->Left->Left) - Height(T->Left->Right);
			if (balance2 == -1)
			{
				T = DoubleRotateWithLeft(T);
			}
			else
			{
				T = SingleRotateWithLeft(T);
			}
		}
		else if (balance == -2)
		{
			int balance2 = Height(T->Right->Left) - Height(T->Right->Right);
			if (balance2 == -1)
			{
				T = DoubleRotateWithRight(T);
			}
			else
			{
				T = SingleRotateWithRight(T);
			}
		}
		T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	}
	return T;
}

ET Retrieve(Position P)
{
	return P->Element;
}
