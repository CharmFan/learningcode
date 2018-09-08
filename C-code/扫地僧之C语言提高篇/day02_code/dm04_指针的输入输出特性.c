#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*  *p间接赋值成立的条件：
		条件1 ：定义了两个变量（一个形参，一个是实参）
		条件2 ：建立关系
		条件3 ：形参去间接的修改实参的值

	应用场景：
		场景一	：1、2、3		写在一个函数                          *** 4 ***
		场景二	：1、2 写在一块	3单独写在另一个函数  ====> 函数调用   *** 3 ***
		场景三	：1单独写   2、3写一块	==>抛砖 ===>c++ 会有
*/

//返回多个指针
int getMem3(char **myp1/*out*/, int *mylen1/*out*/, char **myp2/*out*/, int *mylen2/*out*/)
{
	int	ret = 0;
	char	*tmp1, *tmp2;

	tmp1 = (char *)malloc(100);
	strcpy(tmp1, "1234567890");

	//间接赋值
	*mylen1 = strlen(tmp1);  //一级指针
	*myp1 = tmp1;          //二级指针

	tmp2 = (char *)malloc(100);
	strcpy(tmp2, "qwertyuiop");

	*mylen2 = strlen(tmp2);  //一级指针
	*myp2 = tmp2;          //二级指针

	return ret;
}

//返回一个指针
char * getMem42(int nun)
{
	int ret = 0;
	char	*tmp1;

	tmp1 = (char *)malloc(num);
	strcpy(tmp1, "1234567890");

	return tmp1;
}

/* 
	该案例是指针做函数参数，实现了一个功能，我们可以通过这样的方式设计多个功能函数，初步有了分层的。

	***********指针做函数参数，异常重要**************

	如果没有指针做函数参数，就没有简单的分层，
	没有分层，就不可能有接口的封装和设计，
	没有接口的封装和设计就不可能有软件的功能和功能之间的划分，
	没有有软件的功能和功能之间的划分，就没有软件信息系统，
	没有软件信息系统，做It就没得玩了啊。！！！！！！！！！！！
*/
int main()
{
	int		ret = 0;
	char	*p1 = NULL;
	int		len1 = 0;
	char	*p2 = NULL;
	int		len2 = 0;

	ret  = getMem3(&p1, &len1, &p2, &len2);
	if(ret != 0)
	{
		printf("func getMem2() err \n");
		return ret;
	}

	printf("p1 : %s \n",p1);
	printf("p2 : %s \n",p2);

	if(p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}

	if(p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}

	system("pause");
	return ;
}
