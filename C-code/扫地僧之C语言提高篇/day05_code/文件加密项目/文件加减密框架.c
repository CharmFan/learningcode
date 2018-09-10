#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "des.h"

//函数三要素：名称、参数、返回值

/******************************************    加密   *****************************************

	1、加密： 对称加密  和  非对称加密

	2、对称加密：加密的密钥和解密的密钥一样
	   非对称加密：加密的密钥和解密的密钥不一样

	3、加密的三要素：明文 密文 密钥

	4、对称加密：
			场景：运算速度快，适合做大数据加密，强度弱
			eg: des 3des AES196 512
	  非对称加密：
			场景：运算速度慢，强度大，安全
			eg: rsa2014 2048 ECC椭圆曲线(SM系列。。)

	5、散列  哈希 (指纹)

===============  对称加密原理  ===============
	
	比如：将数据切成和密钥的长度一样，（密钥长度可能是8个字节，也可能是16个字节）然后每一个小块分组加密，最后组成了密文。
		  如果数据长度 4096+5 字节（不是八的正数倍），再假定密钥长度是8， 利用“缺几补几原则 ”==》对用5对8求余，得到3，再后面补三个3
								     正好是8的倍数，后面补8个8
	解密的时，获取最后一位看数据是几

*******************************************    加密   *****************************************/
int FileSymEnc(const char *pfile1, const char *pfile2)
{
	 int ret  = 0;
	FILE  *fp1 = NULL, *fp2 = NULL;
	unsigned char plain[4096];  //明文
	int plainlen = 0;   //明文长度
	int plainlen2 = 0;

	unsigned char cryptbuf[4096];  //密文
	int crpytlen = 0;  //密文长度
	int tmplen = 0;   //写密文的成功的次数

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
		//对于小文件
		if (feof(fp1))  //读完数据以后，判断是否文件结束
		{
			break;
		}

		//加密==4k文件
		//此时不用padding，所以调用 DesEnc_raw
		ret = DesEnc_raw(plain, plainlen, cryptbuf, &crpytlen);
		//ret =  DesEnc(plain, plainlen, cryptbuf, &crpytlen);
		if (ret != 0)
		{
			printf("func DesEnc() err \n");
			goto End;
		}

		//对于大文件  大于4096，先写4096的文件
		tmplen = fwrite(cryptbuf, 1, crpytlen, fp2);
		if (tmplen != crpytlen)
		{
			ret = -3;
			printf("写大于等于4k文件密文失败，请检查是否磁盘已满\n");
			goto End;
		}
	}

	//加密小于4k文件
	ret =  DesEnc(plain, plainlen, cryptbuf, &crpytlen);
	if (ret != 0)
	{
		printf("func DesEnc() err \n");
		goto End;
	}

	//对于小文件
	tmplen = fwrite(cryptbuf, 1, crpytlen, fp2);
	if (tmplen != crpytlen)
	{
		ret = -3;
		printf("写小于4k文件密文失败，请检查是否磁盘已满\n");
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
	unsigned char plain[4096];  //明文
	int plainlen = 0;   //明文长度
	int plainlen2 = 0;

	unsigned char cryptbuf[4096];  //密文
	int crpytlen = 0;  //密文长度
	int tmplen = 0;   //写密文的成功的次数

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
		//对于小文件
		if (feof(fp1))  //读完数据以后，判断是否文件结束
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

		//对于大文件  大于4096，先写4096的文件
		tmplen = fwrite(plain, 1, plainlen, fp2);
		if (tmplen != plainlen)
		{
			ret = -3;
			printf("解密写文件失败，请检查是否磁盘已满\n");
			goto End;
		}
	}

	//加密小于4k文件
	ret =  DesDec(cryptbuf, crpytlen, plain, &plainlen);
	if (ret != 0)
	{
		printf("func DesDec() err \n");
		goto End;
	}

	//对于小文件
	tmplen = fwrite(plain, 1, plainlen, fp2);
	if (tmplen != plainlen)
	{
		ret = -3;
		printf("解密时，写小余明文写失败，请检查是否磁盘已满\n");
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


//加密测试
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