#define  _CRT_SECURE_NO_WARNINGS

#include "stdlib.h"
#include "string.h"

#include "stdio.h"

void main()
{
	//********************************************
	int a;
	int b;            //告诉编译器分配内存
	char * p;
	//********************************************
	a = 10;             //在CPU里边执行
	//*********************************************

	//&a:9566408
	printf("&a:%d\n",&a);
	*((int*)16121504) = 200;
	{
		p  = (char *)16121504;
		*p = 300;
	}
	printf("a:%d\n",a);
	printf("hello...\n");
	system("pause");
	return;
}