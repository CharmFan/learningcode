#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*
	指针的输入与输出模型
		指针做输入：主调函数分配内存
		指针做输出：被调函数分配内存
*/

//求文件的中两段话的长度
int getMem(char **myp1, int *mylen1, char **myp2, int *mylen2)
{
	char *tmp1 = NULL;
	char *tmp2 = NULL;

	tmp1 = (char *)malloc(100);
	if(tmp1==NULL)
	{
		return -1;
	}
	strcpy(tmp1,"abcdefg");

	*mylen1 = strlen(tmp1);
	*myp1 = tmp1;//间接修改实参p1的值

	tmp2 = (char *)malloc(100);
	if(tmp2 == NULL)
	{
		return -2;
	}
	strcpy(tmp2,"11223333");

	*mylen2 = strlen(tmp2);
	*myp2 = tmp2;//间接修改实参p2的值

	return 0;
}
int getMen_Free0(char **myp1)
{
	char *tmp = NULL;
	if(myp1 == NULL)
	{
		return -1;
	}
	tmp = *myp1;

	free(tmp);  //释放完指针变量所指向的内存空间
	tmp = NULL; //把实参修改为NULL

	return 0;
}

void main0()
{
	char *p1 = NULL;
	int len1 = 0;

	char *p2 = NULL;
	int len2 = 0;
	int ret = 0;

	ret = getMem(&p1, &len1, &p2, &len2); 

	printf("p1:%s \n",p1);
	printf("p2:%s \n",p2);

	getMen_Free0(&p1);
	getMen_Free0(&p2);

	system("pause");
	return ;
}

//*********************************  存在野指针  ***********************************************
int getMen_Free1(char *myp1)
{
	char *tmp = NULL;
	if(myp1 == NULL)
	{
		return -1;
	}
	tmp = myp1;

	free(tmp);  //释放完指针变量所指向的内存空间
	tmp = NULL; /**  这里实参与形参没有半毛钱关系 ====》不能把实参修改为NULL */


	return 0 ;
}

void main()
{
	char *p1 = NULL;
	int len1 = 0;

	char *p2 = NULL;
	int len2 = 0;
	int ret = 0;

	ret = getMem(&p1, &len1, &p2, &len2); 

	printf("p1:%s \n",p1);
	printf("p2:%s \n",p2);

	getMen_Free1(p1);  //在被调函数中，把p1所指向的内存空间给释放掉，但是，实参p1不能被修改成NULL；有野指针现象
	getMen_Free1(p2);

	system("pause");
	return ;
}
//******************************************************************************