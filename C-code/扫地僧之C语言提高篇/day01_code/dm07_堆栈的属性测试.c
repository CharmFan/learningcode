#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//栈的开口向上 向下， 测试Debug 和 Release
//一般认为：开口向下
//不管栈开口向上还是向下，buf的内存地址buf+1，永远向上的。

/***** 栈的生长方向和buf的内存增长方向是两个不同的概念****/

void main()
{
	int a,b ;
	char buf[128]; //静态 编译的时候，buf所代表的内存空间的标号，就已经定义下来了

	printf("&a:%d , &b:%d\n ",&a, &b);

	printf("hello...\n");
	system("pause");

	return ;
}

