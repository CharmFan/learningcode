#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********************  ����ѧϰ  ***********  ����ѧϰ  *****************************

	ѧϰ��Ϊ������ѧϰ   ����ѧϰ

	����ѧϰ�����ٵİ����֪ʶ�����APIռ�оͿ����ˣ�ռ��Խ�죬����ܵ�Խ�죬������Խǿ
	   ���磺ѧϰ�ļ���ѧϰ�����̡�ѧϰ���ݿ��ɻ���ѧϰ���ñ���ҵ�����ı��

	����ѧϰ�����֪ʶ��̫��Ҫ������c���� c++��֪ʶ��ϵ�������Ҫ��
	          ����c/c++�ķ��������ã��������������java��php��;Ŭ����ȡÿһ��֪ʶ��
	  ���磺ָ��

*********************  ����ѧϰ  ***********  ����ѧϰ  *****************************/
/*
	�ٶȲ��䣺 �ļ����
		���ļ�I/O�У�Ҫ��һ���ļ���ȡ���ݣ�Ӧ�ó�������Ҫ���ò���ϵͳ�����������ļ�����
		��ѡһ�������ļ���·�������ļ����ú���ȡ��һ��˳��ţ����ļ������file handle����
		���ļ�������ڴ򿪵��ļ���Ψһ��ʶ�����ݡ�Ҫ���ļ��ж�ȡһ�����ݣ�Ӧ�ó�����Ҫ���ú���ReadFile��
		�����ļ�������ڴ��еĵ�ַ��Ҫ�������ֽ������͸�����ϵͳ��������������ͨ������ϵͳ�������رո��ļ���

*/

void main01_fputc()
{
	FILE *fp = NULL;
	int i = 0;
	//char *filename = "d:\\1.txt";	//��C�̲��ܲ���
	char *filename = "d:/2.txt";	//ͳһ��45�ȣ� windows �� linuxϵͳ�����
	char a[27] = "ahiisilkskd";

	fp = fopen(filename, "r+");  //����д��ʽ
	if (fp == NULL)
	{
		printf("func fopen() err : %d \n");
		system("pause");
		return ;
	}
	printf("�򿪳ɹ�\n");

	for (i=0; i<strlen(a); i++)
	{
		fputc(a[i], fp);
	}

	if (fp != NULL)
	{
		fclose(fp);
	}

	return ;
}

void main01_fgetc()
{
	FILE *fp = NULL;
	int i = 0;
	//char *filename = "d:\\1.txt";	//��C�̲��ܲ���
	char *filename = "d:/2.txt";	//ͳһ��45�ȣ� windows �� linuxϵͳ�����
	char a[27] = "ahiisilkskd";

	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		printf("func fopen() err : %d \n");
		system("pause");
		return ;
	}
	printf("�򿪳ɹ�\n");

	while (!feof(fp))
	{
		char tmpc = fgetc(fp);
		printf("%c", tmpc);
	}

	if (fp != NULL)
	{
		fclose(fp);
	}

	return ;
}

void main()
{
	main01_fputc();
	main01_fgetc();

	printf("hello... \n");
	system("pause");
	return;
}