#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
/*
	有一个字符串符合以下特征（"abcdef, acccd, eeee, aaaa, e3eeee,ssss,"）要求写一个函数（接口），输出以下结果
	1、以逗号分隔字符串，形成二维数组，并把结果传出
	2、把二维数组行数运算结果也传出
*/


/*************************  两个辅助指针变量 挖 字符串 ****************************/

//分清楚赋值指针变量 和 操作逻辑之间的关系
int spitString(const char *buf1, char c, char buf2[10][30], int *count)
{
	char *p =NULL, *pTmp = NULL;
	int tmpcount = 0;

	//1、 p 和 pTmp 初始化
	p = buf1;
	pTmp = buf1; 

	do
	{
		//2、 检索符合条件的位置 p后移 形成差值 挖字符串
		p = strchr(p, c);
		if(p != NULL)
		{
			if(p-pTmp > 0)
			{
				strncpy(buf2[tmpcount], pTmp, p-pTmp);
				buf2[tmpcount][p-pTmp] = '\0';	
				tmpcount++;
				//3、重新 让p和ptmp 达到下一次检索的条件
				pTmp = p = p +1;
			}
			else
			{
				break;
			}
		}
	}while(*p != '\0');

	*count = tmpcount;

	return 0;
}

void main()
{	
	char *p1 = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	char ret = 0;
	int i = 0;
	char cTem = ',';
	int nCount = 0;
	char myArray[10][30];

	ret = spitString(p1, cTem, myArray, &nCount);
	if(ret != 0)
	{
		printf("func spitString() err : %d \n", ret);
	}

	for(i=0; i<nCount; i++)
	{
		printf("%s \n", myArray[i]);
	}
	printf("hello...\n");
	system("pause");

	return ;
}

/*
作业一、三种内存模型求解   另外的两种形式
	char **spitString(const char *buf1, char c,  int *count)
	int spitString2(const char *buf1, char c, char ***p, int *count)


作业二、有一个字符串符合以下特征("abcd11111abcd2222abcdqqqqq"),要求写一个函数（接口）
输出以下结果
	1、把字符串自串（"abcd"）出现的次数，并把结果传出。
	2、把字符串替换成（dcba11111dcba2222dcbaqqqqq）,并把结果传出。
	int getRsetbuf(const chaar *buf1, int buflen, int *count, char * buf2)
*/