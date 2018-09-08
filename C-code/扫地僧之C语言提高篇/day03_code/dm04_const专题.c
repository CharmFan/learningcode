#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void main01()
{
	
	const int a = 0;  
	int const b = 0;

	const char *c;    //指向的内存空间不能被修改
	char * const d;   //指针变量不能被修改
	const char * const e;

	/*
		第一个与第二个意思一样，代表一个常整形数，不能被修改
		第三个 c 是一个指向常整形数的指针（所指向的内存数据不能被修改，但是本身可以修改）
		第四个 d 常指针（指针变量不能被修改，但是它指向的内存空间可以被修改）
		第五个 e 一个指向常整形的常指针（指针和它所指向的内存空间，均不能被修改）
	   
	   *******************  结论  **********************
	   指针变量与它所指向的内存空间变量，是两个不同的概念
	   主要看const修饰哪一个：是指针变量 还是指针指向的内存空间变量
	*/
	system("pause");

	return ;
}

//************************ const 修饰函数的参数  *********************

//第一、所指向的内存数据不能被修改，但是本身可以修改
void getMem01(const char *p) //
{
	p = 1 ;
	p = 3;

	//p[1] = 'a';
	return;
}

//第二、指针变量不能被修改，但是它指向的内存空间可以被修改
void getMem02(char *const p)
{
	//p =1 ;
	//p = 3;

	*p = 'a';
	return;
}

//第三、指针和它所指向的内存空间，均不能被修改
void getMem03(const char *const p)  // 只读
{
	//p =1 ;
	//p = 3;

	//p[1] = 'a';
	printf("%c",p[1]);
	return;
}
void main02()
{
	char *p1 = NULL;
	const char *p2 = NULL;
	p2 = 1;	
	printf("p1:%s \n",p1);

	system("pause");
	return;
}
//********************    结论 const 伪命题 ***************************
void main()
{
	const int a = 10; //c语言中的const 修饰的变量，是假的通过指针能修改变量的值
    //a = 100;  //此时编译报错
	{
		int *p = &a;
		*p = 100;
		printf("a:%d \n", a );
	}
	system("pause");
	return;
}
//********************    结论 const 伪命题 ***************************