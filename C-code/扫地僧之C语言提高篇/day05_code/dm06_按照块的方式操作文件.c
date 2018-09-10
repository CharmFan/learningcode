#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********************  横向学习  ***********  纵向学习  *****************************

	学习分为：横向学习   纵向学习

	横向学习：快速的把这个知识领域的API占有就可以了，占有越快，你接受的越快，能力就越强
	   比如：学习文件、学习网络编程、学习数据库变成或者学习调用别人业务流的编程

	纵向学习：这个知识点太重要，整个c语言 c++的知识体系搭建至关重要；
	          甚至c/c++的辐射线作用，能让你快速上手java、php等;努力抠取每一个知识点
	  比如：指针

*********************  横向学习  ***********  纵向学习  *****************************/

//********************  home + shift + end 选中当前鼠标指向的行  *****************

//void socketclient_sent(void *handle, unsigned char *buf, in len)  //典型的内存块打包技术
//void socketclient_sent(void *handle, char *buf)  //言外之意，这个指针指向的内存空间所存放的数据是 “\0” 结尾的数据

struct Teacher
{
	char name[64];
	int age;
}Teacher;

void main_fwrite()
{
	FILE *fp = NULL;
	int i = 0;
	char *filename = "d:/2.txt";	//统一用45度， windows 和 linux系统用这个
	struct Teacher tArray[3] = {0};
	int myN;

	for(i=0; i<3; i++)
	{
		sprintf(tArray[i].name, "%d%d%d", i+1, i+1, i+1);
		tArray[i].age = i + 3;
	}

	fp = fopen(filename, "w+");  //读和写方式  打开文件 文件不存在，则新建文件
	if (fp == NULL)
	{
		printf("建立文件夹失败\n");
		return ;
	}

	for(i=0; i<3; i++)
	{
		//  _Check_return_opt_ _CRTIMP 
		//  size_t __cdecl fwrite(_In_reads_bytes_(_Size*_Count) const void * _Str, _In_ size_t _Size, _In_ size_t _Count, _Inout_ FILE * _File);
		
		//_Count : 写多少次
		//_Str : 从内存块的开始
		//_File : 写入到 文件指针 指向的文件中
		//_Size ： 从内存打包技术

		//函数的返回值  写成功的次数
		myN = fwrite(&tArray[i], sizeof(Teacher), 1, fp);
  		//myN 判断  有没有写满 磁盘	
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
	char *filename = "d:/2.txt";	//统一用45度， windows 和 linux系统用这个
	struct Teacher tArray[3] = {0};
	int myN;

	fp = fopen(filename, "rb");  //读和写方式  打开文件 文件不存在，则新建文件
	if (fp == NULL)
	{
		printf("建立文件夹失败\n");
		return ;
	}

	for(i=0; i<3; i++)
	{
		//**********  home + shift + end 选中当前鼠标指向的行  *****************
		// _Check_return_opt_ _CRTIMP 
		// size_t __cdecl fread(_Out_writes_bytes_(_ElementSize*_Count) void * _DstBuf, _In_ size_t _ElementSize, _In_ size_t _Count, _Inout_ FILE * _File);
	
		//函数的返回值  读成功的次数
		myN = fread(&tArray[i], sizeof(Teacher), 1, fp);
		//myN 判断  有没有写满 磁盘	
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