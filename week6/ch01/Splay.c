#include "Splay.h"
#include<stdlib.h>
#include<stdio.h>
struct SplayNode
{
	ElementType Element;
	SplayTree Left;
	SplayTree Right;
};

typedef struct SplayNode *Position;
static Position NullNode = NULL;

SplayTree MakeEmpty(SplayTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}

	return NULL;
}
/*SplayTree Initialize(void)
{
	if (NullNode == NULL)
	{
		NullNode = (SplayNode*)malloc(sizeof(struct SplayNode));
		if (NullNode == NULL)
			printf("Out of space");
		NullNode->Left = NullNode->Right = NullNode;
	}
	return NullNode;
}*/
SplayTree SingleRotateWithLeft(SplayTree k1)//左旋
{
	Position k2;

	k2 = k1->Right;
	k1->Right = k2->Left;
	k2->Left = k1;
	return k2;
}
SplayTree SingleRotateWithRight(SplayTree T)//右旋
{
	SplayTree k1;

	k1 = T->Left;
	T->Left = k1->Right;
	k1->Right = T;
	return k1;
}
SplayTree Splay(ElementType X, SplayTree T)
{
	SplayNode pseudo;
	SplayTree ltree, rtree;
	ltree = rtree = &pseudo;
	pseudo.Left = pseudo.Right = NULL;

	if (T == NULL || X == T->Element)
		return T;

	for (;;)
	{
		/*小于中树节点时*/
		if (X < T->Element)
		{
			/*没有左子树则证明没有找到，直接退出*/
			if (T->Left == NULL)
				break;
			/*zigzig形状*/
			if (X < T->Left->Element)
			{
				T = SingleRotateWithRight(T);
				/*旋转完之后如果没有左节点，一样是没找到*/
				if (T->Left == NULL)
					break;
			}
			/*右连接，把树根节点及右子树连接到右树上*/
			rtree->Left = T;
			rtree = T;
			T = T->Left;
		}
		else if (X > T->Element)
		{
			/*没有右子树则证明没有找到，直接退出*/
			if (T->Right == NULL)
				break;
			/*zagzag形状*/
			if (X > T->Right->Element)
			{
				T = SingleRotateWithLeft(T);
				/*旋转完之后如果没有右节点，一样是没找到*/
				if (T->Right == NULL)
					break;
			}
			/*左连接，把树根节点及左子树连接到右树上*/
			ltree->Right = T;
			ltree = T;
			T = T->Right;
		}
		/*找到该节点，退出*/
		else
			break;
	}

	/*重新构造树，现在根节点的左右孩子分别接到左树的右节点和右树的左节点*/
	ltree->Right = T->Left;
	rtree->Left = T->Right;
	T->Left = pseudo.Right;
	T->Right = pseudo.Left;

	return T;
}
SplayTree FindMin(SplayTree T)
{
	Position np = T;
	if (T != NULL)
	{
		while (np->Left != NULL)
			np = np->Left;

		ElementType X = np->Element;
		return Splay(X, T);
	}
	return NULL;
}
SplayTree FindMax(SplayTree T)
{
	Position np = T;
	if (T != NULL)
	{
		while (np->Right != NULL)
			np = np->Right;

		ElementType X = np->Element;
		return Splay(X, T);
	}
	return NULL;
}



SplayTree Insert(ElementType X, SplayTree T)
{
	/*空树时直接创建新的树*/
	if (T == NULL)
	{
		T = (SplayTree)malloc(sizeof(struct SplayNode));
		if (T == NULL)
		{
			fprintf(stderr, "not enough memory");
			exit(1);
		}
		T->Element = X;
		T->Left = T->Right = NULL;
		return T;
	}
	T = Splay(X, T);
	/*元素不存在*/
	if (X != T->Element)
	{
		SplayTree newone;
		newone = (SplayTree)malloc(sizeof(struct SplayNode));
		newone->Element = X;
		/*小于T的根节点，则根节点及其右子树作为新节点的右子数，反之亦然*/
		if (X < T->Element)
		{
			newone->Right = T;
			newone->Left = T->Left;
			T->Left = NULL;
		}
		else
		{
			newone->Left = T;
			newone->Right = T->Right;
			T->Right = NULL;
		}
		T = newone;
	}

	/*元素存在时直接返回T,与不存在时返回值相同*/
	return T;

}
SplayTree Remove(ElementType X, SplayTree T)
{
	if (T == NULL)
	{
		fprintf(stderr, "empty Tree");
		return T;
	}

	T = Splay(X, T);
	if (X == T->Element)
	{
		/*左右子数不为空，那么寻找左子树的最大值作为新的根节点*/
		if (T->Left && T->Right)
		{
			SplayTree ltemp, rtemp;
			ltemp = T->Left;
			rtemp = T->Right;
			free(T);
			ltemp = Splay(X, ltemp);
			ltemp->Right = rtemp;
			T = ltemp;
		}
		/*右子树为空*/
		else if (T->Left)
		{
			SplayTree temp;
			temp = T;
			T = T->Left;
			free(temp);
		}
		/*左子数为空*/
		else
		{
			SplayTree temp;
			temp = T;
			T = T->Right;
			free(temp);
		}
		/*左右子树都为空也没关系，返回的是NULL*/
	}
	else
		printf("%d don't exist", X);

	return T;
}
SplayTree Find(ElementType X, SplayTree T)
{
	/*空树直接返回*/
	if (T == NULL)
	{
		fprintf(stderr, "empty tree");
		return T;
	}

	/*不保证最后返回的元素等于X，需要调用者检查*/
	T = Splay(X, T);
	return T;
}
ElementType Retrieve(SplayTree T)
{
	return T->Element;
}
void PrintDepth(ElementType A, int depth)
{
	while (depth != 0)
	{
		printf("	");
		depth--;
	}
	printf("%d\n", A);
}

void PrintTree(SplayTree T, int depth)
{
	if (T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if (T->Left != NULL)
		PrintTree(T->Left, depth + 1);

	PrintDepth(T->Element, depth);
	if (T->Right != NULL)
		PrintTree(T->Right, depth + 1);
}

/*void PrintTree(SplayTree T)
{
	if (T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if (T->Left != NULL)
		PrintTree(T->Left);
	printf("%d\n", T->Element);
	if (T->Right != NULL)
		PrintTree(T->Right);
}*/
