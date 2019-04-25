#pragma once
#include "Config.h"
using namespace std;
class Stud 
{
public:
	int _sid;
	uint16_t _snumber;
	string _sname;

	void setSnumber(uint16_t snumber);
	
	string getSname();
	void setSname(string sname);

	bool operator==(const uint16_t & sid) const;

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
