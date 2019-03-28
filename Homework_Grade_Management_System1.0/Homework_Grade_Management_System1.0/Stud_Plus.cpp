#include "Stud_Plus.h"

Stud_Plus::Stud_Plus(){}
Stud_Plus::~Stud_Plus(){}

int Stud_Plus::Traverse(const SQLIST_STU head)
{
	int i = 0;
	pointer p;
	p = head->next;

	while (p != NULL)
	{
		cout << i << endl;
		cout << "sname:" << p->elem.sname << endl;
		cout << "sumber:" << p->elem.snumber << endl;
		i++;
		p = p->next;
	}
	cout << "表长：" << i << endl;
	return OK;



}


/*按条件查找链表元素 */
int Stud_Plus::Delete_Lowest_Highest(sqlist_stu head, int lowest, int highest)//根据特定查找
{
	int i = 0;
	pointer p = NULL;
	p = head->next;
	if (p == NULL) return ERROR;
	while (p != NULL)
	{
		if (p->elem.snumber >= lowest && p->elem.snumber <= highest)
		{
			Delete(head, i);
		}
		else  p = p->next;
		i++;
	}
	return OK;
}

/*按条件删除链表元素 */
pointer Stud_Plus::Search(const sqlist_stu head, int temp, char* temp_3)//根据特定查找
{
	int i = 0, count = 0;
	pointer p = NULL;
	p = head->next;

	while (p != NULL)
	{
		if (p->elem.snumber == temp)///s.score
		{
			cout << "序号:" << i << endl;
			cout << "sname:" << p->elem.sname << endl;
			cout << "sumber:" << p->elem.snumber << endl;
			count++;
			break;
		}
		i++;
		p = p->next;
	}
	return p;
}

