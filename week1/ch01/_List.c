#include<stdlib.h>
#include<stdio.h>

#include "_List_H.h"

struct Node
{
	ElementType Element;
	Position Next;
};




/* Return true if L is empty */
int IsEmpty(List L) {
	return L->Next == NULL;
}


/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */
int IsLast(Position P, List L) {
	return P->Next == NULL;
}


/* Return Position of X in L; NULL if not Found */
Position Find(ElementType X, List L) {
	Position P;

	P = L->Next;	//传入的List L 中L即为表头节点，此时P为第一个节点

	while (P != NULL && P->Element != X) {
		P = P->Next;
	}

	return P;
}


/* Delete first occurrence of X from a list */
/* Assume use of a header node */
void Delete(ElementType X, List L) {
	Position P, TmpCell;

	P = FindPrevious(X, L);

	if (!IsLast(P, L)) {
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}



/* If X is not found, then Next field of returned */
/* Position is NULL */
/* Assumes a header */
Position FindPrevious(ElementType X, List L) {
	Position P;

	P = L;

	while (P->Next != NULL && P->Next->Element != X) {
		P = P->Next;
	}

	return P;
}


/* Insert after legal position P */
/* Header implementation assumed*/
/* Parameter L is unused in this implementation*/
void Insert(ElementType X, List L, Position P) {
	Position TmpCell;

	TmpCell = (Position) malloc(sizeof(struct Node));

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;

}


/* Delete algorithm*/
void DeleteList(List L) {
	Position P, Tmp;

	P = L->Next;			//P指向头结点的下一个节点，即第一个数据节点
	L->Next = NULL;			//将头结点与链表断开。
	while (P != NULL) {
		Tmp = P->Next;		//P的下一个地址存入Tmp
		free(P);			//释放P所指的内存空间
		P = Tmp;			//将Tmp中存入的地址赋值给P
	}
}


/* Return the position of Header */
Position Header(List L) {
	Position P;
	P = L;
	return P;
}


/* Return the position of the first data node */
Position First(List L) {
	Position P;
	P = L->Next;
	return P;
}

/* return the node afer the posion of p */
Position Advance(Position P) {
	Position P1;
	P1 = P->Next;
	return P1;
}

/* Return the data in position of P*/
ElementType Retrieve(Position P) {
	ElementType X;
	X = P->Element;
	return X;
}




