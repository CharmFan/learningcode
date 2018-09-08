#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//野指针产生的原因
//指针变量和它所指向的内存空间变量是两个不同的概念
//释放了指针所指向的内存空间，当时指针变量本身没有重置成NULL
//造成释放的时候，通过if（p1 != NULL）

/*避免方法：
		1、定义指针的时候 初始化成NULL
		2、释放指针所指向的内存空间后，把指针重置成NULL
************************************/

/* 特别注意： 出现野指针，造成宕机 */
void main21()
{
	char *p1  = NULL;
	p1 = (char *)malloc(100);
	if(p1 == NULL)
	{
		return;
	}
	strcpy(p1 , "11112222");

	printf("p1:%s \n" , p1);
	if(p1 != NULL)
	{
		free(p1); 
	  // 底层相当于将指针指向的内存空间释放掉
	}
	/* 如果再次判断，并释放，这时候会出现宕机  */
	if(p1 != NULL)  //此时,p1还是原来的地址值。原来指向的内存空间的被释放，结果出现了乱指向，就是野指针
		            /* 指针变量和指针所指向的内存空间，两个不同的概念 */
	{
		free(p1);
	}

	printf("hello...\n");
	system("pause");

	return ;

//**********************************************************************
	/* /* 特别注意： 出现宕机 --擦屁股 */
	void main()
	{
		char *p1  = NULL;
		p1 = (char *)malloc(100);
		if(p1 == NULL)
		{
			return;
		}
		strcpy(p1 , "11112222");

		printf("p1:%s \n" , p1);
		if(p1 != NULL)
		{
			free(p1); 
			// 底层相当于将指针指向的内存空间释放掉
			p1 = NULL  ;  //把你屁股擦干净 ，清空原指针变量的值
		}
		
		if(p1 != NULL)  /
		{
			free(p1);
		}

		printf("hello...\n");
		system("pause");

		return ;
	} 
//**********************************************************************