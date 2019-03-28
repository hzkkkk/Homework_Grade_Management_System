#pragma once
#include "Config.h"
class Homw
{
public:
	Homw();
	~Homw();
	SQLIST_DATA InitSqList();
	void DestorySqLIst(SQLIST_DATA head);
	unsigned int SqListCount(const SQLIST_DATA head);
	SQLIST_DATA Get(SQLIST_DATA head, int i);
	int Add(SQLIST_DATA head, Homework e, int i);
	int Delete(SQLIST_DATA head, int i);
	
	int Destory(SQLIST_DATA head);

	virtual int Traverse(const SQLIST_DATA head);
};

