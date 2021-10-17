#include"_Hash_H.h"

static int MinTableSize = 10;

Index Hash(const char* Key, int TableSize) {
	Index HashVal = 0;

	while (*Key != '\0') {
		HashVal = (HashVal << 5) + *Key++;
	}
	return HashVal % TableSize;
}


struct ListNode {
	const char* Element;
	Position Next;
};

typedef Position List;

/// <summary>
/// List *TheList will be an array of lists,allocated later.
/// The lists use headers(for simplicity), though this wastes space
/// </summary>
struct HashTbl {
	int TableSize;
	List* TheLists;
};

HashTable InitializeTable(int TableSize) {
	HashTable H;
	int i;

	if (TableSize < MinTableSize) {
		printf("Table size too small");
		return NULL;
	}

	/* Allocate table */
	H = (HashTable)malloc(sizeof(struct HashTbl));
	
	H->TableSize = TableSize;

	/* Allocate array of lists */
	H->TheLists = (List*)malloc(sizeof(List) * H->TableSize);

	/* Allocate list headers*/
	for (i = 0; i < H->TableSize; i++) {
		H->TheLists[i] = (List)malloc(sizeof(struct ListNode));
		
		H->TheLists[i]->Next = NULL;
	}
	return H;
}

Position Find(const char* Key, HashTable H) {
	Position P;
	List L;

	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while (P != NULL && P->Element != Key) {
		P = P->Next;
	}
	return P;
}

void Insert(const char* Key, HashTable H) {
	Position Pos, NewCell;
	List L;

	Pos = Find(Key, H);
	if (Pos == NULL) {
		NewCell =(Position) malloc(sizeof(struct ListNode));
		
		L = H->TheLists[Hash(Key, H->TableSize)];
		NewCell->Next = L->Next;
		NewCell->Element = Key;
		L->Next = NewCell;
	}
}

void Display(HashTable H)
{
	int i;

	for (i = 0; i < m; i++)
	{
		if (H->TheLists[i] != NULL)
		{
			printf("%d \n", H->TheLists[i]);
		}
	}
}
