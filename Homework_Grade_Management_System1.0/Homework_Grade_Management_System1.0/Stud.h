#pragma once
#include "Config.h"
using namespace std;
//updateMode_fitter��ģʽѡ��
enum update_mode {
	ADD = 1,
	REMOVE = 2
};

class Stud 
{
public:
	uint16_t _sid;
	string _sname;
	uint16_t _snumber;//��������uint8����ɵ��vs��cin>>uint8ֻ�ܴ��λ��.

	//����ƥ����,ÿ8bitΪһ����־λ
	uint16_t _mode_fitter;//ʹ��ģ��Ļ������������ʼ��

	int getSid();
	void setSid(uint16_t sid);
	string getSname();
	void setSname(string sname);
	uint16_t getSnumber();
	void setSnumber(uint16_t snumber);

	uint16_t getMode_fitter();
	void setMode_fitter(uint16_t mode_fitter);
	void updateMode_fitter(uint16_t mode_fitter, update_mode mode);

	/********************************************************
	*  @brief    :  ������û�����Ĳ�ѯ��Ϣ,���Ϊһ������
	*  @param    :
	*  @see      :  StudManager::mode_select
	*  @note     :  
	*  @return   :  Stud��ѯ����

	*  @author   :  HZK  2019/06/03 11:03
	********************************************************/
	static Stud getMatchPattern_by_user();
	
	bool operator==(const Stud &stud);

	/********************************************************
	*  @brief    :  ����ƥ��λ����һ������Ա�
	*  @param    :  StudҪ���ⲿ�Ƚϵ�
	*  @see      :  operator==
	*  @note     :  
	*  @return   :  �ɹ�����1,ʧ�ܷ���0

	*  @author   :  HZK  2019/06/02 16:39
	********************************************************/
	bool equal(const Stud & stud);

	/********************************************************
	*  @brief    :  ��ʾƥ���������ݱ�
	*  @param    :
	*  @see      :  getMatchPattern_by_user
	*  @note     :  
	*  @return   :  void

	*  @author   :  HZK  2019/06/03 10:58
	********************************************************/
	void show_table();

	/********************************************************
	*  @brief    :  ���cin�����Ƿ�������ƥ��
	*  @param    :  istream & _cin ��׼������
	*  @param    :  string error_range ��������
	*  @see      :  &operator>>
	*  @note     :  ��̬����
	*  @return   :  true/false

	*  @author   :  HZK  2019/06/03 10:54
	********************************************************/
	static bool cin_check(istream & _cin,string error_range);
	
	friend ostream& operator<<(ostream& _cout, Stud & _stud);

	friend istream& operator>>(istream& _cin, Stud & _stud);


	//SQLIST_STU InitSqList();
	//void DestorySqLIst(SQLIST_STU head);
	//unsigned int SqListCount(const SQLIST_STU head);
	//pointer Get(SQLIST_STU head, int i);
	//int Add(SQLIST_STU head, Stu e, int i);
	//int Delete(SQLIST_STU head, int i);
	//int Destory(SQLIST_STU head);
	//int Traverse(const SQLIST_STU head);
	//int Delete_Lowest_Highest(sqlist_stu head, int lowest, int highest);
	//pointer Search(const sqlist_stu head, int temp, char * temp_3);

};

