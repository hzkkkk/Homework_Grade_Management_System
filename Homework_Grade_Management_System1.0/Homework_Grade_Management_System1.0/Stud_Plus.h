#pragma once
#include "Stud.h"
class Stud_Plus :
	public Stud
{
public:
	Stud_Plus();
	~Stud_Plus();
	int Traverse(const SQLIST_STU head) override final;

	int Delete_Lowest_Highest(sqlist_stu head, int lowest, int highest);

	pointer Search(const sqlist_stu head, int temp, char * temp_3);


};

