#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//�Ѷ�ά���鵱�� 1ά��������ӡ ֤�����Դ洢              
void printArray(int *b,int size)
{
	int  i= 0;

	for(i=0; i<size; i++)
	{
		printf("%d ",b[i]);
	}
}

void main()
{
	int a[3][5], i=0, j=0;
	int tmp = 1;

	for(i=0; i<3; i++)
	{
		for(j=0; j<5; j++)
		{
			a[i][j] = tmp++;
		}
	}

	//�Ѷ�ά���鵱�� 1ά��������ӡ ֤�����Դ洢
	printArray((int *)a,15);

	printf("hello... \n");
	system("pause");
	return ;
}