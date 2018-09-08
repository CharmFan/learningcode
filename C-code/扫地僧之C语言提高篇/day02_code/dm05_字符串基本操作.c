#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*一级指针的典型
	1、数组
	2、字符串

字符串的基本操作
	1、c语言的字符串，以零结尾的字符串
	2、c语言中没有字符串类型，通过字符数组 来模拟字符串
	3、字符串的内存分配可在  堆上 栈上 全局区（很重要）
*/

/*字符数组 初始化
	1、指定长度
	2、不指定长度
*/
void main51()
{
	//1、指定长度
	char  buf[100] = {'1', '2', '3', '4'};     //  buf[4]-buf[99]  自动补零
	//char  buf1[2]  =  {'1', '2', '3', '4'};  //如果初始化的个数大于内存的个数  不编译错误

	//2、不指定长度
    char  buf2[] = {'1', '2', '3', '4'};  //buf2是一个数组， 不是一个以 0 结尾的字符串


	printf("hello...\n");
	system("pause");

	return ;
}

//*************************************************************************************
//字符串  来 初始化字符数组
//  strlen()   长度 不包括 0
//  sizeof()   内存块的大小
void main52()
{
	int size = 0;
	char buf[] = "abcd"; //buf 作为字符数组 应该是5个字节
						 //buf 作为字符串   应该是4个字节
	int len = strlen(buf);
	printf("buf字符的长度：%d\n",len);      //****   结果为4  ***

	//buf作为数组 数组是一种数据类型，本质（固定大小内存块的别名）
	size = sizeof(buf);
	printf("buf数组所占内存空间大小：%d\n",size);   //****   结果为5  ***

	printf("hello...\n");
	system("pause");

	return ;
}

//*************************************************************************************
//通过数组下标  和 指针

// [ ]  *  推导过程
// buf[i] ===> buf[0+i] ===> *(buf+i)
// [] 的本质 和 *p 是一样，只不过符合程序员的阅读习惯

//这里的buf指：数组名
// buf 是一个指针， 只读的常量，buf是一个常量指针
// 为什么呢？
// 析构内存的时候，保证buf所指向的内存空间的安全释放（比如：在临时区定义，如果buf很容易改变，导致无法释放内存）
//  **  指针变量  与 数组首地址的区别**
void main()
{
	int i = 0;
	char *p = NULL;
	char buf[128] = "abcdef";

	for(i=0; i<strlen(buf); i++)
	{
		printf("%c  ", buf[i]);
	}

	p = buf; //buf 代表数组首元素的地址 
	for(i=0; i<strlen(buf); i++)
	{
		printf("%c  ", *(p+i) );
	}

	for(i=0; i<strlen(buf); i++)
	{
		printf("%c  ", *(buf+i) );
	}

	printf("hello...\n");
	system("pause");
	return ;
}
