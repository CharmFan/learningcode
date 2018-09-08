#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//char *p = "abcd21342abcd3254abcd45abcd"
//求字符串p中，"abcd" 出现的次数

/*
  strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串。
  如果是，则该函数返回str2在str1中首次出现的地址；否则，返回NULL。
 */
void main11()
{
	int ncount = 0;
	char *p = "abcd21342abcd3254abcd45abcd";

	do
	{
		p = strstr(p, "abcd");
		if(p != NULL)
		{
			ncount++;
			p = p + strlen("abcd");
		}
	}while (*p != '\0');

	printf("ncount : %d\n",ncount);

	printf("hello...\n");
	system("pause");

	return ;
}

//**************************************************
void main22()
{
	//strstr
	int ncount = 0;
	char *p = "abcd21342abcd3254abcd45abcd";

	while (p = strstr(p, "abcd"))
	{
		ncount++;
		p = p + strlen("abcd"); //让指针达到查找条件
		if(*p == '\0')
		{
			break;
		}
	
	}

	printf("ncount : %d\n",ncount);

	printf("hello...\n");
	system("pause");

	return ;
}

//**************************************************
//1、请自定义函数接口，完成上述要求
//2、自定义的业务函数 和 main（） 函数必须分开

int getCount(char *mystr/*in*/, char *sub/*in*/, int *ncount)
{
	int ret = 0;
	char *p = mystr; //不轻易改变指针的指向
	int tmpCount = 0;

	if(mystr==NULL || sub==NULL || ncount==NULL)
	{
		ret = -1;
		printf("func getCount() err :%d (mystr==NULL || sub==NULL || ncount==NULL) \n", ret);
		return ret;
	}

	while (p = strstr(p, sub))
	{
		tmpCount++;
		p = p + strlen(sub); //让指针达到查找条件
		if(*p == '\0')
		{
			break;
		}
	}

	*ncount = tmpCount;
	return ret;
}

//******************************** 一个常犯错误的地方  **************************************
int getCount(char *mystr/*in*/, char *sub/*in*/, int *ncount)
{
	int ret = 0;
	char *p = mystr; //不轻易改变指针的指向
	int tmpCount = 0;

	if(mystr==NULL || sub==NULL || ncount==NULL)
	{
		ret = -1;
		printf("func getCount() err :%d (mystr==NULL || sub==NULL || ncount==NULL) \n", ret);
		return ret;
	}

	while (p = strstr(p, sub))
	{
		
		//**********************  犯错之地   ******************
		//tmpCount++;
		//********修改为如下代码 错误示范 ****
		//++后缀操作符优先级高，所以先执行*p操作，然后地址++
		// *ncount++; //此时后已经改变 ncount的地址指向
		//正确示范 (*ncount)++；
		//**********************  犯错之地   ******************

	  p = p + strlen(sub); //让指针达到查找条件
		if(*p == '\0')
		{
			break;
		}
	}

	*ncount = tmpCount;
	return ret;
}
//******************************************************

int main()
{
	int ret = 0;
	int count = 0;
	char *p = "abcd21342abcd3254abcd45abcd";
	char sub[] = "abcd";

	ret = getCount(p, NULL, &count);
	if(ret != 0)
	{
		printf("func getCount() err : %d \n", ret);
		return ret;
	}

	printf("count : %d\n",count);
	printf("hello...\n");
	system("pause");

	return ;
}
