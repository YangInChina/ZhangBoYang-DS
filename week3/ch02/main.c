#include"_Hash_H.h"
#include"_HashQuad_H.h"

void main() {
	const char* Key;
	Key = "Apple";
	int TableSize = 10007;
	Hash(Key, TableSize);

    int i;
    const char* A="Apple";

    HashTable hashTable= InitializeTable(7);


    for (i = 0; i < 7; i++)
    {
        Insert(&A[i], hashTable);
    }

    Display(hashTable);

}
