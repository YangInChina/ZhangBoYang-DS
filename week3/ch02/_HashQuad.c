#include"_HashQuad_H.h"
enum KindOfEntry { Legitimate, Empty, Deleted };

struct HashEntry {
	const char* Element;
	enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl {
	int TableSize;
	Cell* TheCells;
};

Index Hash(const char* Key, int TableSize) {
	Index HashVal = 0;

	while (*Key != '\0') {
		HashVal = (HashVal << 5) + *Key++;
	}
	return HashVal % TableSize;
}

HashTable InitalizeTable(int TableSize) {
	HashTable H;
	int i;

	H =(HashTable) malloc(sizeof(struct HashTbl));

	H->TableSize = TableSize;
	H->TheCells =(Cell*)malloc(sizeof(Cell) * H->TableSize);

	for (i = 0; i < H->TableSize; i++) {
		H->TheCells[i].Info = Empty;
	}
	return H;

}

Position Find(const char* Key, HashTable H) {
	Position CurrentPos;
	int CollisionNum;

	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != Empty &&
		H->TheCells[CurrentPos].Element != Key) {
		CurrentPos += 2 * ++CollisionNum - 1;
		if (CurrentPos >= H->TableSize) {
			CurrentPos -= H->TableSize;
		}
	}
	return CurrentPos;
}

void Insert(const char* Key, HashTable H) {
	Position Pos;

	Pos = Find(Key, H);
	if (H->TheCells[Pos].Info != Legitimate) {
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
	}
}
