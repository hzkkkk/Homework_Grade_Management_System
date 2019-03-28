#include "Stud.h"
#include "Config.h"

Stud::Stud(){}

Stud::~Stud(){}

/*
*   接口功能   *
*              */
/* 初始化链表 */
SQLIST_STU Stud::InitSqList()
{
	sqlist_stu head;
	head = new node_stu;
	head->next = NULL;
	return head;
}

/* 删除链表 */
void Stud::DestorySqLIst(SQLIST_STU head)
{
	pointer p, q;
	p = head;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
}

/* 返回结点数（无符号整数） */
unsigned int Stud::SqListCount(const SQLIST_STU head)
{
	int j = 0;
	pointer p;
	p = head->next;
	while (p != NULL)
	{
		j++;
		p = p->next;
	}
	return j;
}

pointer Stud::Get(SQLIST_STU head, int i)
{
	int j = 0;
	pointer p = NULL;
	if (i == 0) return head;
	if (i < 0) return NULL;

	p = head->next;

	while (p != NULL)
	{
		j++;
		if (j == i) break;
		p = p->next;
	}
	return p;
}

int Stud::Add(SQLIST_STU head, Stu e, int i)
{
	pointer q, s;
	q = Get(head, i - 1);
	if (q == NULL)
	{
		cout << "位置非法" << endl;
		return ERROR;
	}
	s = new node_stu;
	s->elem = e;
	s->next = q->next;	//更新插入结点的next
	q->next = s;	//更新插入结点前趋
	return OK;
}

int Stud::Delete(SQLIST_STU head, int i)
{
	pointer p = NULL, q = NULL;
	q = Get(head, i - 1);//0
	if (p != NULL || q->next == NULL)
	{
		cout << "位置非法";
		return ERROR;
	}
	p = q->next;	//此时p为删除结点,q此时依旧是删除结点前趋
	q->next = p->next; //保存删除结点的next保存到q->next
	delete p;
	return OK;
}

/*遍历链表 */
int Stud::Traverse(const SQLIST_STU head)
{
	int i = 0;
	pointer p;
	p = head->next;

	while (p != NULL)
	{
		cout << i << endl;
		//TODO:Add printf() format
		i++;
		p = p->next;
	}
	cout << "表长：" << i << endl;
	return OK;
}

int Stud::Destory(SQLIST_STU head)
{
	pointer p;
	if (head == NULL)
		return ERROR;
	while (head)
	{
		p = head->next;
		free(head);
		head = p;
	}
	return OK;
}




