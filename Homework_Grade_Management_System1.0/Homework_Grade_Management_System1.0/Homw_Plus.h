#pragma once
#include "Homw.h"
class Homw_Plus :
	public Homw
{
public:
	Homw_Plus();
	~Homw_Plus();
	int Traverse(const SQLIST_DATA head) override final;
	int Delete_Lowest_Highest(SQLIST_DATA head, int lowest, int highest);
	pointer_data Search(const SQLIST_DATA head, int temp, char * temp_3);
};

