#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************  �ṹ��ĸ߼�����  **********************************

        1��һ���ṹ�嶨����������ṹ���еĳ�Ա  �ڴ沼�־Ͷ������� ����
        2������ͨ��age��ַ��ȥ���Ľṹ����ڴ��ַ����

		���������һ��ͷ�ļ�����Ҫ�������׵ĸı���ṹ���е�˳�򣡣�ƫ�������⡣����

*****************************************  �ṹ��ĸ߼�����  **********************************/
typedef struct AdvTeacher
{
	char name[64];
	int age;
	int p;
	char *name2;
}AdvTeacher;

void main01()
{
	AdvTeacher t1;
	AdvTeacher *p = NULL;	
	//strcpy(p, "aaa");  崻�      ԭ�򣺵ȼ��� strcpy(0, "aaa");

	p = &t1;  //int offsize = (int)&(p->age);//����ȡ�õ��� &(t1.age)�ľ��Ե�ַ

	/*********************  ע����� *****************************

		"p - 1"  ����ͨ�� ����ͨ��  ��ָ�����һ��������   ���Ӽ��˳� ������cpu�����㡷

		���ڼĴ������ ����CPU�������� û�в����ڴ�ռ�	
		"p - 1" ��CPU�����У�����û�в����ڴ棡�� 

		���������" *(p-1) ", ����ǲ����ڴ棡��

	 *********************  ע����� ****************************/ 
	//p - 1;	
	//p - 2;

	//p - p;
	//ָ���ָ��û������ 

	{
		int offsize1 = (int)&(p->age) - (int)p;//���ƫ���� 64
		printf("%d \n", offsize1);
	}

	printf("hello... \n");
	system("pause");
	return;
}


void main()
{
	AdvTeacher t1;
	AdvTeacher *p = NULL;	
	//strcpy(p, "aaa");  崻�      ԭ�򣺵ȼ��� strcpy(0, "aaa");
	p = &t1;

	//p - p;  ������� = 0
	//ָ���ָ��û������ 
	{
		int offsize1 = (int)&(p->age) - (int)p;//���ƫ���� 64

		//�����  �����0�����λ�õĵ�ַ
		int offsize2 = (int)&(((AdvTeacher *)0) ->age);     //p - p;  ������� = 0
		
		int offsize3 = (int)&(p->age);  //�����age����ʵ��ַ  ������˼��&(t1.age)

		printf("offsize1 = %d \n", offsize1);
		printf("offsize2 = %d \n", offsize2);
	}

	printf("hello... \n");
	system("pause");
	return;
}