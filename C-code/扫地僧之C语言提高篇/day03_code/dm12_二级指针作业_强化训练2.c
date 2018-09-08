#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
/*
	��һ���ַ�����������������"abcdef, acccd, eeee, aaaa, e3eeee,ssss,"��Ҫ��дһ���������ӿڣ���������½��
	1���Զ��ŷָ��ַ������γɶ�ά���飬���ѽ������
	2���Ѷ�ά��������������Ҳ����

	�ڱ��������з����ڴ�

	��һ�֣����ض���ָ�룺
		char ** spitString(const char *buf1, char c, int *count)
	�ڶ��֣�����ָ����������������ϵ�һ�֣�
		int spitString(const char *buf1, char c,char ***myp3, int *count)

*/
//�������ֵָ����� �� �����߼�֮��Ĺ�ϵ
/* 
  *************************  ��������ָ����� �� �ַ��� **************************
  *************************      ����ָ��   ����ָ��  ***************************
   *************************   �� ��������  �����ڴ�  ****************************  
*/
//*******************************    ���ض���ָ��   ***************************
/*
   �ڱ��������з����ڴ�  ��һ�֣����ض���ָ�룺
*/
char ** spitString1(const char *buf1, char c, int *count)
{
	char *p = NULL, *pTmp = NULL;
	int tmpcount = 0;
    char **myp = NULL;

	if(buf1 == NULL || count == NULL)
	{
		return NULL;
	}
	
    //��һ�� ���count
	//1�� p �� pTmp ��ʼ��
	p = buf1;
	pTmp = buf1;
	do
	{
		//2�� ��������������λ�� p���� �γɲ�ֵ ���ַ���
		p = strchr(p, c);
		if(p != NULL)
		{
			if(p-pTmp > 0)
			{
				tmpcount++;
				//3������ ��p��ptmp �ﵽ��һ�μ���������
				pTmp = p = p +1;
			}
			else
			{
				break;
			}
		}
	}while(*p != '\0');

	*count = tmpcount;

	//���ݶ����� ��ȷ�����ڴ�
	myp = (char **)malloc(sizeof(char *) * tmpcount);
	if(myp == NULL)
	{
		return NULL;
	}

	//1�� p �� pTmp ��ʼ��
	p = buf1;
	pTmp = buf1;
	tmpcount = 0;
	do
	{
		//2�� ��������������λ�� p���� �γɲ�ֵ ���ַ���
		p = strchr(p, c);
		if(p != NULL)
		{
			if(p-pTmp > 0)
			{
				int len = p -pTmp +1 ;  // +1 Ϊ'\0' �����ڴ�  ����c����
				myp[tmpcount] = (char *)malloc(sizeof(char) * len);
				if(myp[tmpcount] == NULL)
				{
					return NULL;
				}
				strncpy(myp[tmpcount], pTmp, p-pTmp);
				myp[tmpcount][p-pTmp] = '\0';  //�ѵ�һ�����ݱ�� C���Է���ַ���
				tmpcount++;
				//3������ ��p��ptmp �ﵽ��һ�μ���������
				pTmp = p = p +1;
			}
			else
			{
				break;
			}
		}
	}while(*p != '\0');

	return myp;
}

void main11()
{	
	char *p1 = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	int i = 0;
	char cTem = ',';
	int nCount = 0;

	char **p = NULL;  //�����char buf[10][30]  /*** �ж�����ڴ� ***/

	p = spitString1(p1, cTem, &nCount);
	if(p == NULL)
	{
		printf("func spitString() err  \n");
	}

	for(i=0; i<nCount; i++)
	{
		printf("%s\n", p[i]);
	}

	//�ͷ��ڴ�
	for(i=0; i<nCount; i++)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;

	printf("hello...\n");
	system("pause");

	return ;
}
//************************************    ���ض���ָ��   ********************************




//*********************************    ����ָ�� �� ��������   ***************************

//*********************** һ����ڣ�������� ��ͬһ���� goto + memset(����)��һ��������ڴ�ȫ��0  ****
//******* �ڶ���������ĳһ�������ڴ�ʧ�ܣ��жϵڶ�����ĵ�ַ֪��Ϊ�գ�����֪���ж��ٵڶ�������ɹ� ***
/*
   �ڱ������� �� �����ڴ�  �ڶ��֣�����ָ�����������������һ�ַ�ʽ
*/

void FreeMem2(char **myp, int count)
{
	int i =0;
	if(myp == NULL)   //�ж϶���ָ��
	{
		return ;
	}
	for(i=0; i<count; i++)
	{	
		if(myp[i] != NULL)
		{
			free(myp[i]);
		}	
	}
	if(myp != NULL)
	{
		free(myp);
	}
}

void FreeMem3(char ***p, int count)
{
	int i =0;
	char **myp = NULL;
	if(p == NULL)  //�ж�����ָ��
	{
		return ;
	}

	myp = *p;
	if (myp == NULL)  //�ж϶���ָ�����FreeMem2(char **myp, int count) ���ж϶���ָ��
	{
		return ;
	}

	for(i=0; i<count; i++)
	{	
		if(myp[i] != NULL)
		{
			free(myp[i]);
		}	
	}

	if(myp != NULL)
	{
		free(myp);
	}
	*p = NULL; //��ʵ�ζ���ָ���޸�Ϊ NULL
}


/**************************************    ע��   **********************************
     �������һ����ڣ��������  ��� ͬһ���ڣ���ͬһ���ڽ�������ڴ��ͷ�

**************************************    ע��   **********************************
*/
int spitString(const char *buf1, char c,char ***myp3, int *count)
{
	char *p = NULL, *pTmp = NULL;
	int tmpcount = 0;
	char **myp = NULL;
	int ret = 0;

	if(buf1 == NULL || count == NULL || myp3 == NULL)
	{
		return -1;
	}

	//��һ�� ���count
	//1�� p �� pTmp ��ʼ��
	p = buf1;
	pTmp = buf1;
	do
	{
		//2�� ��������������λ�� p���� �γɲ�ֵ ���ַ���
		p = strchr(p, c);
		if(p != NULL)
		{
			if(p-pTmp > 0)
			{
				tmpcount++;
				//3������ ��p��ptmp �ﵽ��һ�μ���������
				pTmp = p = p +1;
			}
			else
			{
				break;
			}
		}
	}while(*p != '\0');

	*count = tmpcount;

	//���ݶ����� ��ȷ�����ڴ�
	myp = (char **)malloc(sizeof(char *) * tmpcount);
	if(myp == NULL)
	{
		ret = -2;
		printf("func spitString() err err:%d  tmpcount* sizeof(char *) ", ret);
		goto END;
		//return -2;
	}
	memset(myp, 0, tmpcount* sizeof(char *)); //��һ��������ˣ�������� return -3 �ڴ���ô�ͷ�
	                                          //��������ͷ�

	//1�� p �� pTmp ��ʼ��
	p = buf1;
	pTmp = buf1;
	tmpcount = 0;
	do
	{
		//2�� ��������������λ�� p���� �γɲ�ֵ ���ַ���
		p = strchr(p, c);
		if(p != NULL)
		{
			if(p-pTmp > 0)
			{
				int len = p -pTmp +1 ;  // +1 Ϊ'\0' �����ڴ�  ����c����
				myp[tmpcount] = (char *)malloc(sizeof(char) * len);
				if(myp[tmpcount] == NULL)
				{
					ret = -3;
				    printf("func spitString() err err:%d  sizeof(char) * len ", ret);
				    goto END;
				}
				strncpy(myp[tmpcount], pTmp, p-pTmp);
				myp[tmpcount][p-pTmp] = '\0';  //�ѵ�һ�����ݱ�� C���Է���ַ���
				tmpcount++;
				//3������ ��p��ptmp �ﵽ��һ�μ���������
				pTmp = p = p +1;
			}
			else
			{
				break;
			}
		}
	}while(*p != '\0');

END:
	if(ret !=0)  //ʧ��
	{  
		/*��һ�ַ�ʽ��
			FreeMem2(myp, *count);
			myp = NULL;
		*/
		/* �ڶ���ʽ */
		FreeMem3(&myp, *count);
	}
	else        //�ɹ�
	{
		*myp3 = myp; 
	}
	
	return ret;
}

void main()
{	
	char *p1 = "abcdef,acccd,eeee,aaaa,e3eeee,ssss,";
	int i = 0;
	int ret = 0;
	char cTem = ',';
	int nCount = 0;

	char **p = NULL;  //�����char buf[10][30]  /*** �ж�����ڴ� ***/

	ret = spitString(p1, cTem, &p, &nCount);
	if(ret != 0)
	{
		printf("func spitString() err  \n");
	}

	for(i=0; i<nCount; i++)
	{
		printf("%s\n", p[i]);
	}

	//�ͷ��ڴ�
	for(i=0; i<nCount; i++)
	{
		free(p[i]);
		p[i] = NULL;
	}
	free(p);
	p = NULL;

	printf("hello...\n");
	system("pause");

	return ;
}
//***************************    ����ָ�� �� ��������   **************************