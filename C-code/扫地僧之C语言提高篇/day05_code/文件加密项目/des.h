#ifndef __DES_H__
#define __DES_H__

//�����C++���������밴��c���ԵĹ淶���ø�.h�ļ�
#ifdef  __cplusplus
extern "C" {
#endif

//�û�ʹ�õĺ���
int DesEnc(
	unsigned char *pInData,
	int			   nInDataLen,
	unsigned char *pOutData,
	int			  *pOutDataLen);

//�û�ʹ�ú���des����
int DesDec(
	unsigned char *pInData,
	int			   nInDataLen,
	unsigned char *pOutData,
	int			  *pOutDataLen);
	
#ifdef  __cplusplus
}
#endif

#endif