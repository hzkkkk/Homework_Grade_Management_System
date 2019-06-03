#pragma once
#include "Config.h"
using namespace std;
//updateMode_fitter的模式选择
enum update_mode {
	ADD = 1,
	REMOVE = 2
};

class Stud 
{
public:
	uint16_t _sid;
	string _sname;
	uint16_t _snumber;//本来想用uint8但是傻逼vs的cin>>uint8只能存个位数.

	//公共匹配器,每8bit为一个标志位
	uint16_t _mode_fitter;//使用模板的话不能在这里初始化

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
	*  @brief    :  保存从用户输入的查询信息,存放为一个对象
	*  @param    :
	*  @see      :  StudManager::mode_select
	*  @note     :  
	*  @return   :  Stud查询对象

	*  @author   :  HZK  2019/06/03 11:03
	********************************************************/
	static Stud getMatchPattern_by_user();
	
	bool operator==(const Stud &stud);

	/********************************************************
	*  @brief    :  根据匹配位与另一个对象对比
	*  @param    :  Stud要跟外部比较的
	*  @see      :  operator==
	*  @note     :  
	*  @return   :  成功返回1,失败返回0

	*  @author   :  HZK  2019/06/02 16:39
	********************************************************/
	bool equal(const Stud & stud);

	/********************************************************
	*  @brief    :  显示匹配器的数据表
	*  @param    :
	*  @see      :  getMatchPattern_by_user
	*  @note     :  
	*  @return   :  void

	*  @author   :  HZK  2019/06/03 10:58
	********************************************************/
	void show_table();

	/********************************************************
	*  @brief    :  检查cin数据是否与类型匹配
	*  @param    :  istream & _cin 标准输入流
	*  @param    :  string error_range 错误类型
	*  @see      :  &operator>>
	*  @note     :  静态方法
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

