#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//*****************************    ����ָ��������  ��2���ڴ�ģ��    ****************
//************************************     ��ά����    *****************************
//��ӡ ����
//��װ����
void main11()
{
	int i = 0, j = 0;
	int num = 4;
	char myBuf[30];
	char myArray[10][30] = {"aaaaaaa","cccccc","bbbbbbb","333333"};
	
	//��ӡ
	printf("����֮ǰ \n");
	for(i=0; i<num; i++)
	{
		printf("%s \n", myArray[i]);
	}

	//����
	for(i=0; i<num; i++)
	{
		for(j=i+1; j<num; j++)
		{
			if(strcmp(myArray[i], myArray[j]) > 0)
			{
				strcpy(myBuf, myArray[i]);     //�������� �ڴ��
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], myBuf);
			}
		}
	}
	//��ӡ
	printf("����֮�� \n");
	for(i=0; i<num; i++)
	{
		printf("%s \n", myArray[i]);
	}

	system("pause");
	return ;
}
//***********************************************************************
/*           dm07_����ָ��������_��2���ڴ�ģ��  myArray+1
             dm06_����ָ��������_��1���ڴ�ģ��  myArray+1    ��һ��

     ���Ȿ�ʣ�ָ��Ĳ�����һ����ָ����ָָ����ڴ�ռ���������Ͳ�һ��

**************   ����ʱ�����  printfArray11   *************************/
void printfArray11(char **myArray,int num)
{
	int i =0;

	for(i=0; i<num; i++)
	{
		//printf("%s \n",myArray[i]);
		printf("%s \n",*(myArray+i));
	}
}

void printfArray(char myArray[10][30],int num)
{
	int i =0;

	for(i=0; i<num; i++)
	{
		//printf("%s \n",myArray[i]);
		printf("%s \n",*(myArray+i));
	}
}

void sortArray(char myArray[10][30], int num)
{
	int i = 0, j = 0;
	char tmpBuf[30];

	for(i=0; i<num; i++)
	{
		for(j=i+1; j<num; j++) 
		{
			if(strcmp(myArray[i],myArray[j])>0)
			{                                 //��һ�ֽ�������ָ��ֵ
				strcpy(tmpBuf, myArray[i]);  /****** ���������ڴ�� ******/
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], tmpBuf);
			}
		}
	}
}

void main()
{	int n=0,m=0;
	int i = 0, j = 0;
	int num = 4;
	char myBuf[30];
	char tmpBuf[30];
	char myArray[10][30] = {"aaaaaaa","cccccc","bbbbbbb","333333"};  // myArray�Ĳ����� 30
	//myArray ������ֻ����� �� ��10�У�ÿ��30�� 
	//���������ʲô�� ��Ҫ�ǽ���� myArray+1�Ĳ���    >>>��ά�������ı��� 

	{
		int len1 = sizeof(myArray);     //300
		int len2 = sizeof(myArray[0]);  //30
		int len3 = sizeof(myArray);
		int size = len1/ len2;
		printf("len1:%d, len2:%d,len3:%d, size:%d \n",len1, len2,len3, size);
	}
	//��ӡ
	printf("����֮ǰ \n");
	printfArray(myArray, num);


	//����
	sortArray(myArray, num);


	//��ӡ
	printf("����֮�� \n");
	printfArray(myArray, num);


	system("pause");
	return;
}