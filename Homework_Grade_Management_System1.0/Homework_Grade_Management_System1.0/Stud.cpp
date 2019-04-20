#include "Stud.h"
#include "Config.h"

Stud::Stud(){}
Stud::~Stud(){}
/*			   *
*   �ӿڹ���    *
*              */
uint16_t Stud::printSnumber()
{
	return 0;
}

void Stud::setSnumber(uint16_t snumber)
{
	_snumber = snumber;
}

unsigned char* Stud::getSname()
{
	return _sname;
}

void Stud::setSname(unsigned char * sname)
{
	memcpy(_sname,sname,sizeof(sname));
}


///* ��ʼ������ */
//SQLIST_STU Stud::InitSqList()
//{
//	sqlist_stu head;
//	head = new node_stu;
//	head->next = NULL;
//	return head;
//}
//
///* ɾ������ */
//void Stud::DestorySqLIst(SQLIST_STU head)
//{
//	pointer p, q;
//	p = head;
//	while (p != NULL)
//	{
//		q = p->next;
//		delete p;
//		p = q;
//	}
//}
//
///* ���ؽ�������޷��������� */
//unsigned int Stud::SqListCount(const SQLIST_STU head)
//{
//	int j = 0;
//	pointer p;
//	p = head->next;
//	while (p != NULL)
//	{
//		j++;
//		p = p->next;
//	}
//	return j;
//}
//
//pointer Stud::Get(SQLIST_STU head, int i)
//{
//	int j = 0;
//	pointer p = NULL;
//	if (i == 0) return head;
//	if (i < 0) return NULL;
//
//	p = head->next;
//
//	while (p != NULL)
//	{
//		j++;
//		if (j == i) break;
//		p = p->next;
//	}
//	return p;
//}
//
//int Stud::Add(SQLIST_STU head, Stu e, int i)
//{
//	pointer q, s;
//	q = Get(head, i - 1);
//	if (q == NULL)
//	{
//		cout << "λ�÷Ƿ�" << endl;
//		return ERROR;
//	}
//	s = new node_stu;
//	s->elem = e;
//	s->next = q->next;	//���²������next
//	q->next = s;	//���²�����ǰ��
//	return OK;
//}
//
//int Stud::Delete(SQLIST_STU head, int i)
//{
//	pointer p = NULL, q = NULL;
//	q = Get(head, i - 1);//0
//	if (p != NULL || q->next == NULL)
//	{
//		cout << "λ�÷Ƿ�";
//		return ERROR;
//	}
//	p = q->next;	//��ʱpΪɾ�����,q��ʱ������ɾ�����ǰ��
//	q->next = p->next; //����ɾ������next���浽q->next
//	delete p;
//	return OK;
//}
//
///*�������� */
//int Stud::Traverse(const SQLIST_STU head)
//{
//	int i = 0;
//	pointer p;
//	p = head->next;
//
//	while (p != NULL)
//	{
//		cout << i << endl;
//		//TODO:Add printf() format
//		i++;
//		p = p->next;
//	}
//	cout << "����" << i << endl;
//	return OK;
//}
//
//int Stud::Destory(SQLIST_STU head)
//{
//	pointer p;
//	if (head == NULL)
//		return ERROR;
//	while (head)
//	{
//		p = head->next;
//		free(head);
//		head = p;
//	}
//	return OK;
//}
//
//
//
//int Stud::Traverse(const SQLIST_STU head)
//{
//	int i = 0;
//	pointer p;
//	p = head->next;
//
//	while (p != NULL)
//	{
//		cout << i << endl;
//		cout << "sname:" << p->elem.sname << endl;
//		cout << "sumber:" << p->elem.snumber << endl;
//		i++;
//		p = p->next;
//	}
//	cout << "����" << i << endl;
//	return OK;
//
//
//
//}
//
//
///*��������������Ԫ�� */
//int Stud::Delete_Lowest_Highest(sqlist_stu head, int lowest, int highest)//�����ض�����
//{
//	int i = 0;
//	pointer p = NULL;
//	p = head->next;
//	if (p == NULL) return ERROR;
//	while (p != NULL)
//	{
//		if (p->elem.snumber >= lowest && p->elem.snumber <= highest)
//		{
//			Delete(head, i);
//		}
//		else  p = p->next;
//		i++;
//	}
//	return OK;
//}
//
///*������ɾ������Ԫ�� */
//pointer Stud::Search(const sqlist_stu head, int temp, char* temp_3)//�����ض�����
//{
//	int i = 0, count = 0;
//	pointer p = NULL;
//	p = head->next;
//
//	while (p != NULL)
//	{
//		if (p->elem.snumber == temp)///s.score
//		{
//			cout << "���:" << i << endl;
//			cout << "sname:" << p->elem.sname << endl;
//			cout << "sumber:" << p->elem.snumber << endl;
//			count++;
//			break;
//		}
//		i++;
//		p = p->next;
//	}
//	return p;
//}