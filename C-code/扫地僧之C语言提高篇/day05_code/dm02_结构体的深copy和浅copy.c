#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
	char name[64];
	int age;
	char *name2;
}Teacher;
	
/*******************  ǳcopy  ******************************* 

	������ = �Ų�����ֻ��ָ�������ֵ��������from ������ to
	������ ��ָ�������ָ���ڴ�ռ� ��copy��ȥ��������   
		
	ǳcopy���ֳ��� ��
			�ṹ������һ��һ��ָ������Ƕ���ָ�� 

	�����ִ����copy����ִ��ǳcopy,����ʾ�ķ����ڴ�ռ�

******************  ǳcopy  ********************************/


//���ִ����copy  ��ǳ ����ʾ�ķ����ڴ�
void copyTeacher(Teacher *to, Teacher *from)
{
	//*to = *from;
	memcpy(to, from, sizeof(Teacher)) ;

	/************** 崻�֮�� ����Ӳ���  **************/
	to->name2 = (char *)malloc(100); //�����д��룬���κ����崻�
	strcpy(to->name2,from->name2);
	/************** 崻�֮�� ����Ӳ���  **************/
}

void main()
{
	Teacher t1;
	Teacher t2;

	strcpy(t1.name,"name1");

	t1.name2 = (char *)malloc(100);
	strcpy(t1.name2,"ssss");

	copyTeacher(&t2,&t1);  //ֻ�ǻ�е�İ� ��ַ������һ�� ֻ��ָ�������ֵ���� 
	printf("t2.name2 : %s \n",t2.name2);

	if (t1.name2 != NULL)
	{
		free(t1.name2);
		t1.name2 = NULL;
	}

	if (t2.name2 != NULL)  /****** ��������崻�  *****/
	{
		free(t2.name2);
		t2.name2 != NULL;
	}

	printf("hello... \n");
	system("pause");
	return;
}