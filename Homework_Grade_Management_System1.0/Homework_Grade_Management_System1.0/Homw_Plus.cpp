#include "Homw_Plus.h"

Homw_Plus::Homw_Plus(){}

Homw_Plus::~Homw_Plus(){}


int Homw_Plus::Traverse(const SQLIST_DATA head)
{
	int i = 0;
	pointer_data p;
	p = head->next;

	while (p != NULL)
	{
		cout << i << endl;
		cout << "sname:" << p->elem.hname << endl;
		cout << "sumber:" << p->elem.hnumber << endl;
		i++;
		p = p->next;
	}
	cout << "����" << i << endl;
	return OK;



}


/*��������������Ԫ�� */
int Homw_Plus::Delete_Lowest_Highest(SQLIST_DATA head, int lowest, int highest)//�����ض�����
{
	int i = 0;
	pointer_data p = NULL;
	p = head->next;
	if (p == NULL) return ERROR;
	while (p != NULL)
	{
		if (p->elem.hnumber >= lowest && p->elem.hnumber <= highest)
		{
			Delete(head, i);
		}
		else  p = p->next;
		i++;
	}
	return OK;
}

/*������ɾ������Ԫ�� */
pointer_data Homw_Plus::Search(const SQLIST_DATA head, int temp, char* temp_3)//�����ض�����
{
	int i = 0, count = 0;
	pointer_data p = NULL;
	p = head->next;

	while (p != NULL)
	{
		if (p->elem.hnumber == temp)///s.score
		{
			cout << "���:" << i << endl;
			cout << "sname:" << p->elem.hname << endl;
			cout << "sumber:" << p->elem.hnumber << endl;
			count++;
			break;
		}
		i++;
		p = p->next;
	}
	return p;
}



