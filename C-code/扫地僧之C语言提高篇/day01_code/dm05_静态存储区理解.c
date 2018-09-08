#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

char * getStr1()
{
	char * p1  = "abcdefg";
	return p1;
}

char * getStr2()
{
	char * p2 = "abcdefg1";
	return p2;
}

void main()
{
	char *p1 = NULL;
	char *p2 = NULL;
	
	p1 = getStr1();
	p2 = getStr2();

	//*********   打印p1 、p2所指向的空间的数据  **********//
	printf("p1:%s，p2:%s\n", p1, p2);

	//*********   打印p1、p2的值			*******//
	printf("p1:%d, p2:%d\n", p1, p2);

	printf("hello...\n");
	system("pause");
	return;
}

/**************************************
  画出内存四区好好理解之

	全局区--理解部分：

	getStr1()中  char * p1  = "abcdefg";
	getStr2()中  char * p1  = "abcdefg2";
		 p1 p2值 ：有差

	getStr1()中  char * p1  = "abcdefg";
	getStr2()中  char * p1  = "abcdefg";
	      p1 p2值 ：相等   

 "abcdefg2";  abcdefg" p1 p2的指向内容：

	c++编译器对其进行 词法分析 语法分析 句法分析
    然后对代码进行优化，如果发现内容一样，只会保留一份。
	   
****************************************/