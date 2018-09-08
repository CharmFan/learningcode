#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***************************   结构体中套一级指针   *******************************/
/***********************  掌握内存模型图  如何分配内存 如何释放内存   *************/
typedef struct Teacher
{
	char name[64];
	char * aliasname;
	int age;
	int id;
}Teacher;

void printTeacher(Teacher *array, int num)
{
	int i = 0;

	for(i=0; i<num; i++)
	{
		printf("age:%d \n", array[i].age);
	}
}

void sortTeacher(Teacher *array, int num)
{
	int i,j;
	Teacher tmp;

	for(i=0; i<num; i++)
	{
		for(j=i+1; j<num; j++)
		{
			if(array[i].age > array[j].age)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}

	}
}

int createTeacher(char **pT, int num)
{
	Teacher * tmp = NULL;
	int i = 0;

	tmp = (Teacher *)malloc(sizeof(Teacher) * num);//Teacher Array[3]; 
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0 ,sizeof(Teacher) * num);
	 
	//******************* 之前宕机 由于没有下面代码分配内存空间 ***********************
	for(i=0; i<num; i++)
	{
		tmp[i].aliasname = (char *)malloc(60);
	}
	//********************************************************************************
	*pT = tmp;  //二级指针 形参  去间接的修改 实参的值

	return 0;
}

void FreeTeacher(Teacher *p, int num)
{
	int  i = 0;

	if (p == NULL)
	{
		return;
	}

	for(i=0; i<num; i++)
	{
		if(p[i].aliasname != NULL)
		{
			free(p[i].aliasname);	
		}
	}

	free(p);
}


// 结构体数组 3 输入老师的年龄，排序
void main()
{
	int     i = 0;
	int ret = 0;
	int   num = 3;

	Teacher *pArray =NULL;
	createTeacher(&pArray, num);

	if(ret != 0)
	{
		printf("func creatTeacher err \n");
		return 0;
	}

	for(i=0; i<num; i++)
	{
		printf("\n please enter age:");
		scanf("%d",&(pArray[i].age));

		printf("\n please enter name:");
		scanf("%s",(pArray[i].name));        //向指针所执行的内存空间的copy数据

		printf("\n please enter alias:");
		scanf("%s",(pArray[i].aliasname));   //向指针所执行的内存空间的copy数据  *********** 直接运行会宕机 ****************
		                                    // 结构体变量的时候char name[64]; （64）  char * aliasname; （4）
		                                    //  如果要对aliasname所指向的内存空间copy数据就得给人家分配内存 ,没有内存哪来指针
	                                        // creatTeacher 中分配内存
		 
	}

	//打印老师年龄
	for(i=0; i<num; i++)
	{
		printf("age:%d \n", pArray[i].age);
	}

	printf("排序之后 \n");
	sortTeacher(pArray,num);

	printTeacher(pArray,num);


	FreeTeacher(pArray, num); //释放内存 + 擦屁股
	pArray = NULL;      //擦屁股

	printf("pArray %d:  \n",pArray);

	system("pause");
	return;
}