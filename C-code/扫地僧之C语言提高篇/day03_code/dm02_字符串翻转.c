#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

char g_buf[100] = {0};
/*
	int inverse(char *str, char *str2)
*/
//��ʽһ��ָ��
void main11()
{
	char buf[] = "abcdefg";
	int length  =strlen(buf);

	char *p1 = buf;
	char *p2 = buf + length -1;

	while(p1 < p2)
	{
		char c = *p1;
		*p1 = *p2;
		*p2 = c;
		++p1;
		--p2;
	}
	printf("buf : %s \n",buf);

	printf("hello...\n");
	system("pause");

	return ;
}

//*********************************************************************************************

int inverse(char *str)
{

	return 1;
}
void main22()
{

}
//********************************************************************************************

/* ���ݹ������㣺
		1����������ջģ��
		2������Ƕ�׵��÷�������
 ���õݹ鷽ʽ,�����ӡ
     ��һ����� : �ݹ��ȫ�ֱ�����������Ľ������ȫ�ֱ�����
     �ڶ������ ���ݹ�ͷ�ȫ�ֱ������ݹ�ָ��������������
 */
//��ʽ�����ݹ�
void inverse02(char *p)
{
	if(p == NULL)   //�ݹ������쳣����
	{
		return ;
	}
	if(*p == '\0')  //�ݹ�Ľ�������
	{
		return ;
	}
	inverse02(p+1);  //ע�⣬��ʱû��ִ�д�ӡ������ִ���� ���ú���
	                 //���ַ�����ÿһ����ַ��ջ
	printf("%c  ", *p);
} 

// ��һ����� : �ݹ��ȫ�ֱ�����������Ľ������ȫ�ֱ�����
//��ʱ������Ƕ��̣߳����ܶ�ȫ�ֱ�����θ�ֵ�����ܻ������롣
void inverse03(char *p)
{
	if(p == NULL)   //�ݹ������쳣����
	{
		return ;
	}
	if(*p == '\0')  //�ݹ�Ľ�������
	{
		return ;
	}
	inverse03(p+1);  //ע�⣬��ʱû��ִ�д�ӡ������ִ���� ���ú���
	                  //���ַ�����ÿһ����ַ��ջ

	/**********  ÿһ�ο���һ���ַ�  **********/

	//strncpy(g_buf,p, 1);     //=====���� ����  ��һ��ʱ��g  �ڶ���ʱ��f(����ǰһ��)
	  strncat(g_buf,p, 1);     //=====���� ����  ��һ��ʱ��g  �ڶ���ʱ��gf������ǰһ����

	/**********  ÿһ�ο���һ���ַ�  **********/
}

//�ڶ������ �� �ݹ�ͷ�ȫ�ֱ������ݹ�ָ��������������
void inverse04(char *p, char * bufresult)
{
	if(p == NULL  || bufresult == NULL)   //�ݹ������쳣����
	{
		return ;
	}
	if(*p == '\0')  //�ݹ�Ľ�������
	{
		return ;
	}
	inverse04(p+1, bufresult);   //ͨ��������������ӡ�ú���⣬bufresult��ʵҲ�ݹ���

	strncat(bufresult, p, 1);     //��������
}

void main()
{
	int ret = 0;
	char buf[] = "dfeg";

	//inverse02(buf);

	//g_bufΪȫ�ֱ�����ǰ���ж���
	//��ʽһ������
	memset(g_buf, 0, sizeof(g_buf));
    inverse03(buf);
	printf("g_buf : %s \n", g_buf);

	{
		//��ʽ�����ݹ����
		char mybuf[1024] ={0};
		inverse04(buf, mybuf);
		printf("mybuf : %s \n", mybuf);		
	}

	system("pause");
	return ;
}