/************************************  �������  *********************************
	
	 ��Ҫ��������
		�ӿ�Ҫ����� ģ��Ҫ����

		���� ��� ��ָ��ʲô�ط������ڴ� 

*************************************  �������  *********************************/

	//1�����������
	//2�����������ܵ���������
	//3�����ִ���

// 1��д�����ļ�
    //���� �� ��ʲô�ط�д�� дkey, дvalue
    //int WriteCfgItem(FILE *fp/*in*/, const char *key/*in*/, const char *value/*in*/); ������
    int WriteIniCfg(const char *pfile/*in*/, const char *key/*in*/, char *value/*in*/);

// 2�����������ļ�
	int ReadIniCfg(const char *filename/*in*/, const char *key/*in*/, char *value/*in*/);   //�������������ڴ�

// 3���޸ĸ������ļ�
	int ModifyIniCfg(const char *pfile/*in*/, const char *key/*in*/, char *value/*in*/);



	//1�����������
	//2�����������ܵ���������
	//3�����ִ���

	//д�ļ�   
	int WriteCfgItem(const char *filename/*in*/, const char *key/*in*/, const char *value/*in*/);
	
	//��һ����Ʋ��õĽӿ�
	//    ���ϲ�ʹ��������������ڴ������ļ������Ҫ�ϲ���ļ��Ժ�	
	//    ����д�����ļ����������ԭ�����²�����飩
	//	  int WriteCfgItem(FILE *fp/*in*/, const char *key/*in*/, const char *value/*in*/);

	//�޸������ļ�  ��һ��ǰ�ᣬ��������Ҫ��ǰ֪����mykeys = mykey3333333���Ѿ�������
	int ModifyCfgItem(const char *filename/*in*/, const char *key/*in*/, const char *value/*in*/);

    //�������ļ�
	int GetCfgItem(const char *filename/*in*/, const char *key/*in*/, char *value/*in*/);   //�������������ڴ�
	int GetCfgItem2(const char *filename/*in*/, const char *key/*in*/, char **value/*out*/); //�����ú�����߷����ڴ�
