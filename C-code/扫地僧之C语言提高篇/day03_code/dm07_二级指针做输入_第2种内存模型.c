#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//*****************************    二级指针做输入  第2种内存模型    ****************
//************************************     二维数组    *****************************
//打印 排序
//封装函数
void main11()
{
	int i = 0, j = 0;
	int num = 4;
	char myBuf[30];
	char myArray[10][30] = {"aaaaaaa","cccccc","bbbbbbb","333333"};
	
	//打印
	printf("排序之前 \n");
	for(i=0; i<num; i++)
	{
		printf("%s \n", myArray[i]);
	}

	//排序
	for(i=0; i<num; i++)
	{
		for(j=i+1; j<num; j++)
		{
			if(strcmp(myArray[i], myArray[j]) > 0)
			{
				strcpy(myBuf, myArray[i]);     //交换的是 内存块
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], myBuf);
			}
		}
	}
	//打印
	printf("排序之后 \n");
	for(i=0; i<num; i++)
	{
		printf("%s \n", myArray[i]);
	}

	system("pause");
	return ;
}
//***********************************************************************
/*           dm07_二级指针做输入_第2种内存模型  myArray+1
             dm06_二级指针做输入_第1种内存模型  myArray+1    不一样

     问题本质：指针的步长不一样，指针所指指向的内存空间的数据类型不一样

**************   调用时候出错  printfArray11   *************************/
void printfArray11(char **myArray,int num)
{
	int i =0;

	for(i=0; i<num; i++)
	{
		//printf("%s \n",myArray[i]);
		printf("%s \n",*(myArray+i));
	}
}

void printfArray(char myArray[10][30],int num)
{
	int i =0;

	for(i=0; i<num; i++)
	{
		//printf("%s \n",myArray[i]);
		printf("%s \n",*(myArray+i));
	}
}

void sortArray(char myArray[10][30], int num)
{
	int i = 0, j = 0;
	char tmpBuf[30];

	for(i=0; i<num; i++)
	{
		for(j=i+1; j<num; j++) 
		{
			if(strcmp(myArray[i],myArray[j])>0)
			{                                 //上一种交换的是指针值
				strcpy(tmpBuf, myArray[i]);  /****** 交换的是内存块 ******/
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], tmpBuf);
			}
		}
	}
}

void main()
{	int n=0,m=0;
	int i = 0, j = 0;
	int num = 4;
	char myBuf[30];
	char tmpBuf[30];
	char myArray[10][30] = {"aaaaaaa","cccccc","bbbbbbb","333333"};  // myArray的步长是 30
	//myArray 编译器只会关心 ： 有10行，每行30列 
	//关心这个干什么？ 主要是解决： myArray+1的步长    >>>多维数组名的本质 

	{
		int len1 = sizeof(myArray);     //300
		int len2 = sizeof(myArray[0]);  //30
		int len3 = sizeof(myArray);
		int size = len1/ len2;
		printf("len1:%d, len2:%d,len3:%d, size:%d \n",len1, len2,len3, size);
	}
	//打印
	printf("排序之前 \n");
	printfArray(myArray, num);


	//排序
	sortArray(myArray, num);


	//打印
	printf("排序之后 \n");
	printfArray(myArray, num);


	system("pause");
	return;
}