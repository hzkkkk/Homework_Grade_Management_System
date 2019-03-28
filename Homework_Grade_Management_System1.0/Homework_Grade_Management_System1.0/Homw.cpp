#include "Homw.h"
#include"Config.h"
Homw::Homw(){}

Homw::~Homw(){}


/*
*   �ӿڹ���   *
*              */
/* ��ʼ������ */
SQLIST_DATA Homw::InitSqList()
{
	SQLIST_DATA head;
	head = new node_data;
	head->next = NULL;
	return head;
}

/* ɾ������ */
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

/* ���ؽ�������޷��������� */
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
		cout << "λ�÷Ƿ�" << endl;
		return ERROR;
	}
	s = new node_data;
	s->elem = e;
	s->next = q->next;	//���²������next
	q->next = s;	//���²�����ǰ��
	return OK;
}

int Homw::Delete(SQLIST_DATA head, int i)
{
	pointer_data p = NULL, q = NULL;
	q = Get(head, i - 1);//0
	if (p != NULL || q->next == NULL)
	{
		cout << "λ�÷Ƿ�";
		return ERROR;
	}
	p = q->next;	//��ʱpΪɾ�����,q��ʱ������ɾ�����ǰ��
	q->next = p->next; //����ɾ������next���浽q->next
	delete p;
	return OK;
}

/*�������� */
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
	cout << "����" << i << endl;
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



