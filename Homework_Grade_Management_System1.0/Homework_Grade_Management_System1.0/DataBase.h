#pragma once
#include "Config.h"
#include "Exception_Iterator.h"

template <typename T>
/* �ṹ������ */
class TPList {
protected:
	struct Node {	
		T val;
		Node *next;
		Node *prev;
		//Tû��Ҫָ��
		Node(T va = { 0 }, Node *pre = nullptr, Node *ne = nullptr) : val(va), prev(pre), next(ne) {}
	};

public:
	/*------�ڲ���������-----*/
	class const_iterator {
	public:
		/*------���캯��-----*/
		const_iterator() : cur(nullptr) {}
		//Node *pҲ��, ����Ҫд��const Node *p; �������ֵײ�const����������
		///�޸�ǰ
		//node��TPList�ķ�װ��Ա,����public
		//const_iterator(Node * const p) : cur(p) {}  
	private:
		const_iterator(Node * const p) : cur(p) {}

	protected:
		//ע�⣡��ȻǶ���಻�ܷ����ⲿ��
		friend class TPList<T>; //��ԪTPList,���ڵ���������
		Node *cur;
		const TPList<T> *theList;		//��¼ָ��������ָ�룬������ʶ��
		const_iterator(const TPList<T>* list, Node * const p) : cur(p), theList(list) {}

		/*------���캯��-----*/


		const T &operator*() const
		{
			return cur->val;
		}
		//ע��ǰ��++��������
		const_iterator &operator++()
		{
			cur = cur->next;
			return *this;
		}

		//ע��ǰ��--��������
		const_iterator &operator--()
		{
			cur = cur->prev;
			return *this;
		}

		/*------���������-----*/

		//����++���ɷ�������
		const_iterator operator++(int)
		{
			const_iterator old(theList, this->cur);
			//����ǰ��++
			++(*this);
			return old;
		}


		//����--���ɷ�������
		const_iterator operator--(int)
		{
			const_iterator old(theList, this->cur);
			//����ǰ��++
			--(*this);
			return old;
		}

		bool operator==(const const_iterator &iter) const
		{
			return cur == iter.cur;
		}
		bool operator!=(const const_iterator &iter) const
		{
			//����operator==
			return !(*this == iter);
		}

		/*------���������-----*/

		//��Ч�Լ���
		void AssertValidity() const
		{
			if (theList == nullptr || cur == nullptr ||
				cur->next == nullptr || cur->prev == nullptr)
			{
				throw IteratorMisMatchException("The iterator is invalid!");
			}
		}

	private:
		void AssertRange() const {
			if (this->cur == nullptr) {
				throw IteratorMisMatchException("Iterator went out of the range!");
			}
		}
	};
public:
	//�ڲ���
	class iterator : public const_iterator {
		friend class TPList<T>;

		iterator() : cur(nullptr) {};
	private:
		iterator(Node * p) : cur(p) {}

	protected:
		Node *cur;
		//ע�⣡��ȻǶ���಻�ܷ����ⲿ��
		friend class TPList<T>; //��ԪTPList,���ڵ���������
		const TPList<T> *theList;		//��¼ָ��������ָ�룬������ʶ��
		iterator(const TPList<T>* list, Node * p) : cur(p), theList(list) {}

		/*------���������-----*/
		T &operator*()
		{
			return cur->val;
		}
		//ע��
		const T &operator*() const
		{
			return const_iterator::operator*();
		}
		//��д++
		//ǰ��++��������
		iterator &operator++()
		{
			this->cur = this->cur->next;
			this->AssertRange();
			return *this;
		}

		//��д--
		//ǰ��--��������
		iterator &operator--()
		{
			this->cur = this->cur->prev;
			this->AssertRange();
			return *this;
		}

		//��Ч�Լ���
		void AssertValidity() const
		{
			if (theList == nullptr || cur == nullptr ||
				cur->next == nullptr || cur->prev == nullptr)
			{
				throw IteratorMisMatchException("The iterator is invalid!");
			}
		}

	private:
		void AssertRange() const {
			if (this->cur == nullptr) {
				throw IteratorMisMatchException("Iterator went out of the range!");
			}
		}
	};

	/*-------------TPList�����������������-------------*/
public:
	TPList() { Init(); }
	//ע�Ȿ������ʵ�ּ���
	TPList(const TPList &list) {
		Init();
		operator=(list);
	}
	//ע�ⷵ��ֵ
	/*------���������-----*/

	const TPList &operator=(const TPList &list) {
		if (this == &list)
		{
			return *this;
		}
		Clear();
		for (const_iterator it = list.begin(); it != list.end(); ++it)
		{
			Push_back(*it);
		}
		return *this;
	}
	~TPList() {
		Clear();
		delete head;
		delete tail;
	}
private:
	void Init() {
		size = 0;
		head = new Node;
		tail = new Node;
		tail->prev = head;
		head->next = tail;
	}
	Node *head;
	Node *tail;
	size_t size;

public:
	/*-------------�������ӿ�-------------*/
	/*-------------���ܺ���-------------*/
	void Clear() {
		while (!IsEmpty()) {
			Pop_back();
		}
	}
	iterator Insert(const iterator &iter, const T &val) {
		//���������Ƿ���Ч����Ϊ��end()ǰ����������ģ������ų����������
		if (iter != end()) {
			iter.AssertValidity();
		}
		//����Ƿ��Ǳ������ϵĵ�����
		if (iter.theList != this) {
			throw IteratorMisMatchException("Iterator dose not refer to this list");
		}
		//////////////////////////////////////////////////////
		Node *p = iter.cur;
		++size;

		return iterator(this, p->prev = p->prev->next = new Node(val, p->prev, p));
	}
	iterator Erase(const iterator &iter) {
		iter.AssertValidity();
		if (iter.theList != this)
		{
			throw IteratorMisMatchException("Iterator dose not refer to this list");
		}
		//////////////////////////////////////////////////////
		Node *p = iter.cur;
		//erase�ķ���Լ��
		iterator save(this, p->next);

		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		--size;

		return save;
	}

	//Erase(--end());
	iterator Erase(const iterator &beg, const iterator &end) {
		beg.AssertValidity();
		if (end != this->end()) {
			end.AssertValidity();
		}

		//����Ƿ�ָ��һ�����Լ��Ƿ�ָ�򱾱�
		if (beg.theList != end.theList) {
			throw IteratorMisMatchException("Beg and end refer to different list!");
		}
		else if (beg.theList != this) {
			throw IteratorMisMatchException("Iterator dose not refer to this list");
		}
		//////////////////////////////////////////////////////
		//��Ҫ++it!
		beg.AssertValidity();
		for (iterator it = beg; it != end; ) {
			it = Erase(it);
		}
		return end;
	}

private:
	//��ջ,���ڸ������ʼ��
	void Push_back(const T &val) {
		Insert(end(), val);
	}
	//��ջ,���ڸ��������
	void Pop_back() {
		Erase(--end());
	}

public:

	/*----���ڸ���������ʼ��----*/
	iterator begin() {
		return iterator{ this, head->next };
	}

	//β���constһ��Ҫд����Ϊ��Ҳ��ǩ��֮һ��д��ȥ����������Ч������
	const_iterator begin() const {
		return const_iterator(this, head->next);
	}

	iterator end() {
		return iterator(this, tail);
	}
	const_iterator end() const {
		return const_iterator(this, tail);
	}
	/*------���������-----*/



public:
	/*-------------���ܺ���-------------*/
	void Print() {
		Node *p = head->next;
		cout << "[" << p->val;
		p = p->next;
		while (p != tail) {
			cout << ", " << p->val;
			p = p->next;
		}
		cout << "]" << endl;
	}


	bool IsEmpty() const {
		return size == 0;
	}
	size_t Size() const {
		return size;
	}
	T & front() {
		return *begin();
	}
	const T & front() const {
		return *begin();
	}
	T & back() {
		return *--end();
	}
	const T & back() const {
		return *--end();
	}

};

