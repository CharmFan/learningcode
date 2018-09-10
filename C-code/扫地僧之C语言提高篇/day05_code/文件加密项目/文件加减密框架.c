#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "des.h"

//������Ҫ�أ����ơ�����������ֵ

/******************************************    ����   *****************************************

	1�����ܣ� �ԳƼ���  ��  �ǶԳƼ���

	2���ԳƼ��ܣ����ܵ���Կ�ͽ��ܵ���Կһ��
	   �ǶԳƼ��ܣ����ܵ���Կ�ͽ��ܵ���Կ��һ��

	3�����ܵ���Ҫ�أ����� ���� ��Կ

	4���ԳƼ��ܣ�
			�����������ٶȿ죬�ʺ��������ݼ��ܣ�ǿ����
			eg: des 3des AES196 512
	  �ǶԳƼ��ܣ�
			�����������ٶ�����ǿ�ȴ󣬰�ȫ
			eg: rsa2014 2048 ECC��Բ����(SMϵ�С���)

	5��ɢ��  ��ϣ (ָ��)

===============  �ԳƼ���ԭ��  ===============
	
	���磺�������гɺ���Կ�ĳ���һ��������Կ���ȿ�����8���ֽڣ�Ҳ������16���ֽڣ�Ȼ��ÿһ��С�������ܣ������������ġ�
		  ������ݳ��� 4096+5 �ֽڣ����ǰ˵������������ټٶ���Կ������8�� ���á�ȱ������ԭ�� ��==������5��8���࣬�õ�3���ٺ��油����3
								     ������8�ı��������油8��8
	���ܵ�ʱ����ȡ���һλ�������Ǽ�

*******************************************    ����   *****************************************/
int FileSymEnc(const char *pfile1, const char *pfile2)
{
	 int ret  = 0;
	FILE  *fp1 = NULL, *fp2 = NULL;
	unsigned char plain[4096];  //����
	int plainlen = 0;   //���ĳ���
	int plainlen2 = 0;

	unsigned char cryptbuf[4096];  //����
	int crpytlen = 0;  //���ĳ���
	int tmplen = 0;   //д���ĵĳɹ��Ĵ���

	fp1 = fopen(pfile1, "rb");
	if (fp1 == NULL)
	{
		goto End;
	}

	fp2 = fopen(pfile2, "wb");
	if (fp2 == NULL)
	{
		goto End;
	}

	while (!feof(fp1))
	{
		plainlen = fread(plain, 1, 4096, fp1);
		//����С�ļ�
		if (feof(fp1))  //���������Ժ��ж��Ƿ��ļ�����
		{
			break;
		}

		//����==4k�ļ�
		//��ʱ����padding�����Ե��� DesEnc_raw
		ret = DesEnc_raw(plain, plainlen, cryptbuf, &crpytlen);
		//ret =  DesEnc(plain, plainlen, cryptbuf, &crpytlen);
		if (ret != 0)
		{
			printf("func DesEnc() err \n");
			goto End;
		}

		//���ڴ��ļ�  ����4096����д4096���ļ�
		tmplen = fwrite(cryptbuf, 1, crpytlen, fp2);
		if (tmplen != crpytlen)
		{
			ret = -3;
			printf("д���ڵ���4k�ļ�����ʧ�ܣ������Ƿ��������\n");
			goto End;
		}
	}

	//����С��4k�ļ�
	ret =  DesEnc(plain, plainlen, cryptbuf, &crpytlen);
	if (ret != 0)
	{
		printf("func DesEnc() err \n");
		goto End;
	}

	//����С�ļ�
	tmplen = fwrite(cryptbuf, 1, crpytlen, fp2);
	if (tmplen != crpytlen)
	{
		ret = -3;
		printf("дС��4k�ļ�����ʧ�ܣ������Ƿ��������\n");
		goto End;
	}

End:
	if (fp1 != NULL)
	{
		fclose(fp1);
	}

	if (fp2 != NULL)
	{
		fclose(fp2);
	}

	return ret;
}

int FileSymDec(const char *pfile1, const char *pfile2)
{
	int ret  = 0;
	FILE  *fp1 = NULL, *fp2 = NULL;
	unsigned char plain[4096];  //����
	int plainlen = 0;   //���ĳ���
	int plainlen2 = 0;

	unsigned char cryptbuf[4096];  //����
	int crpytlen = 0;  //���ĳ���
	int tmplen = 0;   //д���ĵĳɹ��Ĵ���

	fp1 = fopen(pfile1, "rb");
	if (fp1 == NULL)
	{
		goto End;
	}

	fp2 = fopen(pfile2, "wb");
	if (fp2 == NULL)
	{
		goto End;
	}

	while (!feof(fp1))
	{
		crpytlen = fread(cryptbuf, 1, 4096, fp1);
		//����С�ļ�
		if (feof(fp1))  //���������Ժ��ж��Ƿ��ļ�����
		{
			break;
		}

		ret = DesDec_raw(cryptbuf, crpytlen, plain, &plainlen);
		//ret =  DesEnc(plain, plainlen, cryptbuf, &crpytlen);
		if (ret != 0)
		{
			printf("func DesDec() err \n");
			goto End;
		}

		//���ڴ��ļ�  ����4096����д4096���ļ�
		tmplen = fwrite(plain, 1, plainlen, fp2);
		if (tmplen != plainlen)
		{
			ret = -3;
			printf("����д�ļ�ʧ�ܣ������Ƿ��������\n");
			goto End;
		}
	}

	//����С��4k�ļ�
	ret =  DesDec(cryptbuf, crpytlen, plain, &plainlen);
	if (ret != 0)
	{
		printf("func DesDec() err \n");
		goto End;
	}

	//����С�ļ�
	tmplen = fwrite(plain, 1, plainlen, fp2);
	if (tmplen != plainlen)
	{
		ret = -3;
		printf("����ʱ��дС������дʧ�ܣ������Ƿ��������\n");
		goto End;
	}

End:
	if (fp1 != NULL)
	{
		fclose(fp1);
	}

	if (fp2 != NULL)
	{
		fclose(fp2);
	}

	return ret;
}


//���ܲ���
void main_enc()
{
	int ret = 0;
	const char *file1 = "d:/2.txt";
	const char *file2 = "d:/2enc.txt";
	
	ret = FileSymEnc(file1, file2);
	if (ret != 0)
	{
		printf("func FileSymEnc() err \n");
		return ret ;
	}

	//system("pause");
	return ;
}

void main_dec()
{
	int ret = 0;
	const char *file1 = "d:/2enc.txt"; 
	const char *file2 = "d:/2dec.txt"; 

	ret = FileSymDec(file1, file2);
	if (ret != 0)
	{
		printf("func FileSymDec() err \n");
		return ret ;
	}

	//system("pause");
	return ;
}


void main()
{
	main_enc();
	main_dec();

	printf("\nhello...\n");
	system("pause");
	return ;
}