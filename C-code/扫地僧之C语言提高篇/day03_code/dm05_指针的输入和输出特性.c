#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*
	ָ������������ģ��
		ָ�������룺�������������ڴ�
		ָ����������������������ڴ�
*/

//���ļ��������λ��ĳ���
int getMem(char **myp1, int *mylen1, char **myp2, int *mylen2)
{
	char *tmp1 = NULL;
	char *tmp2 = NULL;

	tmp1 = (char *)malloc(100);
	if(tmp1==NULL)
	{
		return -1;
	}
	strcpy(tmp1,"abcdefg");

	*mylen1 = strlen(tmp1);
	*myp1 = tmp1;//����޸�ʵ��p1��ֵ

	tmp2 = (char *)malloc(100);
	if(tmp2 == NULL)
	{
		return -2;
	}
	strcpy(tmp2,"11223333");

	*mylen2 = strlen(tmp2);
	*myp2 = tmp2;//����޸�ʵ��p2��ֵ

	return 0;
}
int getMen_Free0(char **myp1)
{
	char *tmp = NULL;
	if(myp1 == NULL)
	{
		return -1;
	}
	tmp = *myp1;

	free(tmp);  //�ͷ���ָ�������ָ����ڴ�ռ�
	tmp = NULL; //��ʵ���޸�ΪNULL

	return 0;
}

void main0()
{
	char *p1 = NULL;
	int len1 = 0;

	char *p2 = NULL;
	int len2 = 0;
	int ret = 0;

	ret = getMem(&p1, &len1, &p2, &len2); 

	printf("p1:%s \n",p1);
	printf("p2:%s \n",p2);

	getMen_Free0(&p1);
	getMen_Free0(&p2);

	system("pause");
	return ;
}

//*********************************  ����Ұָ��  ***********************************************
int getMen_Free1(char *myp1)
{
	char *tmp = NULL;
	if(myp1 == NULL)
	{
		return -1;
	}
	tmp = myp1;

	free(tmp);  //�ͷ���ָ�������ָ����ڴ�ռ�
	tmp = NULL; /**  ����ʵ�����β�û�а�ëǮ��ϵ ====�����ܰ�ʵ���޸�ΪNULL */


	return 0 ;
}

void main()
{
	char *p1 = NULL;
	int len1 = 0;

	char *p2 = NULL;
	int len2 = 0;
	int ret = 0;

	ret = getMem(&p1, &len1, &p2, &len2); 

	printf("p1:%s \n",p1);
	printf("p2:%s \n",p2);

	getMen_Free1(p1);  //�ڱ��������У���p1��ָ����ڴ�ռ���ͷŵ������ǣ�ʵ��p1���ܱ��޸ĳ�NULL����Ұָ������
	getMen_Free1(p2);

	system("pause");
	return ;
}
//******************************************************************************