#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//*****************************    ����ָ��������  ��1���ڴ�ģ��    ********************
//****************************************    ָ������    ******************************

//�����������������˻�Ϊָ�룬�ӳ���
void printfArray(char **myArray,int num)
{
	int i =0;

	for(i=0; i<num; i++)
	{
		//printf("%s \n",MYaRRAY[i]);
		printf("%s \n",*(myArray+i));
	}
}

void sortArray(char **myArray, int num)
{
	int i = 0, j = 0;
	char *tmp =NULL;

	for(i=0; i<num; i++)
	{
		for(j=i+1; j<num; j++) 
		{
			if(strcmp(myArray[i],myArray[j])>0)
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
	int i= 0;
	int j= 0;
	int num = 0;
	char *tmp = NULL;
	//�����е�ÿ��Ԫ����ָ��   ָ������
	char *myArray[] = {"AAAAAA","CCCC","BBBBBB","222222"};

	//��ӡ   
	//*********************  ���ַ���ע���ܽ�  *******************
	num = sizeof(myArray)/sizeof(myArray[0]);

	printf("����ǰ \n");
	printfArray(myArray,num);

	//����
	sortArray(myArray,num);


	printf("����� \n");
	printfArray(myArray,num);

	system("pause");
	return ;
}
