/*
	1、有一个字符串口开头或结尾含义n个空格（“    abcedgg   ”），
	   欲去掉前后空格，返回一个新的字符串。

		要求1、自定义一个接口函数，并实现功能
		要求2、编写测试用例
		int trimSpace(char *inbuf, char *outbuf)
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/* 没有问题 */
int trimSpace(char *inbuf, char *outbuf)
{
	int ret = 0;
	int i = 0;
	char *myinbuf = inbuf;
	char *myoutbuf = outbuf;

	if(myinbuf == NULL || myoutbuf == NULL)
	{
		ret = -1;
		printf("func trimSpace err : %d (myinbuf == NULL || myoutbuf == NULL)\n", ret);
		return ret;
	}

	while(*myinbuf == ' ')
	{
		myinbuf++;
	}
	while((*myoutbuf = *myinbuf) != ' ')
	{
		myinbuf++;
		myoutbuf++;
	}

	return ret;
}

void main()
{
	int ret = 0;
	char * inbuf = "    abcedgg   ";
	char outbuf[200] = {0};


	ret = trimSpace(inbuf, outbuf);
	if(ret != 0)
	{
		printf("func trimSpace err \n");
		return ;
	}
	printf("outbuf :%s \n", outbuf);

	printf("hello...\n");
	system("pause");

	return ;
}
//*******************************************************************************************