#define _CRT_SECURE_NO_WARNINGS
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

//********************  home + shift + end ѡ�е�ǰ���ָ�����  *****************

//void socketclient_sent(void *handle, unsigned char *buf, in len)  //���͵��ڴ��������
//void socketclient_sent(void *handle, char *buf)  //����֮�⣬���ָ��ָ����ڴ�ռ�����ŵ������� ��\0�� ��β������

struct Teacher
{
	char name[64];
	int age;
}Teacher;

void main_fwrite()
{
	FILE *fp = NULL;
	int i = 0;
	char *filename = "d:/2.txt";	//ͳһ��45�ȣ� windows �� linuxϵͳ�����
	struct Teacher tArray[3] = {0};
	int myN;

	for(i=0; i<3; i++)
	{
		sprintf(tArray[i].name, "%d%d%d", i+1, i+1, i+1);
		tArray[i].age = i + 3;
	}

	fp = fopen(filename, "w+");  //����д��ʽ  ���ļ� �ļ������ڣ����½��ļ�
	if (fp == NULL)
	{
		printf("�����ļ���ʧ��\n");
		return ;
	}

	for(i=0; i<3; i++)
	{
		//  _Check_return_opt_ _CRTIMP 
		//  size_t __cdecl fwrite(_In_reads_bytes_(_Size*_Count) const void * _Str, _In_ size_t _Size, _In_ size_t _Count, _Inout_ FILE * _File);
		
		//_Count : д���ٴ�
		//_Str : ���ڴ��Ŀ�ʼ
		//_File : д�뵽 �ļ�ָ�� ָ����ļ���
		//_Size �� ���ڴ�������

		//�����ķ���ֵ  д�ɹ��Ĵ���
		myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);
  		//myN �ж�  ��û��д�� ����	
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
}


void main_fread()
{
	FILE *fp = NULL;
	int i = 0;
	char *filename = "d:/2.txt";	//ͳһ��45�ȣ� windows �� linuxϵͳ�����
	struct Teacher tArray[3] = {0};
	int myN;

	fp = fopen(filename, "rb");  //����д��ʽ  ���ļ� �ļ������ڣ����½��ļ�
	if (fp == NULL)
	{
		printf("�����ļ���ʧ��\n");
		return ;
	}

	for(i=0; i<3; i++)
	{
		//**********  home + shift + end ѡ�е�ǰ���ָ�����  *****************
		// _Check_return_opt_ _CRTIMP 
		// size_t __cdecl fread(_Out_writes_bytes_(_ElementSize*_Count) void * _DstBuf, _In_ size_t _ElementSize, _In_ size_t _Count, _Inout_ FILE * _File);
	
		//�����ķ���ֵ  ���ɹ��Ĵ���
		myN = fread(&tArray[i], sizeof(Teacher), 1, fp);
		//myN �ж�  ��û��д�� ����	
	}
	for(i=0; i<3; i++)
	{
		printf("name : %s, age :%d \n", tArray[i].name, tArray[i].age);
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
}
void main()
{
	main_fwrite();
	main_fread();

	printf("\nhello... \n");
	system("pause");
	return;
}