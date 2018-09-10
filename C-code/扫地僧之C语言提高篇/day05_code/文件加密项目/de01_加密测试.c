#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "des.h"

void main01()
{
	 int ret = 0 ;
	 char *plain = "1232343444";
	 int plainlen = strlen(plain);

	 char plain2[4096];
	 int plainlen2 = 0;

	 unsigned char cryptbuf[4096];
	 int crpytlen = 0;

	//�û�ʹ�õĺ���
	ret =  DesEnc(plain, plainlen, cryptbuf, &crpytlen);
	if (ret != 0)
	{
		printf("func DesEnc() err:%d \n", ret);
		return ret;
	}

	//�û�ʹ�ú���des����
	ret =  DesDec(cryptbuf, crpytlen, plain2, &plainlen2);
	if (ret != 0)
	{
		printf("func DesDec() err:%d \n", ret);
		return ret;
	}

	if (plainlen != plainlen2)
	{
		ret = -2;
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ���  ��һ�� \n");
		return ret;
	}

	if  (memcmp(plain2, plain, plainlen) == 0)
	{
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ���  һ�� ok \n");
	}
	else
	{
		printf("���ĳ��Ⱥͽ��ܺ�����ĳ��� ��һ�� err \n");
	}

	printf("\nhello...\n");
	system("pause");
	return ;
}
