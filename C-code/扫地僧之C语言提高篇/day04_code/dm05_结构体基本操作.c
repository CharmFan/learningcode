#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************  ����ṹ������  **************************/

//������һ���������͡��̶���С�ڴ��ı���  ��û�����ڴ�

struct Teacher1
{
	char name[64];
	int age;
	int id;
};

//�����ض���
typedef struct Teacher
{
	char name[64];
	int age;
	int id;
} Teacher;



/***********************     �ṹ�����Ͷ������  ����  ***********************/

//��һ�֣����Ͷ������  main������д

//�ڶ��֣��������͵�ͬʱ,�������
struct Teacher2
{
	char name[64];
	int age;
	int id;
}t3, t4;

//�����֣���������,�������
struct 
{
	char name[64];
	int age;
	int id;
}t5, t6;



/***********************     ��ʼ������  ����  ***********************/
//1�� ������� Ȼ���ʼ��   t9 = {"names", 21, "222"};

//2��
struct Teachars
{
	char name[64];
	int age;
	int id;
}t7 = {"names", 21, "222"};

//3��
struct 
{
	char name[64];
	int age;
	int id;
}t8 = {"names", 21, "222"};



void main11()
{
	struct Teacher1 t1;   //����C���������ҷ����ڴ�	
	//��һ�֣����Ͷ������
	Teacher t2;  //���û��typedef ,��ȱ��struct�ᱨ��ģ���

	t1.age = 31;  //t1.������ �Ǹ�ʲô ��û�в����ڴ�      ********              ********
				  // "." ��Ѱַ���� ����age�����t1������� ƫ���� ==�� ���� cpu�н��С�����
				  //t1.age ��ʱû�в����ڴ�     "="��ʱ����ǲ����ڴ�
	strcpy(t1.name,"tname ");


	//ͨ��ָ��ķ�ʽ ���� �ڴ�ռ� 
	{
		Teacher *p = NULL;
		p = &t1;
		printf("p->age:%d \n",p->age);
		printf("p->name%s \n",p->name);
	}
	printf("t1.name",t1.name);

	printf("hello... \n");
	system("pause");
	return;
}


//**************************************************
void copyTeacher61(Teacher to, Teacher from)//ֻ�ǰ� t3 t1������to from ��Ӱ�� t3  t1
{
	 to = from;
}


void copyTeacher62(Teacher *to, Teacher *from)// to from ��ָ�� t3 t1��ָ��
{
	*to = *from;
}

void main()
{
	Teacher t1 = {"student",25,02};
	Teacher t2;
	Teacher t3;
	memset(&t3, 0 , sizeof(t3));

	t2 = t1;  // = �Ų����� ����������Ϊ
	//�������������ṩ   ******* ��= �� ��ֵ���� ******* ����Ҫ˳��

	printf("t2.name : %s \n",t2.name);
	printf("t2.age : %d \n",t2.age);

	copyTeacher61(t3, t1);  //ֻ�ǰ� t3 t1������to from ��Ӱ�� t3  t1
	printf("t3.name : %s \n", t3.name);
	printf("t3.age : %d \n", t3.age);

	copyTeacher62(&t3, &t1);
	printf("t3.name : %s \n", t3.name);
	printf("t3.age  :%d \n", t3.age);

	printf("hello... \n");
	system("pause");
	return;
}