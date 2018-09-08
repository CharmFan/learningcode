#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/************************  指针数组的用法  1、菜单 *********************/
//关键字在表中的位置
//一个入口  多个出口

//int  searchKeyTable(const char **table, const int size, const char *key, int *pos)  和下面一样的
int  searchKeyTable(const char *table[], const int size, const char *key, int *pos)
{
	int rv = 0;
	int i = 0;
	int inum = 0;

	if(table==NULL || key==NULL || pos==NULL)
	{
		rv = -1;
		printf("func searchKeyTable : %d \n", rv);
		return rv;
	}

	/***********************     退化问题  传参之后    ****************************/
	//间接的证明了   数组的做函数的参数的退化问题
	//二级指针 除 一级指针 
	inum = (sizeof(table))/sizeof(*table);    //结果是: 4/4 = 1  此时这里是指针，不再是数组。
	printf("inum : %d \n", inum);
	/***********************     退化问题  传参之后    ****************************/

	for(i=0; i<size; i++)
	{
		if(strcmp(key, table[i]) == 0)
		{
			*pos = i;
			return rv;
		}
	}

	//没有找到返回 -1
	if(i == size)
	{
		*pos = -1;
	}

	return rv;
}

#define DIM(a) (sizeof(a)/sizeof(*a))

void main11()
{
	int inum = 0;
	int pos = 0;
	int a[10];
	int i = 0;

	// 指针数组
	char * c_keyword[] = {
		"while",
		"case",
		"static",
		"do"
	};

	/***********************     退化问题   传参之前   ****************************/
	printf("DIM(c_keyword) : %d \n", DIM(c_keyword));    //结果是  4  此时这里是数组。
	/***********************     退化问题   传参之前   ****************************/

	searchKeyTable(c_keyword, DIM(c_keyword), "do", &pos);
	//带参数的宏
	//searchKeyTable(c_keyword, (sizeof(c_keyword)/sizeof(*c_keyword)), "do", &pos);
	printf("pos : %d\n", pos);


	printf("-------------------------------------------------------------------\n");
	searchKeyTable(c_keyword, DIM(c_keyword), "static", &pos);
	printf("pos : %d\n", pos);

	printf("hello...\n");
	system("pause");
	return ;
}



/*********************************  指针数组的用法   2、命令行 *********************/
/*
	argc 命令行
	argv 命令行数组
	env  函数变量数组

	int main()
	int main(int argc)
	int main(int argc, char argv[])
*/

//理解指针的关键是看这个内存空间是谁给分配的，什么地方分配
//请问 char* argv[], char **env 这两个内存空间是谁分配的，在什么地方分配的呢？
/*
	是操作系统把我们应用程序给我们拉起来了，言外之意是我们双击这个软件，操作系统支持我们软件运行，
	操作系统帮我们打造了系统，打造以后；main函数是操作系统和我们应用程序交互的入口。
	言外之意，操作系统会提前分配内存，分配好内存以后，把我们应用程序的内存四区给我们搭建起来。堆区 、栈区、 全局区、代码区
	之后，把打造好的内存空间，（ char* argv[]） 通过指针做函数参数，把内存首地址传到我们被调函数里边，
	我们程序就可以使用操作系给我们提供的环境，
	char **env 应该是环境变量的信息 ，应该是系统环境变量配置的所有信息

	怎么确定一行一行的数据怎么结束的呢?   在数据结束地方加了‘\0’
*/

/*
	int main(int argc, char* argv[], char **env)
	在我们看来 ： 是程序的入口
	在操作系统看来 ： 是它调用的一个函数

	如果我们在使用别是写的API函数，一定要清楚这个API函数写在哪一个框架下的，
	进一步说 ***

	比如 以后们要写驱动
		在linux的内核开发，假如写驱动在，中间是一道坎坎，上面是应用程序，下面是驱动； 在linux的内核中
		有很多模块，进程管理模块，内存管理模块，驱动管理模块，c语言的库函数调用，网络协议栈。
		不停从用户空间切换到内核空间。 在比如给华为做网络协议栈，肯定是做一个驱动，肯定是接触驱动这一小块，
		言外之意，你会看和驱动和内存协议栈向相关的API函数
		你会发现里边有一大堆API函数，怎么看懂这个函数，这个API函数是被操作系统的源码的tcp/ip的协议栈给调用，言外之意说，

			比如：其中这个一个里边的函数 searchKeyTable(const char *table[], const int size, const char *key, int *pos)
		tcp/ip的协议栈 提前给我分配内存，const char *table[] 传到这个函数，我只需要在函数里边填空，填空就可以了。
		做驱动开发，我们都是在别人写好的模型之下做开发。

		***********************************************    无论做什么开发，都要知道在什么的框架下。 ***********************************

			同样的道理：做,MFC开发 ，肯定别人把这个类库写好了，直接下这个类库框架之下，搭建自己的应用场景。一样的道理，别人把内存提前分配好了。

		***********************************************    无论做什么开发，都要知道在什么的框架下。 ***********************************
			
*/
int main22(int argc, char* argv[], char **env)
{
	int i = 0;

	printf("*****************  Begin argv ************************\n");
	for(i=0; i<argc; i++)
	{
		printf("%s \n", argv[i]);
	}
	printf("*****************  End argv ************************\n");
	printf("\n \n\n");


	printf("*****************  Begin env ************************\n");

	for(i=0; env[i]!=NULL; i++)//
	{
		printf("%s \n", env[i]);
	}
	printf("*****************  End env ************************\n");


	system("pause");
	return ;
}

/*
	在cmd中切换到该程序的包含  课堂操练.exe文件下
	输入    课堂操练.exe  1111   2222  3333    /等于四个命令行/
	输出：
	  课堂操练.exe  
	  1111   
	  2222  
	  3333  
*/
/*********************************  指针数组的用法   2、命令行 *********************/




/*******************************  指针数组的自我结束的能力   三种的方式 ***********************************/

//  *****************************  三种的方式都是字符串的结束标志  ******************
void main()
{
	int inum = 0;
	int pos = 0;
	int a[10];
	int i = 0;

	// 指针数组
	char * c_keyword[] = {
		"while",
		"case",
		"static",
		"do",
		'\0'   //放在字符串下转意 其实也是 0   //为了给数组指针的自我结束的能力 ,
		                                        //没有这个，执行下边的打印语句，程序会宕机，越界了。
	};
	

	// 指针数组
	char * c_keyword2[] = {
		"while",
		"case",
		"static",
		"do",
		0  
	};


	// 指针数组
	char * c_keyword3[] = {
		"while",
		"case",
		"static", 
		"do",
		NULL        //这个宏定义  #define NULL    0
	};

	for(i=0; c_keyword[i] != NULL; i++)
	{
		printf("%s \n", c_keyword[i]);

	}
	printf("\n.....\n");


	for(i=0; c_keyword2[i] != NULL; i++)
	{
		printf("%s \n", c_keyword2[i]);

	}
	printf("\n.....\n");


	for(i=0; c_keyword3[i] != NULL; i++)

	{
		printf("%s \n", c_keyword3[i]);

	}
	printf("\n.....\n");


	system("pause");
	return ;
}
/**************************     指针数组的自我结束的能力   三种的方式 ***********************************/