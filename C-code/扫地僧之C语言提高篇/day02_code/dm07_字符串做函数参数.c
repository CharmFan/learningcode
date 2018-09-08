#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void main01()
{
	char a[] = "i am a student";
	char b[64];
	int i =0;

	for(i=0; *(a+i) != '\0'; i++)
	{
		*(b+i) = *(a+i);	
	}
	// 0 没有copy到buf中
	b[i] = '\0';  

	printf("a:%s \n", a);
	printf("b:%s \n", b);   //打印的时候，遇到‘\0’结束，如果没有这一步 b[i] = '\0';打印会出错

	system("pause");
	return;
}


/**********************    经典案列   好好理解  start  ****************************/
//********************************************************************************
//字符串copy函数技术推演

//字符串copy函数
void copy_str21(char *from, char *to)
{
	for( ; *from != '\0'; from++,to++)
	{
		*to = *from;
	}
	*to = '\0';

	return;
}

//其实, * 与 ++  其中，++优先级高,
//但是 *to++ = *from++;
//此时,++是后缀,等同于 先运算*to =*from; 再运算to++; from++;

void copy_str22(char *from, char *to)
{
	for( ; *from != '\0'; )
	{
		*to++ = *from++;
	}
	*to = '\0';

	return;
}

//减少手工添加
void copy_str23(char *from, char *to)
{
	while((*to = *from) != '\0')
	{
		from++;
		to++;
	}
}

void copy_str24(char *from,char *to)
{
	while((*to++ = *from++) != '\0')
	{
		;
	}
}

void copy_str25(char *from,char *to)
{
	while(*to++ = *from++)
	{
		;
	}
	//while(*to++ = *from++);  //也可以这样写
}

int copy_str26(char *from,char *to)
{
	if(from == NULL || to == NULL)
	{
		return -1;
	}
	while(*to++ = *from++)
	{
		;
	}
}
//**********************************  教训  ********************************
//不要轻易形参的值，要引用一个辅助的指针变量，把形参给接过来
int copy_str27_good(char *from,char *to)
{
	char *tmpfrom = from;  //为了不轻易改变指针变量的 from to指向
	char *tmpfo = to;
	if(from == NULL || to == NULL)
	{
		return -1;
	}
	while(*to++ = *from++)
	{
		;
	}
	//printf("from :%s\n", from);  //此时没有问题!!!
}

//此函数有问题啊！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
void copy_str28(char *from,char *to)
{
	while(*to++ = *from++)
	{
		;
	}                             /*****************   教训     ********************/
	printf("from :%s\n", from);  //此时，有问题的哈！ 通过的上面的已经修改了from的指向
}
//**********************************  教训  ********************************

void main()
{
	int ret = 0;
	char *from = "abcdefgh";
	char buf[120];

	copy_str21(from, buf);
	printf("buf:%s \n", buf);

	copy_str22(from, buf);
	printf("buf:%s \n", buf);

	copy_str23(from, buf);
	printf("buf:%s \n", buf);

	copy_str24(from, buf);
	printf("buf:%s \n", buf);

	copy_str25(from, buf);
	printf("buf:%s \n", buf);

	copy_str27_good(from, buf);
	printf("buf:%s \n", buf);
//	{
//		//错误案列
//		char *myto = NULL;  //要分配内存
//		copy_str25(from, myto);
//	}

	{
		char *myto = NULL;  //要分配内存

		ret = copy_str26(from, myto);
		if(ret != 0)
		{
			printf("func copy_str26 err \n", ret);
			return ;
		}
	}
	printf("hello...\n");
	system("pause");
	return ;
}

/**********************    经典案列   好好理解   end  ****************************/
//********************************************************************************