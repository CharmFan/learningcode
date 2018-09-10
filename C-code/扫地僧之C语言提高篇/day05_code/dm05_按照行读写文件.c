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
/*
	百度补充： 文件句柄
		在文件I/O中，要从一个文件读取数据，应用程序首先要调用操作系统函数并传送文件名，
		并选一个到该文件的路径来打开文件。该函数取回一个顺序号，即文件句柄（file handle），
		该文件句柄对于打开的文件是唯一的识别依据。要从文件中读取一块数据，应用程序需要调用函数ReadFile，
		并将文件句柄在内存中的地址和要拷贝的字节数传送给操作系统。当完成任务后，再通过调用系统函数来关闭该文件。

*/

void main01_fputs()
{
	FILE *fp = NULL;
	int i = 0;
	//char *filename = "d:\\1.txt";	//我C盘不能操作
	char *filename = "d:/2.txt";	//统一用45度， windows 和 linux系统用这个
	char a[27] = "ahiisilkskd";

	//fp = fopen(filename, "r+");  //读和写方式  打开文件 文件不存在，则报错
	fp = fopen(filename, "w+");  //读和写方式  打开文件 文件不存在，则新建文件

	if (fp == NULL)
	{
		printf("func fopen() err : %d \n");
		return ;
	}
	printf("打开成功\n");

	/*
	for (i=0; i<strlen(a); i++)
	{
		fputc(a[i], fp);
	}
	*/
	fputs(a, fp);

	if (fp != NULL)
	{
		fclose(fp);
	}

	return ;
}

void main01_fgets()
{
	FILE *fp = NULL;
	int i = 0;
	//char *filename = "d:\\1.txt";	//我C盘不能操作
	char *filename = "d:/2.txt";	//统一用45度， windows 和 linux系统用这个

	char buf[1024] = {0};

	fp = fopen(filename, "r+");
	if (fp == NULL)
	{
		printf("func fopen() err : %d \n");
		return ;
	}
	printf("打开成功\n");

	// 1、C函数库 会一行一行的copy数据 到buf指针所指向的内存空间中，并且变成c的字符串
	// 2、把 \n 也copy到我们的buf中
	// 3、内存打包 (把内存首地址 + 内存的长度)
	while (!feof(fp))
	{
		//_Check_return_opt_ _CRTIMP char * __cdecl fgets(_Out_writes_z_(_MaxCount) char * _Buf, _In_ int _MaxCount, _Inout_ FILE * _File);
		char *p = fgets(buf, 1024, fp); //C函数库 会一行一行的copy数据 到buf指针所指向的内存空间中，并且变成c的字符串
		if (p == NULL)
		{
			goto End;
		}
		printf("%s", buf);  //当有多行时，读多次！
	}

End:
	if (fp != NULL)
	{
		fclose(fp);
	}

	return ;
}

void main()
{
	//main01_fputs();
	main01_fgets();

	printf("\nhello... \n");
	system("pause");
	return;
}