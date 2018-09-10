#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
	char name[64];
	int age;
	char *name2;
}Teacher;
	
/*******************  浅copy  ******************************* 

	编译器 = 号操作，只把指针变量的值拷贝，从from 拷贝到 to
	但不会 把指针变量所指的内存空间 给copy过去！！！！   
		
	浅copy出现场景 ：
			结构体中套一个一级指针或者是二级指针 

	如果想执行深copy，先执行浅copy,再显示的分配内存空间

******************  浅copy  ********************************/


//如果执行深copy  先浅 再显示的分配内存
void copyTeacher(Teacher *to, Teacher *from)
{
	//*to = *from;
	memcpy(to, from, sizeof(Teacher)) ;

	/************** 宕机之后 新添加部分  **************/
	to->name2 = (char *)malloc(100); //这两行代码，屏蔽后出现宕机
	strcpy(to->name2,from->name2);
	/************** 宕机之后 新添加部分  **************/
}

void main()
{
	Teacher t1;
	Teacher t2;

	strcpy(t1.name,"name1");

	t1.name2 = (char *)malloc(100);
	strcpy(t1.name2,"ssss");

	copyTeacher(&t2,&t1);  //只是机械的把 地址拷贝了一份 只把指针变量的值拷贝 
	printf("t2.name2 : %s \n",t2.name2);

	if (t1.name2 != NULL)
	{
		free(t1.name2);
		t1.name2 = NULL;
	}

	if (t2.name2 != NULL)  /****** 这里会出现宕机  *****/
	{
		free(t2.name2);
		t2.name2 != NULL;
	}

	printf("hello... \n");
	system("pause");
	return;
}