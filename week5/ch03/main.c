/*堆排序*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int ElementType;
#define LeftChild(i) (2*(i)+1)

int *RandArray(int size, ElementType left, ElementType right)
{
	srand((unsigned)time(NULL));
	int i;
	ElementType *array = malloc(sizeof(ElementType)*size);
	for (i = 0; i < size; i++)
	{
		array[i] = rand() % (right - left + 1) + left;
	}
	return array;
}
void Swap(ElementType *a,ElementType *b)
{
	int t;
	//int* t = malloc(sizeof(ElementType));
	t = *a;
	*a = *b;
	*b = t;
}
/*最大堆从i位置元素下滤*/
void PercDown(ElementType a[], int i, int N)
{
	int Child;
	ElementType Tmp;
	for (Tmp = a[i]; LeftChild(i) < N; i = Child)
	{
		Child = LeftChild(i);
		if (Child != N - 1 && a[Child] < a[Child + 1])
			Child++;
		if (Tmp < a[Child])
			a[i] = a[Child];
		else
			break;
	}
	a[i] = Tmp;
}
//堆排序，建堆弹出最大放死区
void HeapSort(ElementType a[], int N)
{
	int i;
	for (i = N / 2; i >= 0; i--)
		PercDown(a, i, N);//构建最大堆
	for (i = N - 1; i > 0; i--)
	{
		Swap(&a[0], &a[i]);//删除最大值
		PercDown(a, 0, i);//重新构造前i个元素的最大堆
	}
}
void printArray(ElementType a[],int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("%d\n", a[i]);
}
int main()
{
	int size = 10;
	int *a = malloc(sizeof(int)*size);
	a = RandArray(size, 0, 100);
	printArray(a,size);
	HeapSort(a, size);
	printArray(a,size);
	return 0;
}
