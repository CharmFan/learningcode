/*
	��ֵ�ԣ�"key=valude"���ַ������ڿ����о���ʹ��
	Ҫ��1���Լ�����һ���ӿڣ�ʵ�ָ���key��ȡvalude
	Ҫ��2����д��������
	Ҫ��3����ֵ���м������n���ո���ȡ���ո�
	ע�⣺��ֵ���ַ�����ʽ�������£�
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
	mykeyvaluebuf++; //ָ����ں� ����һλ
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