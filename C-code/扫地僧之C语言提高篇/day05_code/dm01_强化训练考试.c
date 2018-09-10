#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/******************************************   经典案例  ********************************

		int sort(char *p[], int count, char **p, int *ncount);
		int sort(char *p[], int count, char (*p)[30], int *ncount);
		int sort(char (*p)[30], int ncount,  char **p, int *ncount);

		//把第一种内存模型第二种内存模型结果copy到第三种内存模型中，并排序，打印
		char ** sort(char **p1, int num1, char (*p)[30], int num2, int *num3 );

******************************************   经典案例  ********************************/

int sort(char **myp1/*in*/, int num1, char(*myp2)[30], int num2, char ***myp3, int *num3)
{
	int i = 0, j = 0, k = 0;
	int ret = 0;
	int tmplen = 0;
	char **p3 = NULL;
	char *tmp = NULL;
	p3 = (char **)malloc((num1 + num2) * sizeof(char *));  //里边装的是指针
	if (p3 == NULL)
	{
		return -1;
	}

	//根据
	for (i=0; i<num1; i++)
	{
		tmplen = strlen(myp1[i]) + 1;
		p3[i] = (char *)malloc(tmplen * sizeof(char));
		if (p3[i] == NULL)
		{
			return -2;
		}
		strcpy(p3[i],myp1[i]); 
	}

	for (j=0; j<num2; j++, i++)
	{
		tmplen = strlen(myp2[j]) + 1;
		p3[i] = (char *)malloc(tmplen * sizeof(char ));
		if (p3[i] == NULL)
		{
			return -3;
		}
		strcpy(p3[i],myp2[j]);
	}

	tmplen = num1 + num2; 
	//排序
	for (i=0; i<tmplen; i++)
	{
		for (j = i+1; j<tmplen; j++)
		{
			if (strcmp(p3[i], p3[j])>0)//if (p3[i] > p3[j])这样的话没有交换  因为比较的是地址 地址是从小到大,,但是交换值是可以的
			{
				tmp = p3[j];
				p3[j] = p3[i];
				p3[i] = tmp;
			}
		}
	}

	//间接赋值
	*num3 = tmplen;
	*myp3 = p3;

	return 0;
}


void sortFree01(char **p, int len)
{
	int i = 0;
	if (p == NULL)
	{
		return;
	}

	for (i=0; i<len; i++)
	{
		free(p[i]);

	}
	free(p);
}

//把二级指针指向二维内存释放掉 , 同时间接修改了实参的值
void sortFree02(char ***myp, int len)  
{
	int i = 0;
	char **p = NULL;
	if (myp == NULL)
	{
		return;
	}

	p = *myp; //还原成二级指针
	for (i=0; i<len; i++)
	{
		free(p[i]);
	}

	free(p);
	//myp是实参的值
	*myp = NULL;  //间接赋值是指针存在的最大意义
}

int main()
{
	int ret = 0;
	char *p1[]= {"aaa", "cccccc", "bbbbbb"};
	char buf2[10][30] = {"111111", "333333", "222222"};
	char **p3 = NULL;
	int len1, len2, len3, i = 0;

	len1 = sizeof(p1)/sizeof(*p1);
	len2 = 3;

	/**********  项目开发中,函数返回值异常重要  ********/
	ret = sort(p1, len1, buf2, len2, &p3, &len3);
	if (ret != 0)
	{
		printf("func sort() err : %d \n", ret);
		return ret;
	}
	for (i=0; i<len3; i++)
	{
		printf("%s \n", p3[i]);
	}
	sortFree02(&p3,len3);
	printf("%d \n", p3);

	printf("hello... \n");
	system("pause");
	return;
}