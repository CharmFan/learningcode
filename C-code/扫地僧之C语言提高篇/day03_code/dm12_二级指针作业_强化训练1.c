#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*
	有一个字符串符合以下特征（"abcdef,acccd,eeee,aaaa,e3eeee,ssss,"）要求写一个函数（接口），输出以下结果
	1、以逗号分隔字符串，形成二维数组，并把结果传出
	2、把二维数组行数运算结果也传出

	*************************  主调函数 分配内存 *******************
	int spitString(const char *buf1, char c, char **myp, int *count)	
*/
//分清楚赋值指针变量 和 操作逻辑之间的关系

/* 
  *************************  两个辅助指针变量 挖 字符串 **************************
  *****************************   二级指针    ************************************
   *********************    在主调函数分配内存   *******************************  
*/

int spitString(const char *buf1, char c, char **myp/*in*/, int *count)
{
	char *p = NULL, *pTmp = NULL;
	int tmpcount = 0;

	if(buf1 == NULL ||myp ==NULL || count == NULL)
	{
		return -1;
	}
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
				strncpy(myp[tmpcount], pTmp, p-pTmp);
				myp[tmpcount][p-pTmp] = '\0';
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

	char **p = NULL;  //相对于char buf[10][30]  /*** 有多余的内存 ***/

	p = (char **)malloc(10 * sizeof(char *)); // char * array[10]
	if(p == NULL)
	{
		return ;
	}

	for(i=0; i<10; i++)
	{
		p[i] = (char *)malloc(30 * sizeof(char));
		if(p[i]  == NULL)
		{
			return ;
		}
	}
	ret = spitString(p1, cTem, p, &nCount);
	if(ret != 0)
	{
		printf("func spitString() err : %d \n", ret);
	}

	for(i=0; i<nCount; i++)
	{
		printf("%s\n", p[i]);
	}

	//释放内存
	for(i=0; i<10; i++)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;

	printf("hello...\n");
	system("pause");

	return ;
}