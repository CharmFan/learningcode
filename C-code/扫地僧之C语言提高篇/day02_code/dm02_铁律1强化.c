#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*************************************
	c���Ծ��� �� �������� �����ڴ��
*************************************/

void main21()
{
	char *p1 = NULL;
	strcpy(p1, "abcdefg"); // 0��ʼ���ڴ�ռ��ǲ���ϵͳ�����ĵ�ַ
	                       //��ʱ��0x000000000
	printf("hello...\n");
	system("pause");

	return ;
}

//��������Ĵ���
void main22()
{
	char *p1 = NULL;
	p1 = 0x000000077;

	strcpy(p1, "abcdefg"); // 0��ʼ���ڴ�ռ��ǲ���ϵͳ�����ĵ�ַ
	//��ʱ��0x000000000
	printf("hello...\n");
	system("pause");

	return ;
}
/* ǿ�������޸�ָ���ָ�� */
void main()
{
	char buf[128];  //c������ջ�Ϸ����ڴ�
	int  i = 0;     /* 0  ��������ȡ��ַ   */
	                //ע�� ��û�з��ڶѺ�ջ�У�0��һ��������   ����ʲô�ط�����˵,���Բ������//
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
