#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/* ***********************   多维数组名的本质  ***********************
		多维数组名的本质：
			数组指针，步长  一维长度

			(a+i)  代表是整个第i行的地址  2级指针
			*(a+i) 代表第i行首元素的地址  1级指针
			*(a+i)+j ==========>&a[i][j]
			只不过第一行的地址和第一行首元素的地址是重叠的
			*(*(a+i) + j) =======>a[i][j]元素的值
**********************************************************************/
void main11()
{
	int a[3][5], i=0, j=0;
	int tmp = 1;

	for(i=0; i<3; i++)
	{
		for(j=0; j<5; j++)
		{
			a[i][j] = tmp++;
		}
	}

	for(i=0; i<3; i++)
	{
		for(j=0; j<5; j++)
		{
			printf("%d ",a[i][j]);
		}
	}

	//a 多维数组名 代表？
	printf("a : %d, a+1 : %d ", a, a+1);  //a+1 步长 是20个字节  5*4
	printf("&a : %d, &a+1 : %d ", &a, &a+1);
	
	{
		//定义一个指向数组的指针变量 这里用第三种方法定义
		int (*pArray)[5];//告诉编译器 分配4个字节  32bit平台
		pArray = a;

		printf("\n");
		for(i=0; i<3; i++)
		{
			for(j=0; j<5; j++)
			{
				printf("%d ", pArray[i][j]);
			}
		}
	}
	/* ***********************   多维数组名的本质  ***********************
		多维数组名的本质：
			数组指针，步长  一维长度

			(a+i)  代表是整个第i行的地址  2级指针
			*(a+i) 代表第i行首元素的地址  1级指针
			*(a+i)+j =========>&a[i][j]
			只不过第一行的地址和第一行首元素的地址是重叠的
			*(*(a+i) + j) <=======> a[i][j]元素的值

			a[i] ==> a[0+i] ==> *(a+i)
			a[i][j] => a[0+i][j] => *(a+i)[j] => *(a+i)[0+j] => *(*(a+i) +j)
	*************************************************************************/
 	printf("hello...\n");
	system("pause");
	return ;
}



//******************************************************************************
void printArray01(int a[3][5])
{
	int i, j, tmp = 0;

	for(i=0; i<3; i++)
	{
		for(j=0; j<5; j++)
		{
			printf("%d  ",a[i][j]);
		}
	}
}


void printArray02(int a[][5])  //a是指向一维的指针变量
{
	int i, j, tmp = 0;

	for(i=0; i<3; i++)
	{
		for(j=0; j<5; j++)
		{
			printf("%d  ",a[i][j]);
		}
	}
}

void printArray03(int (*a)[5])
{
	int i, j, tmp = 0;

	for(i=0; i<3; i++)
	{
		for(j=0; j<5; j++)
		{
			printf("%d  ",a[i][j]);
		}
	}
}

//多维数组做函数参数  退化过程。。。。。。事实存在。。。。。
//为什呢？  下节课有讲解
void main()
{
	int a[3][5], i=0, j=0;
	int tmp = 01;

	for(i=0; i<3; i++)
	{
		for(j=0; j<5; j++)
		{
			a[i][j] = tmp++;
		}
	}

	printArray01(a);
	printArray02(a);
	printArray03(a);

	printf("hello...\n");
	system("pause");
	return ;

}