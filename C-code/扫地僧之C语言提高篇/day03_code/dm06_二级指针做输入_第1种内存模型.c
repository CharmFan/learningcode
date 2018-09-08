#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//*****************************    二级指针做输入  第1种内存模型    ********************
//****************************************    指针数组    ******************************

//数组做函数参数，退化为指针，加长度
void printfArray(char **myArray,int num)
{
	int i =0;

	for(i=0; i<num; i++)
	{
		//printf("%s \n",MYaRRAY[i]);
		printf("%s \n",*(myArray+i));
	}
}

void sortArray(char **myArray, int num)
{
	int i = 0, j = 0;
	char *tmp =NULL;

	for(i=0; i<num; i++)
	{
		for(j=i+1; j<num; j++) 
		{
			if(strcmp(myArray[i],myArray[j])>0)
			{
				tmp = myArray[i];      //交换的是数组元素，交换的是指针的值
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

void main()
{
	int i= 0;
	int j= 0;
	int num = 0;
	char *tmp = NULL;
	//数组中的每个元素是指针   指针数组
	char *myArray[] = {"AAAAAA","CCCC","BBBBBB","222222"};

	//打印   
	//*********************  这种方法注意总结  *******************
	num = sizeof(myArray)/sizeof(myArray[0]);

	printf("排序前 \n");
	printfArray(myArray,num);

	//排序
	sortArray(myArray,num);


	printf("排序后 \n");
	printfArray(myArray,num);

	system("pause");
	return ;
}
