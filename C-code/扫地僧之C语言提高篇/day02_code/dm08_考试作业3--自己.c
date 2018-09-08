/*
	键值对（"key=valude"）字符串，在开发中经常使用
	要求1、自己定义一个接口，实现根据key获取valude
	要求2、编写测试用例
	要求3、键值对中间可能有n个空格，请取出空格；
	注意：键值对字符串格式可能如下：
		"key=valude1"
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

int getKeyByValude(char *keyvaluebuf, char *keybuf, char *valuebuf, int *valuebuflen)
{
	int ret = 0;
	int len = 0;
	char *mykeyvaluebuf = keyvaluebuf;
	char *mykeybuf = keybuf;
	char *myvaluebuf = valuebuf;
	int *myvaluebuflen = valuebuflen;

	if(mykeyvaluebuf ==NULL || mykeybuf==NULL || myvaluebuf==NULL || myvaluebuflen==NULL)
	{
		ret = -1;
		printf("func getKeyByValude err :%d (mykeyvaluebuf ==NULL || mykeybuf ==NULL || myvaluebuf ==NULL || myvaluebuflen) \n", ret);
		return ret;
	}
	
	while(*mykeyvaluebuf != '=')
	{
		if(*mykeyvaluebuf == ' ')
		{
			mykeyvaluebuf++;
		}
		else 
		{
			*mykeybuf = *mykeyvaluebuf;
			len++;
			mykeyvaluebuf++;
			mykeybuf++;
		}
	}
	*mykeybuf = '\0';
	mykeyvaluebuf++; //指向等于号 后面一位
	len++;

	while(*mykeyvaluebuf != '\0')
	{
		if(*mykeyvaluebuf == ' ')
		{
			mykeyvaluebuf++;
		}
		else
		{
			*myvaluebuf = *mykeyvaluebuf;
			len++;
			mykeyvaluebuf++;
			myvaluebuf++;
		}
	}
	*myvaluebuf = '\0';
	
	*myvaluebuflen = len;

	return ret;
}



void main()
{
	int ret = 0;
	char keybuf[58] = {0} ;
	char valuebuf[50] = {0};
	int valuebuflen = 0;
	char *keyvaluebuf1 = "key=valude1";
	char *keyvaluebuf2 = "key2=    valude2";
	char *keyvaluebuf3 = "key3 =valude3";
	char *keyvaluebuf4 = "key4    =valude4";
	char *keyvaluebuf5 = "key5  =  ";
	char *keyvaluebuf6 = "key6  =";
	char *keyvaluebuf7 = "key7  =  ";
	char keyvaluebuf[100] = {0} ;

	strcpy(keyvaluebuf,  keyvaluebuf7);

	ret = getKeyByValude(keyvaluebuf, keybuf, valuebuf,&valuebuflen);
	if(ret != 0)
	{
		printf("func getKeyByValude err\n");
		return ;
	}

	printf("keyvaluebuf : %s \n",keyvaluebuf);
	printf("keybuf : %s \n", keybuf);
	printf("valuebuf : %s \n", valuebuf);

	printf("valuebuflen : %d \n", valuebuflen);

	printf("hello...\n");
	system("pause");

	return ;
}