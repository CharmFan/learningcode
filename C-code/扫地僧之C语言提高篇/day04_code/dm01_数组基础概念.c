#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void main11()
{
	int a[] = {1, 2};    //��ָ������
	int b[100] = {1, 3}; //ָ������

	int c[200] = {0};    //  �����ʱ ���Ѿ�ȷ�� ���е�ֵΪ��
	
	/**********************   ����ä�� ****************************
		��һά���� C�涨
				c��������Ԫ��         ��ַc+1  �� ���� 4���ֽ�
				&c ����������ĵ�ַ   ��ַ&c+1 �� ���� 200*4
	**************************************************************/
	memset(c, 0, sizeof(c));   //��ʾ�� �����ڴ��
	
	system("pause");
	return ;
}

//��ô����� int a[10]�����������ͣ� int[]
//���ͱ��ʣ��̶���С�ڴ��ı���

//������������
void main22()
{
	typedef int (MyArrayType)[5];  //������һ����������  ������������
	int i = 0;
	MyArrayType  myArray;      //int  myArray[5];

	for (i=0; i<5; i++)
	{
		myArray[i] = i + 1;
	}
	for (i=0; i<5; i++)
	{
		printf("%d  ",myArray[i]);
	}
	printf("\n");

	printf("myArray����������Ԫ�صĵ�ַ  myArray:%d   myArray+1:%d \n", myArray, myArray+1);
	printf("&myArray������������ĵ�ַ    &myArray:%d  &myArray+1:%d \n", &myArray, &myArray+1);

	system("pause");
	return ;
}

//��������ָ������ķ���
//************   ��һ�֣����������� *      **********************
void main33()
{
	char * Myarray[] = {"111", "222"};  //ָ������

	//����ָ�� ��һ��ָ��  ��ָ��һ������
	typedef int (MyArrayType)[5]; 
	int i = 0;
	MyArrayType  myArray;   //int  myArray[5]; ���Ͷ������

	MyArrayType *pArray; //����һ��ָ����� ���ָ�����ָ��һ������
	{
		int a;
		int *p = NULL;
		p = &a;
	}
	{
		//pArray   = &myArray;
		int myArray2[5]; //�൱��һ��ָ��
		for(i=0; i<5; i++)
		{
			myArray2[i] = i+1;
		}
		pArray = &myArray2; //�൱�ڶ���ָ��
		for(i=0; i<5; i++)
		{
			printf("%d  ", (*pArray)[i]);
		}
	}

	system("pause");
	return;

}

//��������ָ�����   �ڶ���
void main44()
{
	//��������һ������ָ������
	typedef int (*PArrayType)[5]; 
	int i = 0;
	PArrayType  pArray;   //���߱�����  ���ҷ���һ��ָ�����

	int c[5];
	pArray = &c;
	for(i=0; i<5; i++)
	{
		(*pArray)[i] = i+1;
	}
	for(i=0; i<5; i++)
	{
		printf("%d  ", (*pArray)[i]);
	}
	system("pause");
	return;
}

//��������ָ�����   ������
//ǰ���ַ���  ͨ�����Ͷ������  �Ƚ��鷳
void main()
{
	int (*pArray)[5]; //ֱ�Ӷ���һ��ָ������� ����ָ�����
	int i = 0;
	int c[5];
	pArray = &c;
	for(i=0; i<5; i++)
	{
		(*pArray)[i] = i+1;
	}
	for(i=0; i<5; i++)
	{
		printf("%d  ", (*pArray)[i]);
	}
	system("pause");
	return;
}