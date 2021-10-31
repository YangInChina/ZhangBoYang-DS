/*插入排序*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int ElementType;
int *RandArray(int size, ElementType left, ElementType right)
{
	srand((unsigned)time(NULL));
	int i;
	ElementType *array = malloc(sizeof(ElementType)*size);
	for (i = 0; i < size; i++)
	{
		array[i] = rand() % (right - left+1) + left;
	}
	return array;
}
void insertSort(ElementType a[], int n)
{
	int p,i;
	ElementType Tmp;
	for(p = 1; p <= n - 1; p++)
	{
		Tmp = a[p];
		for (i = p-1; i>=0; i--)
		{
			if (a[i] > Tmp)
				a[i + 1] = a[i];
			else
				break;
		}
		a[i + 1] = Tmp;
		/*书上实现方法
		for (i = p; i > 0 && a[i - 1] > Tmp; i--)
		{
			a[i] = a[i - 1];
		}
		a[i] = Tmp;*/
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
	insertSort(a, size);
	printArray(a,size);
	return 0;
}
