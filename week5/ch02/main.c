/*希尔排序（缩小增量排序）*/
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
		array[i] = rand() % (right - left + 1) + left;
	}
	return array;
}
/*流行的增量序列（Shell建议的，但是不好）*/
void ShellSort(ElementType a[], int n)
{
	int i,j, Increment;
	ElementType Tmp;
	for (Increment = n / 2; Increment >= 1; Increment /= 2)
	{
		for (i = Increment; i <= n - 1; i++)
		{
			Tmp = a[i];
			for (j = i - Increment; j >= 0&&a[j]>Tmp; j -= Increment)
			{
				a[j + Increment] = a[j];
			}
			a[j + Increment] = Tmp;
		}
	}
}/*书上实现增量序列*/
void Shell(ElementType a[], int n)
{
	int i, j, Increment;
	ElementType Tmp;
	for (Increment = n / 2; Increment > 0; Increment /= 2)
	{
		for (i = Increment; i <n; i++)
		{
			Tmp = a[i];
			for (j = i; j >= Increment; j -= Increment)
			{
				if(Tmp<a[j-Increment])
					a[j] = a[j-Increment];
				else
					break;
			}
			a[j] = Tmp;
		}
	}
}
void printArray(ElementType a[], int n)
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
	printArray(a, size);
	ShellSort(a, size);
	printArray(a, size);
	return 0;
}
