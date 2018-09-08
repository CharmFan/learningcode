#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


//字符串的内存分配可在  堆上 栈上 全局区（很重要）

void main()
{
	char buf[21] =  "222222";  //此时的字符串 是在全局区分配内存  （字符串 ）
	char buf[] = "33333333";
	char *p1 = "111111";
	char * p2 = malloc(10);
	strcpy(p2, "4444")''

	printf("hello...\n");
	system("pause");

	return ;
}