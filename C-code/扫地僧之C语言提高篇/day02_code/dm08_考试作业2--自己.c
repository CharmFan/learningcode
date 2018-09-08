/*
	�и��ַ�����1a2b3d4z��
	����1����ż��λ�ַ���ѡ���������һ���ַ���1.
	����2��������λ�ַ���ѡ����������һ���ַ���2.
	����3�����ַ���1���ַ���2��ͨ���������������ݸ�main,����ӡ��
	����4���������ܲ���ͨ��
	int getStr1Str2(char *source, char *buf1, char *buf2)
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int getStr1Str2(char *source, char *buf1, char *buf2)
{
	int ret = 0;
	int flag = 0;
	char *mysource = source;
	char *mybuf1 = buf1;
	char *mybuf2 = buf2;

	if(mysource ==NULL || buf1 ==NULL || buf2 ==NULL)
	{
		ret = -1;
		printf("func getStr1Str2 err :%d (mysource ==NULL || buf1 ==NULL || buf2 ==NULL) \n", ret);
		return ret;
	}
	while(*mysource != '\0')
	{
		flag++;
		if(flag%2 == 0)
		{
			*mybuf1 = *mysource;
			 mybuf1++;		
		}
		else if(flag%2 == 1)
		{
			*mybuf2 = *mysource;
			*mybuf2++;
		}
		mysource++;
	}
	*mybuf2 = '\0';
	*mybuf1 = '\0';

	//*mysource = '\0';

	return ret;
}

void main()
{
	int ret = 0;
	char *source = "1a2b3d4z";
	char buf1[60] = {0};
	char buf2[60] = {0};

	ret = getStr1Str2(source, buf1, buf2);
	if(ret != 0)
	{
		printf("func getStr1Str2() err \n");
		return ;
	}
	printf("buf1 : %s \n", buf1);
	printf("buf2 : %s \n", buf2);

	printf("hello...\n");
	system("pause");

	return ;
}