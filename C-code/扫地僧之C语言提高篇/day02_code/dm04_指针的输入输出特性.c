#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*  *p��Ӹ�ֵ������������
		����1 ������������������һ���βΣ�һ����ʵ�Σ�
		����2 ��������ϵ
		����3 ���β�ȥ��ӵ��޸�ʵ�ε�ֵ

	Ӧ�ó�����
		����һ	��1��2��3		д��һ������                          *** 4 ***
		������	��1��2 д��һ��	3����д����һ������  ====> ��������   *** 3 ***
		������	��1����д   2��3дһ��	==>��ש ===>c++ ����
*/

//���ض��ָ��
int getMem3(char **myp1/*out*/, int *mylen1/*out*/, char **myp2/*out*/, int *mylen2/*out*/)
{
	int	ret = 0;
	char	*tmp1, *tmp2;

	tmp1 = (char *)malloc(100);
	strcpy(tmp1, "1234567890");

	//��Ӹ�ֵ
	*mylen1 = strlen(tmp1);  //һ��ָ��
	*myp1 = tmp1;          //����ָ��

	tmp2 = (char *)malloc(100);
	strcpy(tmp2, "qwertyuiop");

	*mylen2 = strlen(tmp2);  //һ��ָ��
	*myp2 = tmp2;          //����ָ��

	return ret;
}

//����һ��ָ��
char * getMem42(int nun)
{
	int ret = 0;
	char	*tmp1;

	tmp1 = (char *)malloc(num);
	strcpy(tmp1, "1234567890");

	return tmp1;
}

/* 
	�ð�����ָ��������������ʵ����һ�����ܣ����ǿ���ͨ�������ķ�ʽ��ƶ�����ܺ������������˷ֲ�ġ�

	***********ָ���������������쳣��Ҫ**************

	���û��ָ����������������û�м򵥵ķֲ㣬
	û�зֲ㣬�Ͳ������нӿڵķ�װ����ƣ�
	û�нӿڵķ�װ����ƾͲ�����������Ĺ��ܺ͹���֮��Ļ��֣�
	û��������Ĺ��ܺ͹���֮��Ļ��֣���û�������Ϣϵͳ��
	û�������Ϣϵͳ����It��û�����˰�������������������������
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
