#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//char *p = "abcd21342abcd3254abcd45abcd"
//���ַ���p�У�"abcd" ���ֵĴ���

/*
  strstr(str1,str2) ���������ж��ַ���str2�Ƿ���str1���Ӵ���
  ����ǣ���ú�������str2��str1���״γ��ֵĵ�ַ�����򣬷���NULL��
 */
void main11()
{
	int ncount = 0;
	char *p = "abcd21342abcd3254abcd45abcd";

	do
	{
		p = strstr(p, "abcd");
		if(p != NULL)
		{
			ncount++;
			p = p + strlen("abcd");
		}
	}while (*p != '\0');

	printf("ncount : %d\n",ncount);

	printf("hello...\n");
	system("pause");

	return ;
}

//**************************************************
void main22()
{
	//strstr
	int ncount = 0;
	char *p = "abcd21342abcd3254abcd45abcd";

	while (p = strstr(p, "abcd"))
	{
		ncount++;
		p = p + strlen("abcd"); //��ָ��ﵽ��������
		if(*p == '\0')
		{
			break;
		}
	
	}

	printf("ncount : %d\n",ncount);

	printf("hello...\n");
	system("pause");

	return ;
}

//**************************************************
//1�����Զ��庯���ӿڣ��������Ҫ��
//2���Զ����ҵ���� �� main���� ��������ֿ�

int getCount(char *mystr/*in*/, char *sub/*in*/, int *ncount)
{
	int ret = 0;
	char *p = mystr; //�����׸ı�ָ���ָ��
	int tmpCount = 0;

	if(mystr==NULL || sub==NULL || ncount==NULL)
	{
		ret = -1;
		printf("func getCount() err :%d (mystr==NULL || sub==NULL || ncount==NULL) \n", ret);
		return ret;
	}

	while (p = strstr(p, sub))
	{
		tmpCount++;
		p = p + strlen(sub); //��ָ��ﵽ��������
		if(*p == '\0')
		{
			break;
		}
	}

	*ncount = tmpCount;
	return ret;
}

//******************************** һ����������ĵط�  **************************************
int getCount(char *mystr/*in*/, char *sub/*in*/, int *ncount)
{
	int ret = 0;
	char *p = mystr; //�����׸ı�ָ���ָ��
	int tmpCount = 0;

	if(mystr==NULL || sub==NULL || ncount==NULL)
	{
		ret = -1;
		printf("func getCount() err :%d (mystr==NULL || sub==NULL || ncount==NULL) \n", ret);
		return ret;
	}

	while (p = strstr(p, sub))
	{
		
		//**********************  ����֮��   ******************
		//tmpCount++;
		//********�޸�Ϊ���´��� ����ʾ�� ****
		//++��׺���������ȼ��ߣ�������ִ��*p������Ȼ���ַ++
		// *ncount++; //��ʱ���Ѿ��ı� ncount�ĵ�ַָ��
		//��ȷʾ�� (*ncount)++��
		//**********************  ����֮��   ******************

	  p = p + strlen(sub); //��ָ��ﵽ��������
		if(*p == '\0')
		{
			break;
		}
	}

	*ncount = tmpCount;
	return ret;
}
//******************************************************

int main()
{
	int ret = 0;
	int count = 0;
	char *p = "abcd21342abcd3254abcd45abcd";
	char sub[] = "abcd";

	ret = getCount(p, NULL, &count);
	if(ret != 0)
	{
		printf("func getCount() err : %d \n", ret);
		return ret;
	}

	printf("count : %d\n",count);
	printf("hello...\n");
	system("pause");

	return ;
}
