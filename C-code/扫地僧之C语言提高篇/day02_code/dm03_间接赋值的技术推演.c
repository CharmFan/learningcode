#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*  *p��Ӹ�ֵ������������
		����1 ������������������һ���βΣ�һ����ʵ�Σ�
		����2 ��������ϵ
		����3 ���β�ȥ��ӵ��޸�ʵ�ε�ֵ

	Ӧ�ó�����
		����һ	��1��2��3		д��һ������                          *** 4 ***
		������	��1��2 д��һ��	3����д����һ������  ====> ��������   *** 3 ***
		������	��1����д   2��3дһ��	==>��ש ===>c++ ����
*/


//*****************************************************************    1   ***
//�βε�����
//����������{};
//int a ������С������  �ʹ�����  �����޲��ֻ��С���ŵ��βξ��ж��������
int getMen1(int a)
{
	//int a;
}

int getFileLen(int *p)
{
	*p = 41;  //p��ֵ��a�ĵ�ַ��*p ����޸�a��ֵ
			//����3 ���β�ȥ��ӵ��޸�ʵ�ε�ֵ
}

int getFileLen2(int b)
{
	b = 100;
}

//һ��ָ�� ����޸ı�����ֵ
void main32()
{
	int a = 10;   //����1������������������һ���βΣ�һ����ʵ�Σ�
	int *p = NULL;
	
	//ֱ�Ӹ�ֵ
	a = 10;

	p = &a;  //����2 ��������ϵ
	{
		*p = 23;
		printf("*p = %d\n",*p);
	}

	getFileLen(&a);
	printf("*p = %d\n",*p);

	getFileLen2(a);
	printf("*p = %d\n",*p);

	printf("hello...\n");
	system("pause");

	return ;
}

//*******************************************************  2  ******
void getMen(char **p2)
{
	*p2 = 666;
}
//����ָ�뼼������
void main33()
{
	char *p1 = NULL;
	char **p2 = NULL;

	p1 = 11;
	p2 = 22;

	//ֱ���޸�
	p1 = 111;

	//�����p1, p2��p1�ĵ�ַ
	p2 = &p1;
	*p2 = 222;
	printf("p1 :%d \n", p1);

	{
		*p2 = 2222;
		printf("p1 :%d \n", p1);
	}

	getMen(&p1);
	printf("p1 :%d \n", p1);

	system("pause");
	return ;
}

//**********************************************************  3  ***

int getMem3(char **myp1, int *mylen1, char **myp2, int *mylen2)
{
	int	ret = 0;
	char	*tmp1, *tmp2;

	tmp1 = (char *)malloc(100);
	strcpy(tmp1, "1234567890");

	//��Ӹ�ֵ
	*mylen1 = strlen(tmp1);  //һ��ָ��
	*myp1 = tmp1;          //����ָ��

	tmp2 = (char *)malloc(100);
	strcpy(tmp2, "qwertyuiop");

	*mylen2 = strlen(tmp2);  //һ��ָ��
	*myp2 = tmp2;          //����ָ��

	return ret;
}
/* 
	�ð�����ָ��������������ʵ����һ�����ܣ����ǿ���ͨ�������ķ�ʽ��ƶ�����ܺ������������˷ֲ�ġ�

	***********ָ���������������쳣��Ҫ**************

	���û��ָ����������������û�м򵥵ķֲ㣬
	û�зֲ㣬�Ͳ������нӿڵķ�װ����ƣ�
	û�нӿڵķ�װ����ƾͲ�����������Ĺ��ܺ͹���֮��Ļ��֣�
	û��������Ĺ��ܺ͹���֮��Ļ��֣���û�������Ϣϵͳ��
	û�������Ϣϵͳ����It��û�����˰�������������������������
*/
int main34()
{
	int		ret = 0;
	char	*p1 = NULL;
	int		len1 = 0;
	char	*p2 = NULL;
	int		len2 = 0;

	ret  = getMem3(&p1, &len1, &p2, &len2);
	if(ret != 0)
	{
		printf("func getMem2() err \n");
		return ret;
	}

	printf("p1 : %s \n",p1);
	printf("p2 : %s \n",p2);

	if(p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}

	if(p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}

	system("pause");
	return ;
}

//*******************************************  4 ****
//��Ӹ�ֵ��Ӧ�ó���һ
void main()
{
	char from[128];
	char to[128] = {0};
	char *p1 = from;
	char *p2 = to;

	strcpy(from, "afoihafuiohdsuafohduaofhu");

	while(*p1 != '\0')
	{
		*p2 = *p1;
		p2++;
		p1++;
	}

	printf("to:%s \n",to );

	system("pause");
	return ;
}