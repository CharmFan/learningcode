#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void main11()
{
	//求非空格的字符长度
	char *p = "     abcdefg    ";
	int i, j = 0;
	int ncount = 0;
	i = 0;
	j = strlen(p)-1;

	while(isspace(p[i]) && p[i]!='\0' )
	{
		i++;
	}

	while(isspace(p[j]) && p[j]!='\0' )
	{
		j--;
	}
	
	ncount = j - i + 1;

	printf("ncount : %d \n",ncount);

	printf("hello...\n");
	system("pause");

	return 0;
}

//**********************************************************************************
int getCount(char *str, int *pCount)
{
	char *p = str;
	int ncount = 0;
	int ret = 0;

	int i, j = 0;
	i = 0;
	j = strlen(p)-1;

	if(str == NULL || pCount == NULL)
	{
		ret = -1 ;
		printf("func trimSpcae err\n");
		return ret;
	}

	while(isspace(p[i]) && p[i]!='\0' )
	{
		i++;
	}

	while(isspace(p[j]) && p[j]!='\0' )
	{
		j--;
	}

	ncount = j - i + 1;
	*pCount = ncount;

	return ret;
}

//去除字符串前后空格
//考试作业1
int trimSpcae02(char *str, char *newstr)
{
	int ret = 0;
	char *p = str;
	int i, j ;
	int ncount = 0;

	i = 0;
	j = strlen(p)-1;

	if(p == NULL || newstr == NULL)
	{
		ret = -1 ;
		printf("func err\n");
		return ret;
	}

	while(isspace(p[i]) && p[i]!='\0' )
	{
		i++;
	}

	while(isspace(p[j]) && p[j]!='\0' )
	{
		j--;
	}

	ncount = j - i + 1;
	strncpy(newstr, str+i, ncount);
	newstr[ncount] = '\0';

	return ret;
}
void main02()
{
	char *p = "  abcdefg   ";
	int num = 0;
	int ret = 0;
	char buf[100] = {0};

	ret = getCount(p, &num);
	if(ret != 0)
	{
		printf("func1 err \n");
		return ;
	}
	printf("num : %d \n", num);


	ret = trimSpcae02(p, buf);
	if(ret != 0)
	{
		printf("func2 err \n");
		return ;
	}
	printf("buf : %s \n", buf);


	printf("hello...\n");
	system("pause");
	return ;
}
//*************************************************************************

/*************   既做输入；也做输出的情况；请特别注意  ********************
	注意：str指向的内存空间，可以被修改，才行 ！！！！！	

如果要告诉别人，指针能不能被修改；*********  加一个const修饰   ********
int trimSpcae(const char *str)   
**/
int trimSpcae(char *str)
{
	int ret = 0;
	char *p = str;
	int i, j ;
	int ncount = 0;

	i = 0;
	j = strlen(p)-1;

	if(p == NULL)
	{
		ret = -1 ;
		printf("func err\n");
		return ret;
	}

	while(isspace(p[i]) && p[i]!='\0' )
	{
		i++;
	}

	while(isspace(p[j]) && p[j]!='\0' )
	{
		j--;
	}

	ncount = j - i + 1;
	strncpy(str, str+i, ncount);
	str[ncount] = '\0';

	return ret;
}

void main()
{
	//***************************  存在宕机风险  ********************************

	//char *p = "  abcdefg   ";  程序直接死掉;此时变量定义在 : 常量区（不能被修改）

	/*换中方式定义*/
	char p[] = "   abcdefg   ";  //此时变量定义在 ：临时区（能被修改）
	
	//***************************  存在宕机风险  ********************************

	int ret = 0;
	char buf[100] = {0};

	ret = trimSpcae(p);
	if(ret != 0)
	{
		printf("func1 err \n");
		return ;
	}
	
	printf("buf : %s \n", p);

	system("pause");
	return ;
}