#define  _CRT_SECURE_NO_WARNINGS

#include "stdlib.h"
#include "string.h"

#include "stdio.h"

void main()
{
	//********************************************
	int a;
	int b;            //���߱����������ڴ�
	char * p;
	//********************************************
	a = 10;             //��CPU���ִ��
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