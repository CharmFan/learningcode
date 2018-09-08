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
	// 0 û��copy��buf��
	b[i] = '\0';  

	printf("a:%s \n", a);
	printf("b:%s \n", b);   //��ӡ��ʱ��������\0�����������û����һ�� b[i] = '\0';��ӡ�����

	system("pause");
	return;
}


/**********************    ���䰸��   �ú����  start  ****************************/
//********************************************************************************
//�ַ���copy������������

//�ַ���copy����
void copy_str21(char *from, char *to)
{
	for( ; *from != '\0'; from++,to++)
	{
		*to = *from;
	}
	*to = '\0';

	return;
}

//��ʵ, * �� ++  ���У�++���ȼ���,
//���� *to++ = *from++;
//��ʱ,++�Ǻ�׺,��ͬ�� ������*to =*from; ������to++; from++;

void copy_str22(char *from, char *to)
{
	for( ; *from != '\0'; )
	{
		*to++ = *from++;
	}
	*to = '\0';

	return;
}

//�����ֹ����
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
	//while(*to++ = *from++);  //Ҳ��������д
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
//**********************************  ��ѵ  ********************************
//��Ҫ�����βε�ֵ��Ҫ����һ��������ָ����������βθ��ӹ���
int copy_str27_good(char *from,char *to)
{
	char *tmpfrom = from;  //Ϊ�˲����׸ı�ָ������� from toָ��
	char *tmpfo = to;
	if(from == NULL || to == NULL)
	{
		return -1;
	}
	while(*to++ = *from++)
	{
		;
	}
	//printf("from :%s\n", from);  //��ʱû������!!!
}

//�˺��������Ⱑ��������������������������������������������������������������������
void copy_str28(char *from,char *to)
{
	while(*to++ = *from++)
	{
		;
	}                             /*****************   ��ѵ     ********************/
	printf("from :%s\n", from);  //��ʱ��������Ĺ��� ͨ����������Ѿ��޸���from��ָ��
}
//**********************************  ��ѵ  ********************************

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
//		//������
//		char *myto = NULL;  //Ҫ�����ڴ�
//		copy_str25(from, myto);
//	}

	{
		char *myto = NULL;  //Ҫ�����ڴ�

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

/**********************    ���䰸��   �ú����   end  ****************************/
//********************************************************************************