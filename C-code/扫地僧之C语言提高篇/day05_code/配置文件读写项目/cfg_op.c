#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cfg_op.h"

#define MaxLine 2048

//获取配置项
int GetCfgItem(const char *pFileName/*in*/, char *pKey/*in*/, char *pValue/*in out*/, int *pValueLen/*out*/)
{
	FILE *fp = NULL;
	int ret = 0;

	char lineBuf[MaxLine];
	char *pTmp = NULL;
	char *pBegin = NULL;
	char *pEnd = NULL;

	fp = fopen(pFileName, "r");
	if (fp == NULL)
	{
		ret = -1;
		return ret;
	}

	while (!feof(fp))
	{
		//_Check_return_opt_ _CRTIMP 
		//char * __cdecl fgets(_Out_writes_z_(_MaxCount) char * _Buf, _In_ int _MaxCount, _Inout_ FILE * _File);
		fgets(lineBuf, MaxLine, fp);

		pTmp = strchr(lineBuf, '=');
		if (pTmp == NULL) //没有=号
		{
			continue;
		}

		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL) //判断所在行是不是有key
		{
			continue;
		}
		pTmp = pTmp + strlen(pKey); //mykey1 = myvalude111  ===> “  = myvalude111”


		pTmp = strchr(pTmp, '=');
		if (pTmp == NULL) //没有=号
		{
			continue;
		}
		pTmp = pTmp + 1;

	  //获取valude起点
		while(1)
		{
			if (*pTmp == ' ')
			{
				pTmp ++;
			}
			else
			{
				pBegin = pTmp;
				if (*pBegin == '\n')
				{
					//没有配置value
					printf("配置项：%s 没有配置value \n", pKey);
					goto End;
				}
				break;
			}
		}

		//获取valude结束点
		while(1)
		{
			if (*pTmp == ' ' || *pTmp == '\n')
			{
				break;
			}
			else
			{
				pTmp++;
			}
		}
		pEnd = pTmp;

		//赋值
		*pValueLen = pEnd-pBegin;
		memcpy(pValue, pBegin, pEnd-pBegin);
	}

End:
	if (fp != NULL)
	{
		fclose(fp);
	}

	return ret;
}

//写配置项
/*
	流程：
		循环读每一行，检查key配置项是否存在  若存在修改对于的value值
		若不存在，在文件末尾  添加“key = value”
	难点：
		如何修改文件流中的值
*/
int WriteCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char *pValue /*in*/, int *ValueLen/*in*/)
{
	int rv = 0, iTag = 0, length = 0;
	FILE *fp = NULL;
	char lineBuf[MaxLine];
	char *pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
	char filebuf[1024*8] = {0};

	if (pFileName==NULL || pKey==NULL || pValue==NULL)
	{
		rv = -1;
		printf("func  WriteCfgItem() err \n");
		goto End;
	}

	fp = fopen(pFileName, "r+");  //读写方式
	if (fp == NULL)
	{
		rv = -2;
		printf("fopen() err \n");
	}

	if (fp == NULL)
	{
		fp = fopen(pFileName, "w+t"); //文件不存在，我们就建一个
		if (fp == NULL)
		{
			rv = -3;
			printf("fopen err. \n");
			goto End;
		}
	}

	fseek(fp,0L, SEEK_END); //把文件指针从0位置开始，移动到文件末尾
	//获取文件长度
	length = ftell(fp);

	fseek(fp, 0L, SEEK_SET);

	if (length > 1024*8)
	{
		rv = -3;
		printf("文件长度超过1024*8， nunsupport \n");
		goto End;
	}

	while(1)
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, MaxLine, fp);
		if (pTmp == NULL)
		{
			break;
		}

		//key关键字是否在本行
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL) //key关键字不在本行，copy到file中
		{
			strcat(filebuf, lineBuf);
			continue;
		}
		else //key关键字在本行中，替换旧的行，在copy到file中
		{
			sprintf(lineBuf, "%s = %s\n", pKey, pValue);
			strcat(filebuf, lineBuf);
			//若存在key
			iTag = 1;
		}
	}

	//若key关键字，不存在 追加
	if (iTag == 0)
	{
		fprintf(fp, "%s = %s\n", pKey, pValue);
	}
	else //若key关键字，存在，则重新创建文件
	{
		if (fp != NULL)
		{
			fclose(fp);
			fp = NULL; //避免野指针
		}

		fp = fopen(pFileName, "w+t");
		if(fp == NULL)
		{
			rv = -4;
			printf("fopen() err. \n");
		}
		fputs(filebuf, fp);
	}

End:
	if (fp != NULL)
	{
		fclose(fp);
	}

	return rv;
}  