#ifndef __DES_H__
#define __DES_H__

//如果是C++编译器，请按照c语言的规范引用该.h文件
#ifdef  __cplusplus
extern "C" {
#endif

//用户使用的函数
int DesEnc(
	unsigned char *pInData,
	int			   nInDataLen,
	unsigned char *pOutData,
	int			  *pOutDataLen);

//用户使用函数des解密
int DesDec(
	unsigned char *pInData,
	int			   nInDataLen,
	unsigned char *pOutData,
	int			  *pOutDataLen);
	
#ifdef  __cplusplus
}
#endif

#endif