#include"_Tree_H.h"

struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};


SearchTree MakeEmpty(SearchTree T) {
	if (T != NULL) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
	}
	return NULL;
}

Position Find(ElementType X, SearchTree T) {
	if (T == NULL) {
		return NULL;
	}
	if (X < T->Element) {
		return Find(X, T->Left);
	}
	else {
		if (X > T->Element) {
			return Find(X, T->Right);
		}
		else {
			return T;
		}
	}
}

Position FindMin(SearchTree T) {
	if (T == NULL) {
		return NULL;
	}
	else {
		if (T->Left == NULL) {
			return T;
		}
		else {
			return FindMin(T->Left);
		}
	}
}//递归实现


Position FindMax(SearchTree T) {
	if (T != NULL) {
		while (T->Right != NULL) {
			T = T->Right;
		}
	}
	return T;
}

SearchTree Insert(ElementType X, SearchTree T) {
	if (T == NULL) {
		T =(SearchTree) malloc(sizeof(struct TreeNode));
		if (T == NULL)
			throw"Out of Space!!";
		else {
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else {
		if (X < T->Element) {
			T->Left = Insert(X, T->Left);
		}
		else {
			if (X > T->Element) {
				T->Right = Insert(X, T->Right);
			}
		}
	}

	return T;
}


SearchTree Delete(ElementType X, SearchTree T) {
	Position TmpCell;

	if (T == NULL) {
		throw"Element not found";
	}
	else {
		if ( X < T->Element ) {
			T->Left = Delete(X, T->Left);
		}
		else {
			if (X > T->Element) {
				T->Right = Delete(X, T->Left);
			}
			else {
				if (T->Left && T->Right) {
					TmpCell = FindMin(T->Right);
					T->Element = TmpCell->Element;
					T->Right = Delete(T->Element, T->Right);
				}
				else {
					TmpCell = T;
					if (T->Left == NULL) {
						T = T->Right;
					}
					else {
						if (T->Right == NULL) {
							T = T->Left;
						}
					}
					free(TmpCell);
				}
			}
		}
	}

	return T;
}
