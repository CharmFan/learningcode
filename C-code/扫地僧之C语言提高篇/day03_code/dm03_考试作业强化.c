/*
	键值对（"key=valude"）字符串，在开发中经常使用
	要求1、自己定义一个接口，实现根据key获取valude
	要求2、编写测试用例
	要求3、键值对中间可能有n个空格，请取出空格；
	注意：键值对字符串格式可能如下：
		"key1=valude1"
		  "key2=    valude2"
			"key3 =valude3"
		       "key4    =valude4"
		         "key5  =  "
		           "key6  ="
		             "key7  =  "

		int getKeyByValude(char *keyvaluebuf, char *keybuf, char *valubuf, int *valuebuflen);
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//去除字符串前后空格  "两头堵模型"
int trimSpcae(char *str, char *newstr)
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

//总体思路 : 
// 1、查找key是不是在母串中
// 2、看有没有 "="
// 3、在等号后面  去除空格
int getKeyByValude(char *keyvaluebuf, char *keybuf, char *valuebuf)
{
	
	int ret = 0;
	int len = 0;
	char *p = keyvaluebuf;  //初始化辅助指针变量

	if(keyvaluebuf==NULL || keybuf==NULL || valuebuf==NULL)
	{
		ret = -1;
		printf("func getKeyByValude err :%d (mykeyvaluebuf ==NULL || mykeybuf ==NULL || myvaluebuf ==NULL) \n", ret);
		return ret;
	}

	// 1、查找key是不是在母串中
	p = strstr(p, keybuf);
	if(p == NULL)
	{
		return -1;
	}
	//让辅助指针变量 重新达到下一次检索的条件
	p = p + strlen(keybuf);


	// 2、看有没有 "="
	p = strstr(p, "=");
	if(p == NULL)
	{
		return -1;
	}
	//让辅助指针变量 重新达到下一次检索的条件
	p = p + strlen("=");


	// 3、在等号后面  去除空格
	ret = trimSpcae(p, valuebuf);
	if(ret != 0)
	{
		printf("func getKeyByValude err \n ");
		return -1;
	}

	return ret;
}

void main()
{
	int ret = 0;
	
	char value[50] = {0};
	int valuebuflen = 0;
	char *keyvaluebuf1 = "key1=valude1";
	char *keyvaluebuf2 = "key2=    valude2";
	char *keyvaluebuf3 = "key3 =valude3";
	char *keyvaluebuf4 = "key4    =valude4";
	char *keyvaluebuf5 = "key5  =  ";
	char *keyvaluebuf6 = "key6  =";
	char *keyvaluebuf7 = "key7  =  ";
	char key[] = "key1";

	ret = getKeyByValude(keyvaluebuf1, key, value);
	if(ret != 0)
	{
		printf("func getKeyByValude err\n");
		return ;
	}

	printf("keyvaluebuf : %s \n",keyvaluebuf1);
	printf("key : %s \n", key);
	printf("value : %s \n", value);

	system("pause");

	return ;
}