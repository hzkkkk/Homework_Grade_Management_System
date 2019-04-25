#include "Stud.h"
#include "Config.h"

/*			   *
*   接口功能    *
*              */


void Stud::setSnumber(uint16_t snumber)
{
	_snumber = snumber;
}

string Stud::getSname()
{
	return _sname;
}

void Stud::setSname(string sname)
{
	_sname = sname;
}

bool Stud::operator==(const uint16_t & sid) const
{
	return _sid == sid;
}

ostream &operator<<(ostream & _cout, Stud & _stud)
{
	_cout << setw(6) << left << _stud._sid 
		<< setw(6) << left << _stud._snumber 
		<< setw(6) << left << _stud._sname;
	return _cout;
}

istream &operator>>(istream & _cin, Stud & _stud)
{
	_cin >> _stud._sid >> _stud._snumber >> _stud._sname;
	return _cin;
}

///* 初始化链表 */
//SQLIST_STU Stud::InitSqList()
//{
//	sqlist_stu head;
//	head = new node_stu;
//	head->next = NULL;
//	return head;
//}
//
///* 删除链表 */
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
///* 返回结点数（无符号整数） */
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
//		cout << "位置非法" << endl;
//		return ERROR;
//	}
//	s = new node_stu;
//	s->elem = e;
//	s->next = q->next;	//更新插入结点的next
//	q->next = s;	//更新插入结点前趋
//	return OK;
//}
//
//int Stud::Delete(SQLIST_STU head, int i)
//{
//	pointer p = NULL, q = NULL;
//	q = Get(head, i - 1);//0
//	if (p != NULL || q->next == NULL)
//	{
//		cout << "位置非法";
//		return ERROR;
//	}
//	p = q->next;	//此时p为删除结点,q此时依旧是删除结点前趋
//	q->next = p->next; //保存删除结点的next保存到q->next
//	delete p;
//	return OK;
//}
//
///*遍历链表 */
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
//	cout << "表长：" << i << endl;
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
//	cout << "表长：" << i << endl;
//	return OK;
//
//
//
//}
//
//
///*按条件查找链表元素 */
//int Stud::Delete_Lowest_Highest(sqlist_stu head, int lowest, int highest)//根据特定查找
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
///*按条件删除链表元素 */
//pointer Stud::Search(const sqlist_stu head, int temp, char* temp_3)//根据特定查找
//{
//	int i = 0, count = 0;
//	pointer p = NULL;
//	p = head->next;
//
//	while (p != NULL)
//	{
//		if (p->elem.snumber == temp)///s.score
//		{
//			cout << "序号:" << i << endl;
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