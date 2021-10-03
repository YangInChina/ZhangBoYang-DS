#include"_Stack_h.h"


struct Node
{
	ElementType Element;
	PtrToNode Next;
};


int IsEmpty(Stack S) {
	return S->Next == NULL;
}


Stack CreateStack(void) {
	Stack S;

	S =(Stack) malloc(sizeof(struct Node));

	if (S == NULL) {
		return;
	}
	S->Next == NULL;
	MakeEmpty(S);
	return S;
}

void MakeEmpty(Stack S) {
	if (S == NULL) {
		printf_s("Must use CreateStack first");
		return;
	}
	else {
		while (!IsEmpty(S)) {
			Pop(S);
		}
	}
}

void Push(ElementType X, Stack S) {
	PtrToNode TmpCell;
	TmpCell = (Stack)malloc(sizeof(struct Node));
	if (TmpCell == NULL) {
		printf_s("Out of space");
		return;
	}
	else {
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}


ElementType Top(Stack S) {
	if (!IsEmpty(S)) {
		return S->Next->Element;
	}
	else {
		printf_s("Empty stack");
		return 0;
	}
}

void DisposeStack(Stack S) {
	if (S == NULL) {
		printf_s("Must use CreateStack first");
		return;
	}
	else {
		while (!IsEmpty(S)) {
			Pop(S);
		}
	}
}

void Pop(Stack S) {
	PtrToNode TmpCell;
	TmpCell = (Stack)malloc(sizeof(struct Node));
	TmpCell = S->Next;
	S->Next = TmpCell->Next;
	free(TmpCell);
}
