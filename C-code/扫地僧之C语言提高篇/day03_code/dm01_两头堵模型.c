#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void main11()
{
	//��ǿո���ַ�����
	char *p = "     abcdefg    ";
	int i, j = 0;
	int ncount = 0;
	i = 0;
	j = strlen(p)-1;

	while(isspace(p[i]) && p[i]!='\0' )
	{
		i++;
	}

	while(isspace(p[j]) && p[j]!='\0' )
	{
		j--;
	}
	
	ncount = j - i + 1;

	printf("ncount : %d \n",ncount);

	printf("hello...\n");
	system("pause");

	return 0;
}

//**********************************************************************************
int getCount(char *str, int *pCount)
{
	char *p = str;
	int ncount = 0;
	int ret = 0;

	int i, j = 0;
	i = 0;
	j = strlen(p)-1;

	if(str == NULL || pCount == NULL)
	{
		ret = -1 ;
		printf("func trimSpcae err\n");
		return ret;
	}

	while(isspace(p[i]) && p[i]!='\0' )
	{
		i++;
	}

	while(isspace(p[j]) && p[j]!='\0' )
	{
		j--;
	}

	ncount = j - i + 1;
	*pCount = ncount;

	return ret;
}

//ȥ���ַ���ǰ��ո�
//������ҵ1
int trimSpcae02(char *str, char *newstr)
{
	int ret = 0;
	char *p = str;
	int i, j ;
	int ncount = 0;

	i = 0;
	j = strlen(p)-1;

	if(p == NULL || newstr == NULL)
	{
		ret = -1 ;
		printf("func err\n");
		return ret;
	}

	while(isspace(p[i]) && p[i]!='\0' )
	{
		i++;
	}

	while(isspace(p[j]) && p[j]!='\0' )
	{
		j--;
	}

	ncount = j - i + 1;
	strncpy(newstr, str+i, ncount);
	newstr[ncount] = '\0';

	return ret;
}
void main02()
{
	char *p = "  abcdefg   ";
	int num = 0;
	int ret = 0;
	char buf[100] = {0};

	ret = getCount(p, &num);
	if(ret != 0)
	{
		printf("func1 err \n");
		return ;
	}
	printf("num : %d \n", num);


	ret = trimSpcae02(p, buf);
	if(ret != 0)
	{
		printf("func2 err \n");
		return ;
	}
	printf("buf : %s \n", buf);


	printf("hello...\n");
	system("pause");
	return ;
}
//*************************************************************************

/*************   �������룻Ҳ���������������ر�ע��  ********************
	ע�⣺strָ����ڴ�ռ䣬���Ա��޸ģ����� ����������	

���Ҫ���߱��ˣ�ָ���ܲ��ܱ��޸ģ�*********  ��һ��const����   ********
int trimSpcae(const char *str)   
**/
int trimSpcae(char *str)
{
	int ret = 0;
	char *p = str;
	int i, j ;
	int ncount = 0;

	i = 0;
	j = strlen(p)-1;

	if(p == NULL)
	{
		ret = -1 ;
		printf("func err\n");
		return ret;
	}

	while(isspace(p[i]) && p[i]!='\0' )
	{
		i++;
	}

	while(isspace(p[j]) && p[j]!='\0' )
	{
		j--;
	}

	ncount = j - i + 1;
	strncpy(str, str+i, ncount);
	str[ncount] = '\0';

	return ret;
}

void main()
{
	//***************************  ����崻�����  ********************************

	//char *p = "  abcdefg   ";  ����ֱ������;��ʱ���������� : �����������ܱ��޸ģ�

	/*���з�ʽ����*/
	char p[] = "   abcdefg   ";  //��ʱ���������� ����ʱ�����ܱ��޸ģ�
	
	//***************************  ����崻�����  ********************************

	int ret = 0;
	char buf[100] = {0};

	ret = trimSpcae(p);
	if(ret != 0)
	{
		printf("func1 err \n");
		return ;
	}
	
	printf("buf : %s \n", p);

	system("pause");
	return ;
}