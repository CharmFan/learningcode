#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*
	��һ���ַ�����������������"abcdef,acccd,eeee,aaaa,e3eeee,ssss,"��Ҫ��дһ���������ӿڣ���������½��
	1���Զ��ŷָ��ַ������γɶ�ά���飬���ѽ������
	2���Ѷ�ά��������������Ҳ����

	*************************  �������� �����ڴ� *******************
	int spitString(const char *buf1, char c, char **myp, int *count)	
*/
//�������ֵָ����� �� �����߼�֮��Ĺ�ϵ

/* 
  *************************  ��������ָ����� �� �ַ��� **************************
  *****************************   ����ָ��    ************************************
   *********************    ���������������ڴ�   *******************************  
*/

int spitString(const char *buf1, char c, char **myp/*in*/, int *count)
{
	char *p = NULL, *pTmp = NULL;
	int tmpcount = 0;

	if(buf1 == NULL ||myp ==NULL || count == NULL)
	{
		return -1;
	}
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
				strncpy(myp[tmpcount], pTmp, p-pTmp);
				myp[tmpcount][p-pTmp] = '\0';
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

	char **p = NULL;  //�����char buf[10][30]  /*** �ж�����ڴ� ***/

	p = (char **)malloc(10 * sizeof(char *)); // char * array[10]
	if(p == NULL)
	{
		return ;
	}

	for(i=0; i<10; i++)
	{
		p[i] = (char *)malloc(30 * sizeof(char));
		if(p[i]  == NULL)
		{
			return ;
		}
	}
	ret = spitString(p1, cTem, p, &nCount);
	if(ret != 0)
	{
		printf("func spitString() err : %d \n", ret);
	}

	for(i=0; i<nCount; i++)
	{
		printf("%s\n", p[i]);
	}

	//�ͷ��ڴ�
	for(i=0; i<10; i++)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;

	printf("hello...\n");
	system("pause");

	return ;
}