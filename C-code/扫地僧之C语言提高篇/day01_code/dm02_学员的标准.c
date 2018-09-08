#include "stdlib.h"
#include "string.h"
#include "stdio.h"

//打印
void printArray(int *a, int len)
{
	int i = 0;
	for(i=0; i<len; i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
}

//排序
void sortArray(int *a, int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for(i=0; i<5; i++)
	{
		for(j=i+1; j<5; j++)
		{
			if(a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}


//数组做函数参数的退回问题，退回一个指针
//结论：把数组的内存首地址和数组的有效长度给被调用函数

//形参中的数组，编译器会把它当成指针处理，这是c语言的特色
//本质也剖析，形参写在函数上，和写在函数内是一样的，只不过是具有对外的属性而已。

void main22()
{
	int len = 0;

	int a[]  = {3, 34, 45, 6, 37};
    len = sizeof(a)/sizeof(a[0]);
	printf("len = %d\n",len);

	printf("排序之前\n");
    printArray(a, len);

	//排序
    sortArray(a, len);
	printf("排序之后\n");
	printArray(a, len);

	printf("hello...\n");
	system("pause");
	return ;
}
