#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<malloc.h>

/*
	1、指针指向谁，就把谁地址赋给指针
	2、指针变量和它指向的内存空间变量是两个不同的概念
	3、理解指针的关键，是内存，没有内存哪来的指针
*/

//堆
char * getMen(int num)
{
	char * p1  = NULL;
	p1 = (char *)malloc(sizeof(char) * num);
	if(p1 == NULL)
	{
		return NULL;
	}
	return p1;
} 

//栈
//注意,return 不是吧内存块50字节给return出来，而是把内存块的首地址，给return出来了
char * getMen2()
{
	char buf[50];//临时存放，栈区存放

	strcpy(buf, "9999");
	//printf("栈 buf:%s\n", buf);

	return buf;  //栈区分配的50字节的空间，在此函数调用完成后，被编译器自动释放
	             //但是首地址可以拷贝出来（tmp = getMen2();  将地址拷贝给tmp）,并不是50字的内存空间给拷贝出来了。
                 //而是把内存空间开始的标号给拷贝出来了，就是开始的地方拷贝出来了。
}

void main()
{
	char *tmp = NULL;
	
	tmp = getMen(1);
	if(tmp == NULL)
	{
		return;
	}

	strcpy(tmp, "1025"); //向tmp指向的内存空间中copy数据
	printf("堆 temp:%s\n", tmp);

	tmp = getMen2();
    printf("栈 temp:%s.\n", tmp);

	/*
		在Debug下，打印    "栈 temp:%s."
		在Release下，打印  "栈 temp:9999."
		两种的处理程序不一样，局部变量是不能将内存块转移过来的
	*/

	printf("hello...\n");
	system("pause");
	return;
}

