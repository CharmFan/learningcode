#ifndef __CFG_OP_H__
#define __CFG_OP_H__

//�����C++���������밴��c���ԵĹ淶���ø�.h�ļ�
#ifdef  __cplusplus
extern "C" {
#endif

//��ȡ������
int WriteCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char *pValue /*in*/, int *ValueLen/*in*/);
//д������
int GetCfgItem(const char *pFileName/*in*/, char *pKey/*in*/, char *pValue/*in out*/, int *pValueLen/*out*/);


#ifdef  __cplusplus
}
#endif

#endif

