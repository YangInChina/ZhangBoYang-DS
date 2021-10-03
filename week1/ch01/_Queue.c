#include"_Queue_h.h"

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType* Array;
};

int IsEmpty(Queue Q) {
	return Q->Size == 0;
}


void MakeEmpty(Queue Q) {
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

int IsFull(Queue Q) {
	return (Q->Rear + 1) % Q->Size == Q->Front;
}

Queue CreateQueue(int MaxElements) {
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QueueRecord));
	Q->Front = Q->Rear = -1;
	return Q;
}

void DisposeQueue(Queue Q) {
	if (Q == NULL) {
		printf_s("Must use QueueRecord first");
		return;
	}
	else {
		while (!IsEmpty(Q)) {
			Dequeue(Q);
		}
	}
}


void Enqueue(ElementType X, Queue Q) {
	Q->Rear = (Q->Rear + 1) % Q->Size;
	Q->Array[Q->Rear] = X;
}

ElementType Front(Queue Q) {
	if (Q->Rear == Q->Front)	
		throw"队空！";			
	return Q->Array[(Q->Front + 1) % Q->Size];
}

void Dequeue(Queue Q) {
	if (Q->Rear == Q->Front)	
		throw"下溢";			/*功能：将队头元素出队*/
	Q->Front = (Q->Front + 1) % Q->Size;				/*返回值：DT类型的元素x*/
}

ElementType FrontAndDequeue(Queue Q) {
	if (Q->Rear == Q->Front)
		throw"下溢";			/*功能：将队头元素出队*/
	Q->Front = (Q->Front + 1) % Q->Size;				/*返回值：DT类型的元素x*/
	return Q->Array[Q->Front];
}
