#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
/*
	有一个字符串符合以下特征（"abcdef, acccd, eeee, aaaa, e3eeee,ssss,"）要求写一个函数（接口），输出以下结果
	1、以逗号分隔字符串，形成二维数组，并把结果传出
	2、把二维数组行数运算结果也传出

	在被调函数中分配内存

	第一种：返回二级指针：
		char ** spitString(const char *buf1, char c, int *count)
	第二种：三级指针做函数参数替代上第一种：
		int spitString(const char *buf1, char c,char ***myp3, int *count)

*/
//分清楚赋值指针变量 和 操作逻辑之间的关系
/* 
  *************************  两个辅助指针变量 挖 字符串 **************************
  *************************      二级指针   三级指针  ***************************
   *************************   在 被调函数  分配内存  ****************************  
*/
//*******************************    返回二级指针   ***************************
/*
   在被调函数中分配内存  第一种：返回二级指针：
*/
char ** spitString1(const char *buf1, char c, int *count)
{
	char *p = NULL, *pTmp = NULL;
	int tmpcount = 0;
    char **myp = NULL;

	if(buf1 == NULL || count == NULL)
	{
		return NULL;
	}
	
    //第一遍 求出count
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

	//根据多少行 精确分配内存
	myp = (char **)malloc(sizeof(char *) * tmpcount);
	if(myp == NULL)
	{
		return NULL;
	}

	//1、 p 和 pTmp 初始化
	p = buf1;
	pTmp = buf1;
	tmpcount = 0;
	do
	{
		//2、 检索符合条件的位置 p后移 形成差值 挖字符串
		p = strchr(p, c);
		if(p != NULL)
		{
			if(p-pTmp > 0)
			{
				int len = p -pTmp +1 ;  // +1 为'\0' 分配内存  符合c语言
				myp[tmpcount] = (char *)malloc(sizeof(char) * len);
				if(myp[tmpcount] == NULL)
				{
					return NULL;
				}
				strncpy(myp[tmpcount], pTmp, p-pTmp);
				myp[tmpcount][p-pTmp] = '\0';  //把第一行数据变成 C语言风格字符串
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

	return myp;
}

void main11()
{	
	char *p1 = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	int i = 0;
	char cTem = ',';
	int nCount = 0;

	char **p = NULL;  //相对于char buf[10][30]  /*** 有多余的内存 ***/

	p = spitString1(p1, cTem, &nCount);
	if(p == NULL)
	{
		printf("func spitString() err  \n");
	}

	for(i=0; i<nCount; i++)
	{
		printf("%s\n", p[i]);
	}

	//释放内存
	for(i=0; i<nCount; i++)
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
//************************************    返回二级指针   ********************************




//*********************************    三级指针 做 函数参数   ***************************

//*********************** 一个入口，多个出口 变同一出口 goto + memset(置零)第一次申请的内存全置0  ****
//******* 第二次申请中某一次申请内存失败，判断第二申请的地址知否为空，就能知道有多少第二次申请成功 ***
/*
   在被调函数 中 分配内存  第二种：三级指针做函数参数替代第一种方式
*/

void FreeMem2(char **myp, int count)
{
	int i =0;
	if(myp == NULL)   //判断二级指针
	{
		return ;
	}
	for(i=0; i<count; i++)
	{	
		if(myp[i] != NULL)
		{
			free(myp[i]);
		}	
	}
	if(myp != NULL)
	{
		free(myp);
	}
}

void FreeMem3(char ***p, int count)
{
	int i =0;
	char **myp = NULL;
	if(p == NULL)  //判断三级指针
	{
		return ;
	}

	myp = *p;
	if (myp == NULL)  //判断二级指针等于FreeMem2(char **myp, int count) 中判断二级指针
	{
		return ;
	}

	for(i=0; i<count; i++)
	{	
		if(myp[i] != NULL)
		{
			free(myp[i]);
		}	
	}

	if(myp != NULL)
	{
		free(myp);
	}
	*p = NULL; //把实参二级指针修改为 NULL
}


/**************************************    注意   **********************************
     函数如果一个入口，多个出口  变成 同一出口；在同一出口将出错的内存释放

**************************************    注意   **********************************
*/
int spitString(const char *buf1, char c,char ***myp3, int *count)
{
	char *p = NULL, *pTmp = NULL;
	int tmpcount = 0;
	char **myp = NULL;
	int ret = 0;

	if(buf1 == NULL || count == NULL || myp3 == NULL)
	{
		return -1;
	}

	//第一遍 求出count
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

	//根据多少行 精确分配内存
	myp = (char **)malloc(sizeof(char *) * tmpcount);
	if(myp == NULL)
	{
		ret = -2;
		printf("func spitString() err err:%d  tmpcount* sizeof(char *) ", ret);
		goto END;
		//return -2;
	}
	memset(myp, 0, tmpcount* sizeof(char *)); //做一个负责的人，下面的有 return -3 内存怎么释放
	                                          //方便后面释放

	//1、 p 和 pTmp 初始化
	p = buf1;
	pTmp = buf1;
	tmpcount = 0;
	do
	{
		//2、 检索符合条件的位置 p后移 形成差值 挖字符串
		p = strchr(p, c);
		if(p != NULL)
		{
			if(p-pTmp > 0)
			{
				int len = p -pTmp +1 ;  // +1 为'\0' 分配内存  符合c语言
				myp[tmpcount] = (char *)malloc(sizeof(char) * len);
				if(myp[tmpcount] == NULL)
				{
					ret = -3;
				    printf("func spitString() err err:%d  sizeof(char) * len ", ret);
				    goto END;
				}
				strncpy(myp[tmpcount], pTmp, p-pTmp);
				myp[tmpcount][p-pTmp] = '\0';  //把第一行数据变成 C语言风格字符串
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

END:
	if(ret !=0)  //失败
	{  
		/*第一种方式：
			FreeMem2(myp, *count);
			myp = NULL;
		*/
		/* 第二方式 */
		FreeMem3(&myp, *count);
	}
	else        //成功
	{
		*myp3 = myp; 
	}
	
	return ret;
}

void main()
{	
	char *p1 = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	int i = 0;
	int ret = 0;
	char cTem = ',';
	int nCount = 0;

	char **p = NULL;  //相对于char buf[10][30]  /*** 有多余的内存 ***/

	ret = spitString(p1, cTem, &p, &nCount);
	if(ret != 0)
	{
		printf("func spitString() err  \n");
	}

	for(i=0; i<nCount; i++)
	{
		printf("%s\n", p[i]);
	}

	//释放内存
	for(i=0; i<nCount; i++)
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
//***************************    三级指针 做 函数参数   **************************