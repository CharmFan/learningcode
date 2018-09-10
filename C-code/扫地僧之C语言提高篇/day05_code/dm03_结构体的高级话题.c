#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************  结构体的高级话题  **********************************

        1、一旦结构体定义下来，则结构体中的成员  内存布局就定下来了 ！！
        2、可以通过age地址，去求大的结构体的内存地址！！

		如果定义了一个头文件，不要让人轻易的改变你结构体中的顺序！！偏移量问题。。。

*****************************************  结构体的高级话题  **********************************/
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
	//strcpy(p, "aaa");  宕机      原因：等价于 strcpy(0, "aaa");

	p = &t1;  //int offsize = (int)&(p->age);//这样取得的是 &(t1.age)的绝对地址

	/*********************  注意理解 *****************************

		"p - 1"  编译通过 运行通过  （指针就是一个变量）   《加减乘除 都是在cpu里运算》

		放在寄存器里的 是在CPU里面运算 没有操作内存空间	
		"p - 1" 在CPU里运行，绝对没有操作内存！！ 

		如果是这样" *(p-1) ", 这才是操作内存！！

	 *********************  注意理解 ****************************/ 
	//p - 1;	
	//p - 2;

	//p - p;
	//指针加指针没有意义 

	{
		int offsize1 = (int)&(p->age) - (int)p;//相对偏移量 64
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
	//strcpy(p, "aaa");  宕机      原因：等价于 strcpy(0, "aaa");
	p = &t1;

	//p - p;  这里等于 = 0
	//指针加指针没有意义 
	{
		int offsize1 = (int)&(p->age) - (int)p;//相对偏移量 64

		//求出了  相对于0这个的位置的地址
		int offsize2 = (int)&(((AdvTeacher *)0) ->age);     //p - p;  这里等于 = 0
		
		int offsize3 = (int)&(p->age);  //求出了age的真实地址  就这意思：&(t1.age)

		printf("offsize1 = %d \n", offsize1);
		printf("offsize2 = %d \n", offsize2);
	}

	printf("hello... \n");
	system("pause");
	return;
}