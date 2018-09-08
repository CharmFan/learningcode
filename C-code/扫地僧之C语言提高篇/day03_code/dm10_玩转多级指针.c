#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//��������Ƕ���ָ��ĵ������ڴ�ģ���еĺ���
char ** getMem11(int num)
{
	int i = 0;
	char **p2 = NULL;
	p2 = (char **)malloc(sizeof(char *) * num);
	if(p2 == NULL)
	{
		return NULL;
	}

	for(i=0; i<5; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * num);
		sprintf(p2[i], "%d%d%d", i+1, i+1, i+1); //��κ���
	}
	
	return p2;
}
//*************************************************************
//������ĺ��� ��д Ϊ��������ʽ�ĺ���

int  getMem(char ***p3, int num)
{
	int i = 0;
	char **tmp = NULL;
	
	if(p3 == NULL)
	{
		return -1;
	}

	tmp = (char **)malloc(sizeof(char *) * num);
	if(tmp == NULL)
	{
		return -1;
	}
	for(i=0; i<5; i++)
	{
		tmp[i] = (char *)malloc(sizeof(char) * num);
		sprintf(tmp[i], "%d%d%d", i+1, i+1, i+1); //��κ���
	}

	*p3 = tmp;

	return 0;
}

int getFree(char ***p3, int num)
{
	int i = 0;
	char **tmp = NULL;
	if(p3 == NULL)
	{
		return -1;
	}

	tmp = *p3;
	if(tmp == NULL)   //���ڶ���ָ��ĵ�һ���ж�
	{
		return -2;
	}

	for(i=0; i<num; i++)
	{
		if(tmp[i] != NULL)
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}
	}

	free(tmp);
	*p3 = NULL;

	return 0;	 //��ʵ�θ�ֵ��ΪNULL
}

//�����������������˻�Ϊָ�룬�ӳ���
//��һ���ڴ�ģ�͵� "��ӡ" ����
void printfArray(char **myArray,int num)
{
	int i =0;

	for(i=0; i<num; i++)
	{
		//printf("%s \n",MYaRRAY[i]);
		printf("%s \n",*(myArray+i));
	}
}
//��һ���ڴ�ģ�͵� "����" ����
void sortArray(char **myArray, int num)
{
	int i = 0, j = 0;
	char *tmp =NULL;

	for(i=0; i<num; i++)
	{
		for(j=i+1; j<num; j++) 
		{
			if(strcmp(myArray[i],myArray[j]) < 0)
			{
				tmp = myArray[i];      //������������Ԫ�أ���������ָ���ֵ
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

void main()
{
	int j = 0;
	int num = 5;
	char **tmp = NULL;
	char tmpbuf[100] = {0};
	char **p2 = NULL;

	getMem(&p2, num);

	printfArray(p2, num);

	getFree(&p2, num);

	printf("hello...\n");
	system("pause");
	return ;
}