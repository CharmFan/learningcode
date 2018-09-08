#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*************************************
	c语言精华 ： 两个函数 共享内存块
*************************************/

void main21()
{
	char *p1 = NULL;
	strcpy(p1, "abcdefg"); // 0开始的内存空间是操作系统保护的地址
	                       //此时向0x000000000
	printf("hello...\n");
	system("pause");

	return ;
}

//重新上面的错误
void main22()
{
	char *p1 = NULL;
	p1 = 0x000000077;

	strcpy(p1, "abcdefg"); // 0开始的内存空间是操作系统保护的地址
	//此时向0x000000000
	printf("hello...\n");
	system("pause");

	return ;
}
/* 强化不断修改指针的指向 */
void main()
{
	char buf[128];  //c可以在栈上分配内存
	int  i = 0;     /* 0  它不可以取地址   */
	                //注意 ：没有放在堆和栈中，0是一个字面量   放在什么地方不好说,可以查查资料//
	int  j;

	char *p1 = NULL;
	char *p2 = NULL;

	p1 = &buf[1];
	p1 = &buf[2];
	p1 = &buf[3];

	for(i=0; i<10; i++)
	{
		p1 = buf[i];
	}

	p2 = (char *)malloc(100);
	strcpy(p2, "avdfgasrgaserhesahg");
	for(i=0; i<10; i++)
	{
		p1 = p2+i;
		printf("%c ", *p1);
	}

	printf("hello...\n");
	system("pause");

	return ;
}
