#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<malloc.h>

/*
	1��ָ��ָ��˭���Ͱ�˭��ַ����ָ��
	2��ָ���������ָ����ڴ�ռ������������ͬ�ĸ���
	3�����ָ��Ĺؼ������ڴ棬û���ڴ�������ָ��
*/

//��
char * getMen(int num)
{
	char * p1  = NULL;
	p1 = (char *)malloc(sizeof(char) * num);
	if(p1 == NULL)
	{
		return NULL;
	}
	return p1;
} 

//ջ
//ע��,return ���ǰ��ڴ��50�ֽڸ�return���������ǰ��ڴ����׵�ַ����return������
char * getMen2()
{
	char buf[50];//��ʱ��ţ�ջ�����

	strcpy(buf, "9999");
	//printf("ջ buf:%s\n", buf);

	return buf;  //ջ�������50�ֽڵĿռ䣬�ڴ˺���������ɺ󣬱��������Զ��ͷ�
	             //�����׵�ַ���Կ���������tmp = getMen2();  ����ַ������tmp��,������50�ֵ��ڴ�ռ�����������ˡ�
                 //���ǰ��ڴ�ռ俪ʼ�ı�Ÿ����������ˣ����ǿ�ʼ�ĵط����������ˡ�
}

void main()
{
	char *tmp = NULL;
	
	tmp = getMen(1);
	if(tmp == NULL)
	{
		return;
	}

	strcpy(tmp, "1025"); //��tmpָ����ڴ�ռ���copy����
	printf("�� temp:%s\n", tmp);

	tmp = getMen2();
    printf("ջ temp:%s.\n", tmp);

	/*
		��Debug�£���ӡ    "ջ temp:%s."
		��Release�£���ӡ  "ջ temp:9999."
		���ֵĴ������һ�����ֲ������ǲ��ܽ��ڴ��ת�ƹ�����
	*/

	printf("hello...\n");
	system("pause");
	return;
}

