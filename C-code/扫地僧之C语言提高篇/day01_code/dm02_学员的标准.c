#include "stdlib.h"
#include "string.h"
#include "stdio.h"

//��ӡ
void printArray(int *a, int len)
{
	int i = 0;
	for(i=0; i<len; i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
}

//����
void sortArray(int *a, int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for(i=0; i<5; i++)
	{
		for(j=i+1; j<5; j++)
		{
			if(a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}


//�����������������˻����⣬�˻�һ��ָ��
//���ۣ���������ڴ��׵�ַ���������Ч���ȸ������ú���

//�β��е����飬���������������ָ�봦������c���Ե���ɫ
//����Ҳ�������β�д�ں����ϣ���д�ں�������һ���ģ�ֻ�����Ǿ��ж�������Զ��ѡ�

void main22()
{
	int len = 0;

	int a[]  = {3, 34, 45, 6, 37};
    len = sizeof(a)/sizeof(a[0]);
	printf("len = %d\n",len);

	printf("����֮ǰ\n");
    printArray(a, len);

	//����
    sortArray(a, len);
	printf("����֮��\n");
	printArray(a, len);

	printf("hello...\n");
	system("pause");
	return ;
}
