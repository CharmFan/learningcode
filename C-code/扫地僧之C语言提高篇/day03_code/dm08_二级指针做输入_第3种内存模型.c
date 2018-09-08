#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//*****************************    ����ָ��������  ��3���ڴ�ģ��    ********************
//************************************     �ֹ���ά�ڴ�    *****************************

void main11()
{
	int i = 0;
	int j = 0;
	char **p2 = NULL;
	int num = 5;
	char * tmp = NULL;
	char tmpbuf[100] = {0};

	p2 = (char **)malloc(sizeof(char *) * num);

	for(i=0; i<5; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * num);
		sprintf(p2[i], "%d%d%d", i+1, i+1, i+1); //��κ���
	}

	//����֮ǰ
	printf("����֮ǰ \n");
	for(i=0; i<num; i++)
	{
		printf("%s \n", p2[i]);
	}

	//����  /*  ������ָ��  */
	for(i=0; i<num; i++)
	{
		for(j=i+1; j<num; j++)
		{
			if(strcmp(p2[i], p2[j]) < 0)
			{
				tmp	= p2[i];
				p2[i] = p2[j];
				p2[j] = tmp;
			}
		}
	}
	printf("����֮�� \n");
	for(i=0; i<num; i++)
	{
		printf("%s \n", p2[i]);
	}

	//����  /*  �������ڴ�  */
	for(i=0; i<num; i++)
	{
		for(j=i+1; j<num; j++)
		{
			if(strcmp(p2[i], p2[j]) > 0)
			{
				strcpy(tmpbuf, p2[i]);
				strcpy(p2[i], p2[j]);
				strcpy(p2[j], tmpbuf);
			}
		}
	}

	printf("����֮�� \n");
	for(i=0; i<num; i++)
	{
		printf("%s \n", p2[i]);
	}

	//�Ƿ��ڴ�
	for(i=0; i<num; i++)
	{
		if(p2[i] != NULL)
		{
			free(p2[i]);
			p2[i] = NULL;
		}
	}
	
	printf("hello...\n");
	system("pause");
	return ;
}
//**********************************************************************************************
char ** getMem(int num)
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

void getFree(char **p2, int num)
{
	int i = 0;
	for(i=0; i<num; i++)
	{
		if(p2[i] != NULL)
		{
			free(p2[i]);
			p2[i] = NULL;
		}
	}

	if(p2 != NULL)
	{
		free(p2);
		//p2 = NULL;
	}
}
void main()
{
	int j = 0;
	int num = 5;
	char * tmp = NULL;
	char tmpbuf[100] = {0};
	char **p2 = NULL;

	p2 = getMem(num);

	//����֮ǰ
	printf("����֮ǰ \n");
    printfArray(p2, num);

	//����
	sortArray(p2, num);

	//����֮��
	printf("����֮�� \n");
	printfArray(p2, num);

	getFree(p2, num);   /* ���ú����� =====>p2��һ��Ұָ�� */

	printf("hello...\n");
	system("pause");
	return ;
}