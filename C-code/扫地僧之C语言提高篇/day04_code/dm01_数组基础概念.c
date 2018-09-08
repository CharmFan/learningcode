#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void main11()
{
	int a[] = {1, 2};    //不指定长度
	int b[100] = {1, 3}; //指定长度

	int c[200] = {0};    //  编译的时 就已经确定 所有的值为零
	
	/**********************   技术盲点 ****************************
		对一维数组 C规定
				c是数组首元素         地址c+1  ： 步长 4个字节
				&c 是整个数组的地址   地址&c+1 ： 步长 200*4
	**************************************************************/
	memset(c, 0, sizeof(c));   //显示的 重置内存块
	
	system("pause");
	return ;
}

//怎么样表达 int a[10]这种数据类型？ int[]
//类型本质：固定大小内存块的别名

//定义数组类型
void main22()
{
	typedef int (MyArrayType)[5];  //定义了一个数据类型  数组数据类型
	int i = 0;
	MyArrayType  myArray;      //int  myArray[5];

	for (i=0; i<5; i++)
	{
		myArray[i] = i + 1;
	}
	for (i=0; i<5; i++)
	{
		printf("%d  ",myArray[i]);
	}
	printf("\n");

	printf("myArray代表数组首元素的地址  myArray:%d   myArray+1:%d \n", myArray, myArray+1);
	printf("&myArray代表整个数组的地址    &myArray:%d  &myArray+1:%d \n", &myArray, &myArray+1);

	system("pause");
	return ;
}

//定义数组指针变量的方法
//************   第一种：用数组类型 *      **********************
void main33()
{
	char * Myarray[] = {"111", "222"};  //指针数组

	//数组指针 用一个指针  来指向一个数组
	typedef int (MyArrayType)[5]; 
	int i = 0;
	MyArrayType  myArray;   //int  myArray[5]; 类型定义变量

	MyArrayType *pArray; //定义一个指针变量 这个指针变量指向一个数组
	{
		int a;
		int *p = NULL;
		p = &a;
	}
	{
		//pArray   = &myArray;
		int myArray2[5]; //相当于一级指针
		for(i=0; i<5; i++)
		{
			myArray2[i] = i+1;
		}
		pArray = &myArray2; //相当于二级指针
		for(i=0; i<5; i++)
		{
			printf("%d  ", (*pArray)[i]);
		}
	}

	system("pause");
	return;

}

//定义数组指针变量   第二种
void main44()
{
	//定义声明一个数组指针类型
	typedef int (*PArrayType)[5]; 
	int i = 0;
	PArrayType  pArray;   //告诉编译器  给我分配一个指针变量

	int c[5];
	pArray = &c;
	for(i=0; i<5; i++)
	{
		(*pArray)[i] = i+1;
	}
	for(i=0; i<5; i++)
	{
		printf("%d  ", (*pArray)[i]);
	}
	system("pause");
	return;
}

//定义数组指针变量   第三种
//前两种方法  通过类型定义变量  比较麻烦
void main()
{
	int (*pArray)[5]; //直接定义一个指向数组的 数组指针变量
	int i = 0;
	int c[5];
	pArray = &c;
	for(i=0; i<5; i++)
	{
		(*pArray)[i] = i+1;
	}
	for(i=0; i<5; i++)
	{
		printf("%d  ", (*pArray)[i]);
	}
	system("pause");
	return;
}