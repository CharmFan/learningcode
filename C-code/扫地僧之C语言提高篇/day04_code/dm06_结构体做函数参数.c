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


// �ṹ������ 3 ������ʦ�����䣬����
void main11()
{
	int     i = 0;
	int   num = 3;
	Teacher Array[3];
	
	for(i=0; i<3; i++)
	{
		printf("\n please enter age:");
		scanf("%d",&(Array[i].age));

	}

	//��ӡ��ʦ����
	for(i=0; i<num; i++)
	{		printf("age:%d \n", Array[i].age);
	}

	printf("����֮�� \n");
	sortTeacher(Array,num);

	printTeacher(Array,num);

	printf("hello... \n");
	system("pause");
	return;
}

//********************************************************************
Teacher * createTeacher(int num)
{
	Teacher * tmp = NULL;

	tmp = (Teacher *)malloc(sizeof(Teacher) * num);//Teacher Array[3]; 
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp;//֮ǰ��д ���� ��ȻҲ����
}

void FreeTeacher(Teacher *p)
{
	if (p != NULL)
	{
		free(p);
	}
}

// �ṹ������ 3 ������ʦ�����䣬����
void main()
{
	int     i = 0;
	int   num = 3;
	//Teacher Array[3];  //��stack �����ڴ� 
	Teacher *pArray =NULL;
	pArray = createTeacher(num);

	for(i=0; i<num; i++)
	{
		printf("\n please enter age:");
		scanf("%d",&(pArray[i].age));
	}

	//��ӡ��ʦ����
	for(i=0; i<num; i++)
	{
		printf("age:%d \n", pArray[i].age);
	}

	printf("����֮�� \n");
	sortTeacher(pArray,num);

	printTeacher(pArray,num);

	FreeTeacher(pArray); //�ͷ��ڴ� + ��ƨ��
	pArray = NULL;      //��ƨ��

	printf("pArray %d:  \n",pArray);


	printf("hello... \n");
	system("pause");
	return;
}