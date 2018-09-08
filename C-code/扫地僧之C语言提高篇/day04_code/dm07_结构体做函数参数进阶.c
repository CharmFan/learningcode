#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
	char name[64];
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

	tmp = (Teacher *)malloc(sizeof(Teacher) * num);//Teacher Array[3]; 
	if (tmp == NULL)
	{
		return -1;
	}
	*pT = tmp;  //二级指针 形参  去间接的修改 实参的值

	return 0;
}

void FreeTeacher(Teacher *p)
{
	if (p != NULL)
	{
		free(p);
	}
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
	}

	//打印老师年龄
	for(i=0; i<num; i++)
	{
		printf("age:%d \n", pArray[i].age);
	}

	printf("排序之后 \n");
	sortTeacher(pArray,num);

	printTeacher(pArray,num);

	FreeTeacher(pArray); //释放内存 + 擦屁股
	pArray = NULL;      //擦屁股

	printf("pArray %d:  \n",pArray);


	printf("hello... \n");
	system("pause");
	return;
}