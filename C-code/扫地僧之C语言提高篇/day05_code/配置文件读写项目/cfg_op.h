#ifndef __CFG_OP_H__
#define __CFG_OP_H__

//如果是C++编译器，请按照c语言的规范引用该.h文件
#ifdef  __cplusplus
extern "C" {
#endif

//获取配置项
int WriteCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char *pValue /*in*/, int *ValueLen/*in*/);
//写配置项
int GetCfgItem(const char *pFileName/*in*/, char *pKey/*in*/, char *pValue/*in out*/, int *pValueLen/*out*/);


#ifdef  __cplusplus
}
#endif

#endif

