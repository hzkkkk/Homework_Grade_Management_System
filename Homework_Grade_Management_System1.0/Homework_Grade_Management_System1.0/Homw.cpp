#include "Homw.h"
#include"Config.h"
Homw::Homw(){}

Homw::~Homw(){}


/*
*   接口功能   *
*              */
/* 初始化链表 */
SQLIST_DATA Homw::InitSqList()
{
	SQLIST_DATA head;
	head = new node_data;
	head->next = NULL;
	return head;
}

/* 删除链表 */
void Homw::DestorySqLIst(SQLIST_DATA head)
{
	pointer_data p, q;
	p = head;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
}

/* 返回结点数（无符号整数） */
unsigned int Homw::SqListCount(const SQLIST_DATA head)
{
	int j = 0;
	pointer_data p;
	p = head->next;
	while (p != NULL)
	{
		j++;
		p = p->next;
	}
	return j;
}

SQLIST_DATA Homw::Get(SQLIST_DATA head, int i)
{
	int j = 0;
	pointer_data p = NULL;
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

int Homw::Add(SQLIST_DATA head, Homework e, int i)
{
	pointer_data q, s;
	q = Get(head, i - 1);
	if (q == NULL)
	{
		cout << "位置非法" << endl;
		return ERROR;
	}
	s = new node_data;
	s->elem = e;
	s->next = q->next;	//更新插入结点的next
	q->next = s;	//更新插入结点前趋
	return OK;
}

int Homw::Delete(SQLIST_DATA head, int i)
{
	pointer_data p = NULL, q = NULL;
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
int Homw::Traverse(const SQLIST_DATA head)
{
	int i = 0;
	pointer_data p;
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

int Homw::Destory(SQLIST_DATA head)
{
	pointer_data p;
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



