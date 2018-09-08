#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void main81()                                  
{
	int a = 10;
	char *p1 = NULL;  //分配4个字节的内存
	char *****p2 = NULL;

	int * p3 = NULL;
	p3 = &a;
	*p3 = 254;   //简洁修改a的值
	//指针就像一把钥匙，通过一个地址（&a），去修改a变量的标示的内存

	{
		int c = 0 ;
		c = *p3;
		//*p 放在=左边，写内存
		//*p 放在=右边，读内存
		printf("c:%d \n",c);
	}
	{
		/* 特别注意 ：不断的给指针赋值，相当于不停的改变指针的指向 */
		char *p4;
		p4 = (char *)malloc((sizeof(char) * 5 ));
		p4 = (char *)malloc((sizeof(char) * 5 ));
	}
	printf("a:%d \n", a);
	printf("地址大小 a:%d , p1:%d , p2 :%d\n ", sizeof(a), sizeof(p1), sizeof(p2));
	printf("hello...\n");
	system("pause");

	return ;
}

//********************************************************************
char * getStr()
{
	char * tmp = NULL;
 	tmp = "abcdefg";
	return tmp;
}

void  main()
{
	char *p = getStr();
	printf("p : %s \n", p);
	printf("p的地址 : %p \n", p);

	/* 注意：如果加入下边这条语句，编译后会出现宕机情况      */
  //  *(p+2)   = 'k'; //经常出现的错误保证指针所指向的内存空间 可以被修改
    /*  p指向了常量区，不能随便修改，这个区域被操作系统保护的，
	    如果通过指针建立赋值 修改内存空间  就会出错          */

	//*p = 5;
	//printf("*p =  %d \n", *p);
	system("pause");
	return;
}
//****************************************************************

char * getABC1(char *p);
char * getABC2(char **p);
char * getABC3(char *p);
char * getABC4(char (*p)[30]);
char * getABC5(char p5[10][30]);
//形参做函数参数，形参有多级指针的时候
//站在编译器的角度，只需要分配4个字节的内存（32bit平台）
//当我们使用内存的时候，我们才关心指针所指向的内存 是一维还是二维

void main83()
{
	system("pause");
	return;
}
//****************************************************************