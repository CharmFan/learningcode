#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************  定义结构体类型  **************************/

//定义了一个数据类型。固定大小内存块的别名  还没分配内存

struct Teacher1
{
	char name[64];
	int age;
	int id;
};

//类型重定义
typedef struct Teacher
{
	char name[64];
	int age;
	int id;
} Teacher;



/***********************     结构体类型定义变量  三种  ***********************/

//第一种：类型定义变量  main中有书写

//第二种：定义类型的同时,定义变量
struct Teacher2
{
	char name[64];
	int age;
	int id;
}t3, t4;

//第三种：匿名类型,定义变量
struct 
{
	char name[64];
	int age;
	int id;
}t5, t6;



/***********************     初始化变量  三种  ***********************/
//1、 定义变量 然后初始化   t9 = {"names", 21, "222"};

//2、
struct Teachars
{
	char name[64];
	int age;
	int id;
}t7 = {"names", 21, "222"};

//3、
struct 
{
	char name[64];
	int age;
	int id;
}t8 = {"names", 21, "222"};



void main11()
{
	struct Teacher1 t1;   //告诉C编译器给我分配内存	
	//第一种：类型定义变量
	Teacher t2;  //如果没有typedef ,并缺少struct会报错的！！

	t1.age = 31;  //t1.操作符 是干什么 有没有操作内存      ********              ********
				  // "." 是寻址操作 计算age相对于t1大变量的 偏移量 ==》 计算 cpu中进行。。。
				  //t1.age 此时没有操作内存     "="的时候才是操作内存
	strcpy(t1.name,"tname ");


	//通过指针的方式 操作 内存空间 
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
void copyTeacher61(Teacher to, Teacher from)//只是把 t3 t1拷贝给to from 不影响 t3  t1
{
	 to = from;
}


void copyTeacher62(Teacher *to, Teacher *from)// to from 是指向 t3 t1的指针
{
	*to = *from;
}

void main()
{
	Teacher t1 = {"student",25,02};
	Teacher t2;
	Teacher t3;
	memset(&t3, 0 , sizeof(t3));

	t2 = t1;  // = 号操作下 编译器的行为
	//编译器给我们提供   ******* 简单= 号 赋值操作 ******* 我们要顺从

	printf("t2.name : %s \n",t2.name);
	printf("t2.age : %d \n",t2.age);

	copyTeacher61(t3, t1);  //只是把 t3 t1拷贝给to from 不影响 t3  t1
	printf("t3.name : %s \n", t3.name);
	printf("t3.age : %d \n", t3.age);

	copyTeacher62(&t3, &t1);
	printf("t3.name : %s \n", t3.name);
	printf("t3.age  :%d \n", t3.age);

	printf("hello... \n");
	system("pause");
	return;
}