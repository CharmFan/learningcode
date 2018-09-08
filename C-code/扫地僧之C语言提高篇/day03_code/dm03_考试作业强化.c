/*
	��ֵ�ԣ�"key=valude"���ַ������ڿ����о���ʹ��
	Ҫ��1���Լ�����һ���ӿڣ�ʵ�ָ���key��ȡvalude
	Ҫ��2����д��������
	Ҫ��3����ֵ���м������n���ո���ȡ���ո�
	ע�⣺��ֵ���ַ�����ʽ�������£�
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

//ȥ���ַ���ǰ��ո�  "��ͷ��ģ��"
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

//����˼· : 
// 1������key�ǲ�����ĸ����
// 2������û�� "="
// 3���ڵȺź���  ȥ���ո�
int getKeyByValude(char *keyvaluebuf, char *keybuf, char *valuebuf)
{
	
	int ret = 0;
	int len = 0;
	char *p = keyvaluebuf;  //��ʼ������ָ�����

	if(keyvaluebuf==NULL || keybuf==NULL || valuebuf==NULL)
	{
		ret = -1;
		printf("func getKeyByValude err :%d (mykeyvaluebuf ==NULL || mykeybuf ==NULL || myvaluebuf ==NULL) \n", ret);
		return ret;
	}

	// 1������key�ǲ�����ĸ����
	p = strstr(p, keybuf);
	if(p == NULL)
	{
		return -1;
	}
	//�ø���ָ����� ���´ﵽ��һ�μ���������
	p = p + strlen(keybuf);


	// 2������û�� "="
	p = strstr(p, "=");
	if(p == NULL)
	{
		return -1;
	}
	//�ø���ָ����� ���´ﵽ��һ�μ���������
	p = p + strlen("=");


	// 3���ڵȺź���  ȥ���ո�
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