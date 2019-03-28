#pragma once
#include "Config.h"
class Stud 
{
public:
	int sname;

	Stud();
	~Stud();

	SQLIST_STU InitSqList();

	void DestorySqLIst(SQLIST_STU head);

	unsigned int SqListCount(const SQLIST_STU head);

	pointer Get(SQLIST_STU head, int i);

	int Add(SQLIST_STU head, Stu e, int i);

	int Delete(SQLIST_STU head, int i);

	int Destory(SQLIST_STU head);


	virtual int Traverse(const SQLIST_STU head);

};

