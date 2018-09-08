#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//*****************************    二级指针做输入  第3种内存模型    ********************
//************************************     手工二维内存    *****************************

void main11()
{
	int i = 0;
	int j = 0;
	char **p2 = NULL;
	int num = 5;
	char * tmp = NULL;
	char tmpbuf[100] = {0};

	p2 = (char **)malloc(sizeof(char *) * num);

	for(i=0; i<5; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * num);
		sprintf(p2[i], "%d%d%d", i+1, i+1, i+1); //变参函数
	}

	//排序之前
	printf("排序之前 \n");
	for(i=0; i<num; i++)
	{
		printf("%s \n", p2[i]);
	}

	//排序  /*  交换的指针  */
	for(i=0; i<num; i++)
	{
		for(j=i+1; j<num; j++)
		{
			if(strcmp(p2[i], p2[j]) < 0)
			{
				tmp	= p2[i];
				p2[i] = p2[j];
				p2[j] = tmp;
			}
		}
	}
	printf("排序之后 \n");
	for(i=0; i<num; i++)
	{
		printf("%s \n", p2[i]);
	}

	//排序  /*  交换的内存  */
	for(i=0; i<num; i++)
	{
		for(j=i+1; j<num; j++)
		{
			if(strcmp(p2[i], p2[j]) > 0)
			{
				strcpy(tmpbuf, p2[i]);
				strcpy(p2[i], p2[j]);
				strcpy(p2[j], tmpbuf);
			}
		}
	}

	printf("排序之后 \n");
	for(i=0; i<num; i++)
	{
		printf("%s \n", p2[i]);
	}

	//是否内存
	for(i=0; i<num; i++)
	{
		if(p2[i] != NULL)
		{
			free(p2[i]);
			p2[i] = NULL;
		}
	}
	
	printf("hello...\n");
	system("pause");
	return ;
}
//**********************************************************************************************
char ** getMem(int num)
{
	int i = 0;
	char **p2 = NULL;
	p2 = (char **)malloc(sizeof(char *) * num);
	if(p2 == NULL)
	{
		return NULL;
	}

	for(i=0; i<5; i++)
	{
		p2[i] = (char *)malloc(sizeof(char) * num);
		sprintf(p2[i], "%d%d%d", i+1, i+1, i+1); //变参函数
	}
	
	return p2;
}

//数组做函数参数，退化为指针，加长度
//第一种内存模型的 "打印" 函数
void printfArray(char **myArray,int num)
{
	int i =0;

	for(i=0; i<num; i++)
	{
		//printf("%s \n",MYaRRAY[i]);
		printf("%s \n",*(myArray+i));
	}
}
//第一种内存模型的 "排序" 函数
void sortArray(char **myArray, int num)
{
	int i = 0, j = 0;
	char *tmp =NULL;

	for(i=0; i<num; i++)
	{
		for(j=i+1; j<num; j++) 
		{
			if(strcmp(myArray[i],myArray[j]) < 0)
			{
				tmp = myArray[i];      //交换的是数组元素，交换的是指针的值
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

void getFree(char **p2, int num)
{
	int i = 0;
	for(i=0; i<num; i++)
	{
		if(p2[i] != NULL)
		{
			free(p2[i]);
			p2[i] = NULL;
		}
	}

	if(p2 != NULL)
	{
		free(p2);
		//p2 = NULL;
	}
}
void main()
{
	int j = 0;
	int num = 5;
	char * tmp = NULL;
	char tmpbuf[100] = {0};
	char **p2 = NULL;

	p2 = getMem(num);

	//排序之前
	printf("排序之前 \n");
    printfArray(p2, num);

	//排序
	sortArray(p2, num);

	//排序之后
	printf("排序之后 \n");
	printfArray(p2, num);

	getFree(p2, num);   /* 调用函数后 =====>p2是一个野指针 */

	printf("hello...\n");
	system("pause");
	return ;
}