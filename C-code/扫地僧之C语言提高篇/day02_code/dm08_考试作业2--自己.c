/*
	有个字符串“1a2b3d4z”
	功能1、把偶数位字符挑选出来，组成一个字符串1.
	功能2、把奇数位字符挑选出来，做成一个字符串2.
	功能3、把字符串1和字符串2，通过函数参数，传递给main,并打印。
	功能4、主函数能测试通过
	int getStr1Str2(char *source, char *buf1, char *buf2)
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int getStr1Str2(char *source, char *buf1, char *buf2)
{
	int ret = 0;
	int flag = 0;
	char *mysource = source;
	char *mybuf1 = buf1;
	char *mybuf2 = buf2;

	if(mysource ==NULL || buf1 ==NULL || buf2 ==NULL)
	{
		ret = -1;
		printf("func getStr1Str2 err :%d (mysource ==NULL || buf1 ==NULL || buf2 ==NULL) \n", ret);
		return ret;
	}
	while(*mysource != '\0')
	{
		flag++;
		if(flag%2 == 0)
		{
			*mybuf1 = *mysource;
			 mybuf1++;		
		}
		else if(flag%2 == 1)
		{
			*mybuf2 = *mysource;
			*mybuf2++;
		}
		mysource++;
	}
	*mybuf2 = '\0';
	*mybuf1 = '\0';

	//*mysource = '\0';

	return ret;
}

void main()
{
	int ret = 0;
	char *source = "1a2b3d4z";
	char buf1[60] = {0};
	char buf2[60] = {0};

	ret = getStr1Str2(source, buf1, buf2);
	if(ret != 0)
	{
		printf("func getStr1Str2() err \n");
		return ;
	}
	printf("buf1 : %s \n", buf1);
	printf("buf2 : %s \n", buf2);

	printf("hello...\n");
	system("pause");

	return ;
}