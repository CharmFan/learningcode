#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
/*
	��һ���ַ�����������������"abcdef, acccd, eeee, aaaa, e3eeee,ssss,"��Ҫ��дһ���������ӿڣ���������½��
	1���Զ��ŷָ��ַ������γɶ�ά���飬���ѽ������
	2���Ѷ�ά��������������Ҳ����
*/


/*************************  ��������ָ����� �� �ַ��� ****************************/

//�������ֵָ����� �� �����߼�֮��Ĺ�ϵ
int spitString(const char *buf1, char c, char buf2[10][30], int *count)
{
	char *p =NULL, *pTmp = NULL;
	int tmpcount = 0;

	//1�� p �� pTmp ��ʼ��
	p = buf1;
	pTmp = buf1; 

	do
	{
		//2�� ��������������λ�� p���� �γɲ�ֵ ���ַ���
		p = strchr(p, c);
		if(p != NULL)
		{
			if(p-pTmp > 0)
			{
				strncpy(buf2[tmpcount], pTmp, p-pTmp);
				buf2[tmpcount][p-pTmp] = '\0';	
				tmpcount++;
				//3������ ��p��ptmp �ﵽ��һ�μ���������
				pTmp = p = p +1;
			}
			else
			{
				break;
			}
		}
	}while(*p != '\0');

	*count = tmpcount;

	return 0;
}

void main()
{	
	char *p1 = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	char ret = 0;
	int i = 0;
	char cTem = ',';
	int nCount = 0;
	char myArray[10][30];

	ret = spitString(p1, cTem, myArray, &nCount);
	if(ret != 0)
	{
		printf("func spitString() err : %d \n", ret);
	}

	for(i=0; i<nCount; i++)
	{
		printf("%s \n", myArray[i]);
	}
	printf("hello...\n");
	system("pause");

	return ;
}

/*
��ҵһ�������ڴ�ģ�����   �����������ʽ
	char **spitString(const char *buf1, char c,  int *count)
	int spitString2(const char *buf1, char c, char ***p, int *count)


��ҵ������һ���ַ���������������("abcd11111abcd2222abcdqqqqq"),Ҫ��дһ���������ӿڣ�
������½��
	1�����ַ����Դ���"abcd"�����ֵĴ��������ѽ��������
	2�����ַ����滻�ɣ�dcba11111dcba2222dcbaqqqqq��,���ѽ��������
	int getRsetbuf(const chaar *buf1, int buflen, int *count, char * buf2)
*/