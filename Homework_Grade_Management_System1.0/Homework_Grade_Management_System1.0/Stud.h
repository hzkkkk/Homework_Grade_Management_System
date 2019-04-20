#pragma once
#include "Config.h"
class Stud 
{
public:
	Stud();
	~Stud();
	int sname;
	uint16_t _snumber;
	unsigned char _sname[20];


	uint16_t printSnumber();
	void setSnumber(uint16_t snumber);
	
	unsigned char* getSname();
	void setSname(unsigned char* sname);



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

