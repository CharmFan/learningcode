#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//ջ�Ŀ������� ���£� ����Debug �� Release
//һ����Ϊ����������
//����ջ�������ϻ������£�buf���ڴ��ַbuf+1����Զ���ϵġ�

/***** ջ�����������buf���ڴ�����������������ͬ�ĸ���****/

void main()
{
	int a,b ;
	char buf[128]; //��̬ �����ʱ��buf��������ڴ�ռ�ı�ţ����Ѿ�����������

	printf("&a:%d , &b:%d\n ",&a, &b);

	printf("hello...\n");
	system("pause");

	return ;
}

