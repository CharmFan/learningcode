#include "stdlib.h"
#include "string.h"
#include "stdio.h"

//数据类型的用途
//数据类型的本质：固定大小内存块的别名
//b &b 数组数据类型（1、定义一个数组类型 2、定义一个指针数组  3、数组类型和数组指针类型的关系）

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
	/*细节问题*/ 
	//在c语言中这样子、定义有问题   
	//如果是c++语言中不会有问题，原因是c++中对struct进行了功能增强
	//Teacher st;   
	//修改为：
	//struct  Teacher st;  
	//或者
	 Teacher2  st1;
	 printf("Teacher2: %d\n",sizeof(Teacher2));
	 printf("sizeof(st1): %d\n",sizeof(st1));
     printf("sizeof(st1.name): %d\n",sizeof(st1.name));
	 printf("sizeof(st1.age): %d\n",sizeof(st1.age));
	 /* 结构体在内存中存放是按单元存放的，每个单元多大取决于结构体中最大基本类型的大小 */
	 system("pause");
} 


void main1()
{
	int a; //告诉c编译器分配4个字节的内存
	int b[10];//告诉C 编译器分配40个字节的内存

	printf("b:%d, b+1:%d, &b:%d, &b+1:%d\n",b ,b+1,&b, &b+1 );

	//运行一次结果：b:15334620, b+1:15334624, &b:15334620, &b+1:15334660
	             // b  b+1 相差4      &b &b+1 相差40 

	//b+1 &b+1 结果不一样  //b &b所代表的数据类型一样
	//b代表的数组的首元素的地址
	//&b代表的是整个数组的地址
	printf("sizeof(a):%d\n", sizeof(a));
	printf("sizeof(b):%d\n", sizeof(b));

	printf("hello...\n");
	system("pause");
}