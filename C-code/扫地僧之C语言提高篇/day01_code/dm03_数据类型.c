#include "stdlib.h"
#include "string.h"
#include "stdio.h"

//�������͵���;
//�������͵ı��ʣ��̶���С�ڴ��ı���
//b &b �����������ͣ�1������һ���������� 2������һ��ָ������  3���������ͺ�����ָ�����͵Ĺ�ϵ��

 struct Teacher
{
	char name[40];
	int age;
}Teacher;

typedef struct Teacher2
{
	short name[39];
	int age;
}Teacher2;


void main()
{
	/*ϸ������*/ 
	//��c�����������ӡ�����������   
	//�����c++�����в��������⣬ԭ����c++�ж�struct�����˹�����ǿ
	//Teacher st;   
	//�޸�Ϊ��
	//struct  Teacher st;  
	//����
	 Teacher2  st1;
	 printf("Teacher2: %d\n",sizeof(Teacher2));
	 printf("sizeof(st1): %d\n",sizeof(st1));
     printf("sizeof(st1.name): %d\n",sizeof(st1.name));
	 printf("sizeof(st1.age): %d\n",sizeof(st1.age));
	 /* �ṹ�����ڴ��д���ǰ���Ԫ��ŵģ�ÿ����Ԫ���ȡ���ڽṹ�������������͵Ĵ�С */
	 system("pause");
} 


void main1()
{
	int a; //����c����������4���ֽڵ��ڴ�
	int b[10];//����C ����������40���ֽڵ��ڴ�

	printf("b:%d, b+1:%d, &b:%d, &b+1:%d\n",b ,b+1,&b, &b+1 );

	//����һ�ν����b:15334620, b+1:15334624, &b:15334620, &b+1:15334660
	             // b  b+1 ���4      &b &b+1 ���40 

	//b+1 &b+1 �����һ��  //b &b���������������һ��
	//b������������Ԫ�صĵ�ַ
	//&b���������������ĵ�ַ
	printf("sizeof(a):%d\n", sizeof(a));
	printf("sizeof(b):%d\n", sizeof(b));

	printf("hello...\n");
	system("pause");
}