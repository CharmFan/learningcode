/************************************  设计理念  *********************************
	
	 重要的设计理念：
		接口要求紧， 模块要求松

		输入 输出 是指在什么地方分配内存 

*************************************  设计理念  *********************************/

	//1、分清楚功能
	//2、分析出功能的输入和输出
	//3、兑现代码

// 1、写配置文件
    //参数 ： 向什么地方写， 写key, 写value
    //int WriteCfgItem(FILE *fp/*in*/, const char *key/*in*/, const char *value/*in*/); 不合理
    int WriteIniCfg(const char *pfile/*in*/, const char *key/*in*/, char *value/*in*/);

// 2、读该配置文件
	int ReadIniCfg(const char *filename/*in*/, const char *key/*in*/, char *value/*in*/);   //主调函数分配内存

// 3、修改该配置文件
	int ModifyIniCfg(const char *pfile/*in*/, const char *key/*in*/, char *value/*in*/);



	//1、分清楚功能
	//2、分析出功能的输入和输出
	//3、兑现代码

	//写文件   
	int WriteCfgItem(const char *filename/*in*/, const char *key/*in*/, const char *value/*in*/);
	
	//这一个设计不好的接口
	//    当上层使用这个函数，由于传参是文件句柄，要上层打开文件以后，	
	//    才能写配置文件（这个工作原本是下层的事情）
	//	  int WriteCfgItem(FILE *fp/*in*/, const char *key/*in*/, const char *value/*in*/);

	//修改配置文件  有一个前提，调用者需要提前知道“mykeys = mykey3333333”已经存在了
	int ModifyCfgItem(const char *filename/*in*/, const char *key/*in*/, const char *value/*in*/);

    //读配置文件
	int GetCfgItem(const char *filename/*in*/, const char *key/*in*/, char *value/*in*/);   //主调函数分配内存
	int GetCfgItem2(const char *filename/*in*/, const char *key/*in*/, char **value/*out*/); //被调用函数里边分配内存
