#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void main81()                                  
{
	int a = 10;
	char *p1 = NULL;  //����4���ֽڵ��ڴ�
	char *****p2 = NULL;

	int * p3 = NULL;
	p3 = &a;
	*p3 = 254;   //����޸�a��ֵ
	//ָ�����һ��Կ�ף�ͨ��һ����ַ��&a����ȥ�޸�a�����ı�ʾ���ڴ�

	{
		int c = 0 ;
		c = *p3;
		//*p ����=��ߣ�д�ڴ�
		//*p ����=�ұߣ����ڴ�
		printf("c:%d \n",c);
	}
	{
		/* �ر�ע�� �����ϵĸ�ָ�븳ֵ���൱�ڲ�ͣ�ĸı�ָ���ָ�� */
		char *p4;
		p4 = (char *)malloc((sizeof(char) * 5 ));
		p4 = (char *)malloc((sizeof(char) * 5 ));
	}
	printf("a:%d \n", a);
	printf("��ַ��С a:%d , p1:%d , p2 :%d\n ", sizeof(a), sizeof(p1), sizeof(p2));
	printf("hello...\n");
	system("pause");

	return ;
}

//********************************************************************
char * getStr()
{
	char * tmp = NULL;
 	tmp = "abcdefg";
	return tmp;
}

void  main()
{
	char *p = getStr();
	printf("p : %s \n", p);
	printf("p�ĵ�ַ : %p \n", p);

	/* ע�⣺��������±�������䣬���������崻����      */
  //  *(p+2)   = 'k'; //�������ֵĴ���ָ֤����ָ����ڴ�ռ� ���Ա��޸�
    /*  pָ���˳���������������޸ģ�������򱻲���ϵͳ�����ģ�
	    ���ͨ��ָ�뽨����ֵ �޸��ڴ�ռ�  �ͻ����          */

	//*p = 5;
	//printf("*p =  %d \n", *p);
	system("pause");
	return;
}
//****************************************************************

char * getABC1(char *p);
char * getABC2(char **p);
char * getABC3(char *p);
char * getABC4(char (*p)[30]);
char * getABC5(char p5[10][30]);
//�β��������������β��ж༶ָ���ʱ��
//վ�ڱ������ĽǶȣ�ֻ��Ҫ����4���ֽڵ��ڴ棨32bitƽ̨��
//������ʹ���ڴ��ʱ�����ǲŹ���ָ����ָ����ڴ� ��һά���Ƕ�ά

void main83()
{
	system("pause");
	return;
}
//****************************************************************