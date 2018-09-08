#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*
	注意结合：二级指针的三种内存模型图片
*/
void main()
{
	int i = 0;
	//指针数组
	char *p1[] = {"123", "456", "789"};

	//二维数组
	char p2[3][4] = {"123", "456", "789"};

	//手工二维数组
	char **p3 = (char **)malloc(3 * sizeof(char *));

	for(i=0; i<3; i++)
	{
		p3[i] = (char *)malloc(sizeof(char) * 3);
		sprintf(p3[i], "%d%d%d", i+1, i+1, i+1); //变参函数
	}

	printf("hello...\n");
	system("pause");

	return ;
}