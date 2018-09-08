#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***************************   结构体中套  二级指针   *******************************/
/***********************  掌握内存模型图  如何分配内存 如何释放内存   *************/

typedef struct Teacher
{
	char name[64];
	char *aliasname;
	char **stuname;
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
	 char **p = NULL;
	int i = 0;
	int j = 0;

	tmp = (Teacher *)malloc(sizeof(Teacher) * num);//Teacher Array[3]; 
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0 ,sizeof(Teacher) * num);
	 

	for(i=0; i<num; i++)
	{
		//malloc 一级指针
		tmp[i].aliasname = (char *)malloc(60);

		//二级指针的第三种内存模型	
		p = (char **)malloc(3 * sizeof(char *));
		if(p == NULL)
		{
			return -1;
		}

		for(j=0; j<3; j++)
		{
			p[j] = (char *)malloc(120);
			if(p[j] == NULL)
			{
				return -2;
			}
		}
		tmp[i].stuname = p; 
		
	}

	*pT = tmp;  //二级指针 形参  去间接的修改 实参的值

	return 0;
}

void FreeTeacher(Teacher *p, int num)
{
	int  i = 0;
	int	 j = 0;

	if (p == NULL)
	{
		return;
	}

	for(i=0; i<num; i++)
	{
		//释放一级指针
		if(p[i].aliasname != NULL)
		{
			free(p[i].aliasname);	
		}

		//释放二级指针
		if(p[i].stuname != NULL)
		{
			//********  接过来，小技巧  ***************
			char **myp = p[i].stuname;  
			for(j=0; j<3; j++)
			{
				if(myp[j] != NULL)
				{
					free(myp[j]);
				}
			}
			free(myp);
			p[i].stuname = NULL;			
		}
	}

	free(p);
}


// 结构体数组 3 输入老师的年龄，排序
void main()
{
	int     i = 0;
	int j = 0;
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

		//printf("\n please enter name:");
		//scanf("%s",(pArray[i].name));       

		printf("\n please enter alias:");
		scanf("%s",(pArray[i].aliasname));   
		                                    
		printf("\n please enter name:");
		scanf("%s",(pArray[i].name));  

		for(j=0; j<3; j++)
		{
			printf("\n please enter student name:");
			scanf("%s",(pArray[i].stuname[j]));      
		}
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
/*
	1、按照名字排序
	2、课本的题目
*/