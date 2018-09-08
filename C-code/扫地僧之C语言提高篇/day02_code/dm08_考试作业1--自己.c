/*
	1����һ���ַ����ڿ�ͷ���β����n���ո񣨡�    abcedgg   ������
	   ��ȥ��ǰ��ո񣬷���һ���µ��ַ�����

		Ҫ��1���Զ���һ���ӿں�������ʵ�ֹ���
		Ҫ��2����д��������
		int trimSpace(char *inbuf, char *outbuf)
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/* û������ */
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