#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*
	ע���ϣ�����ָ��������ڴ�ģ��ͼƬ
*/
void main()
{
	int i = 0;
	//ָ������
	char *p1[] = {"123", "456", "789"};

	//��ά����
	char p2[3][4] = {"123", "456", "789"};

	//�ֹ���ά����
	char **p3 = (char **)malloc(3 * sizeof(char *));

	for(i=0; i<3; i++)
	{
		p3[i] = (char *)malloc(sizeof(char) * 3);
		sprintf(p3[i], "%d%d%d", i+1, i+1, i+1); //��κ���
	}

	printf("hello...\n");
	system("pause");

	return ;
}