#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

char g_buf[100] = {0};
/*
	int inverse(char *str, char *str2)
*/
//方式一、指针
void main11()
{
	char buf[] = "abcdefg";
	int length  =strlen(buf);

	char *p1 = buf;
	char *p2 = buf + length -1;

	while(p1 < p2)
	{
		char c = *p1;
		*p1 = *p2;
		*p2 = c;
		++p1;
		--p2;
	}
	printf("buf : %s \n",buf);

	printf("hello...\n");
	system("pause");

	return ;
}

//*********************************************************************************************

int inverse(char *str)
{

	return 1;
}
void main22()
{

}
//********************************************************************************************

/* 理解递归两个点：
		1、参数的入栈模型
		2、函数嵌套调用返回流程
 采用递归方式,逆向打印
     第一种情况 : 递归和全局变量（把逆序的结果存入全局变量）
     第二种情况 ：递归和非全局变量（递归指针做函数参数）
 */
//方式二、递归
void inverse02(char *p)
{
	if(p == NULL)   //递归结果的异常条件
	{
		return ;
	}
	if(*p == '\0')  //递归的结束条件
	{
		return ;
	}
	inverse02(p+1);  //注意，此时没有执行打印，而是执行了 调用函数
	                 //让字符串的每一个地址入栈
	printf("%c  ", *p);
} 

// 第一种情况 : 递归和全局变量（把逆序的结果存入全局变量）
//此时，如果是多线程，可能对全局变量多次赋值，可能会先乱码。
void inverse03(char *p)
{
	if(p == NULL)   //递归结果的异常条件
	{
		return ;
	}
	if(*p == '\0')  //递归的结束条件
	{
		return ;
	}
	inverse03(p+1);  //注意，此时没有执行打印，而是执行了 调用函数
	                  //让字符串的每一个地址入栈

	/**********  每一次拷贝一个字符  **********/

	//strncpy(g_buf,p, 1);     //=====拷贝 覆盖  第一次时候：g  第二次时候：f(覆盖前一个)
	  strncat(g_buf,p, 1);     //=====拷贝 连接  第一次时候：g  第二次时候：gf（连接前一个）

	/**********  每一次拷贝一个字符  **********/
}

//第二种情况 ： 递归和非全局变量（递归指针做函数参数）
void inverse04(char *p, char * bufresult)
{
	if(p == NULL  || bufresult == NULL)   //递归结果的异常条件
	{
		return ;
	}
	if(*p == '\0')  //递归的结束条件
	{
		return ;
	}
	inverse04(p+1, bufresult);   //通过是上面的逆序打印好好理解，bufresult其实也递归了

	strncat(bufresult, p, 1);     //拷贝连接
}

void main()
{
	int ret = 0;
	char buf[] = "dfeg";

	//inverse02(buf);

	//g_buf为全局变量，前面有定义
	//方式一：测试
	memset(g_buf, 0, sizeof(g_buf));
    inverse03(buf);
	printf("g_buf : %s \n", g_buf);

	{
		//方式二：递归测试
		char mybuf[1024] ={0};
		inverse04(buf, mybuf);
		printf("mybuf : %s \n", mybuf);		
	}

	system("pause");
	return ;
}