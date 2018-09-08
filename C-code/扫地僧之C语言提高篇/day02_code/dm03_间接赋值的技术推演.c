#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*  *p间接赋值成立的条件：
		条件1 ：定义了两个变量（一个形参，一个是实参）
		条件2 ：建立关系
		条件3 ：形参去间接的修改实参的值

	应用场景：
		场景一	：1、2、3		写在一个函数                          *** 4 ***
		场景二	：1、2 写在一块	3单独写在另一个函数  ====> 函数调用   *** 3 ***
		场景三	：1单独写   2、3写一块	==>抛砖 ===>c++ 会有
*/


//*****************************************************************    1   ***
//形参的属性
//函数名（）{};
//int a 定义在小括号里  和大括号  基本无差别，只是小括号的形参具有对外的属性
int getMen1(int a)
{
	//int a;
}

int getFileLen(int *p)
{
	*p = 41;  //p的值是a的地址，*p 间接修改a的值
			//条件3 ：形参去间接的修改实参的值
}

int getFileLen2(int b)
{
	b = 100;
}

//一级指针 间接修改变量的值
void main32()
{
	int a = 10;   //条件1：定义了两个变量（一个形参，一个是实参）
	int *p = NULL;
	
	//直接赋值
	a = 10;

	p = &a;  //条件2 ：建立关系
	{
		*p = 23;
		printf("*p = %d\n",*p);
	}

	getFileLen(&a);
	printf("*p = %d\n",*p);

	getFileLen2(a);
	printf("*p = %d\n",*p);

	printf("hello...\n");
	system("pause");

	return ;
}

//*******************************************************  2  ******
void getMen(char **p2)
{
	*p2 = 666;
}
//二级指针技术推演
void main33()
{
	char *p1 = NULL;
	char **p2 = NULL;

	p1 = 11;
	p2 = 22;

	//直接修改
	p1 = 111;

	//间接修p1, p2是p1的地址
	p2 = &p1;
	*p2 = 222;
	printf("p1 :%d \n", p1);

	{
		*p2 = 2222;
		printf("p1 :%d \n", p1);
	}

	getMen(&p1);
	printf("p1 :%d \n", p1);

	system("pause");
	return ;
}

//**********************************************************  3  ***

int getMem3(char **myp1, int *mylen1, char **myp2, int *mylen2)
{
	int	ret = 0;
	char	*tmp1, *tmp2;

	tmp1 = (char *)malloc(100);
	strcpy(tmp1, "1234567890");

	//间接赋值
	*mylen1 = strlen(tmp1);  //一级指针
	*myp1 = tmp1;          //二级指针

	tmp2 = (char *)malloc(100);
	strcpy(tmp2, "qwertyuiop");

	*mylen2 = strlen(tmp2);  //一级指针
	*myp2 = tmp2;          //二级指针

	return ret;
}
/* 
	该案例是指针做函数参数，实现了一个功能，我们可以通过这样的方式设计多个功能函数，初步有了分层的。

	***********指针做函数参数，异常重要**************

	如果没有指针做函数参数，就没有简单的分层，
	没有分层，就不可能有接口的封装和设计，
	没有接口的封装和设计就不可能有软件的功能和功能之间的划分，
	没有有软件的功能和功能之间的划分，就没有软件信息系统，
	没有软件信息系统，做It就没得玩了啊。！！！！！！！！！！！
*/
int main34()
{
	int		ret = 0;
	char	*p1 = NULL;
	int		len1 = 0;
	char	*p2 = NULL;
	int		len2 = 0;

	ret  = getMem3(&p1, &len1, &p2, &len2);
	if(ret != 0)
	{
		printf("func getMem2() err \n");
		return ret;
	}

	printf("p1 : %s \n",p1);
	printf("p2 : %s \n",p2);

	if(p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}

	if(p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}

	system("pause");
	return ;
}

//*******************************************  4 ****
//间接赋值的应用场景一
void main()
{
	char from[128];
	char to[128] = {0};
	char *p1 = from;
	char *p2 = to;

	strcpy(from, "afoihafuiohdsuafohduaofhu");

	while(*p1 != '\0')
	{
		*p2 = *p1;
		p2++;
		p1++;
	}

	printf("to:%s \n",to );

	system("pause");
	return ;
}