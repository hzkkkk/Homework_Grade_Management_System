#pragma once
#include "Config.h"
#include "Exception_Iterator.h"

template <typename T>
/* 结构体链表 */
class TPList {
protected:
	struct Node {	
		T val;
		Node *next;
		Node *prev;
		//T没必要指类
		Node(T va = { 0 }, Node *pre = nullptr, Node *ne = nullptr) : val(va), prev(pre), next(ne) {}
	};

public:
	/*------内部迭代器类-----*/
	class const_iterator {
	public:
		/*------构造函数-----*/
		const_iterator() : cur(nullptr) {}
		//Node *p也行, 但不要写成const Node *p; 否则会出现底层const不相容问题
		///修改前
		//node是TPList的封装成员,不能public
		//const_iterator(Node * const p) : cur(p) {}  
	private:
		const_iterator(Node * const p) : cur(p) {}

	protected:
		//注意！不然嵌套类不能访问外部类
		friend class TPList<T>; //友元TPList,用于迭代器访问
		Node *cur;
		const TPList<T> *theList;		//记录指向的链表的指针，用作标识。
		const_iterator(const TPList<T>* list, Node * const p) : cur(p), theList(list) {}

		/*------构造函数-----*/


		const T &operator*() const
		{
			return cur->val;
		}
		//注意前置++返回引用
		const_iterator &operator++()
		{
			cur = cur->next;
			return *this;
		}

		//注意前置--返回引用
		const_iterator &operator--()
		{
			cur = cur->prev;
			return *this;
		}

		/*------运算符重载-----*/

		//后置++不可返回引用
		const_iterator operator++(int)
		{
			const_iterator old(theList, this->cur);
			//调用前置++
			++(*this);
			return old;
		}


		//后置--不可返回引用
		const_iterator operator--(int)
		{
			const_iterator old(theList, this->cur);
			//调用前置++
			--(*this);
			return old;
		}

		bool operator==(const const_iterator &iter) const
		{
			return cur == iter.cur;
		}
		bool operator!=(const const_iterator &iter) const
		{
			//调用operator==
			return !(*this == iter);
		}

		/*------运算符重载-----*/

		//有效性检验
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
	//内部类
	class iterator : public const_iterator {
		friend class TPList<T>;

		iterator() : cur(nullptr) {};
	private:
		iterator(Node * p) : cur(p) {}

	protected:
		Node *cur;
		//注意！不然嵌套类不能访问外部类
		friend class TPList<T>; //友元TPList,用于迭代器访问
		const TPList<T> *theList;		//记录指向的链表的指针，用作标识。
		iterator(const TPList<T>* list, Node * p) : cur(p), theList(list) {}

		/*------运算符重载-----*/
		T &operator*()
		{
			return cur->val;
		}
		//注意
		const T &operator*() const
		{
			return const_iterator::operator*();
		}
		//重写++
		//前置++返回引用
		iterator &operator++()
		{
			this->cur = this->cur->next;
			this->AssertRange();
			return *this;
		}

		//重写--
		//前置--返回引用
		iterator &operator--()
		{
			this->cur = this->cur->prev;
			this->AssertRange();
			return *this;
		}

		//有效性检验
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

	/*-------------TPList构造器和重载运算符-------------*/
public:
	TPList() { Init(); }
	//注意本函数的实现技巧
	TPList(const TPList &list) {
		Init();
		operator=(list);
	}
	//注意返回值
	/*------运算符重载-----*/

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
	/*-------------链表对外接口-------------*/
	/*-------------功能函数-------------*/
	void Clear() {
		while (!IsEmpty()) {
			Pop_back();
		}
	}
	iterator Insert(const iterator &iter, const T &val) {
		//检查迭代器是否有效，因为在end()前插入是允许的，所以排除该特殊情况
		if (iter != end()) {
			iter.AssertValidity();
		}
		//检查是否是本链表上的迭代器
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
		//erase的返回约定
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

		//检查是否指向一个表，以及是否指向本表
		if (beg.theList != end.theList) {
			throw IteratorMisMatchException("Beg and end refer to different list!");
		}
		else if (beg.theList != this) {
			throw IteratorMisMatchException("Iterator dose not refer to this list");
		}
		//////////////////////////////////////////////////////
		//不要++it!
		beg.AssertValidity();
		for (iterator it = beg; it != end; ) {
			it = Erase(it);
		}
		return end;
	}

private:
	//进栈,用于给链表初始化
	void Push_back(const T &val) {
		Insert(end(), val);
	}
	//出栈,用于给链表回收
	void Pop_back() {
		Erase(--end());
	}

public:

	/*----用于给迭代器初始化----*/
	iterator begin() {
		return iterator{ this, head->next };
	}

	//尾后的const一定要写，因为它也是签名之一，写上去才能视作有效的重载
	const_iterator begin() const {
		return const_iterator(this, head->next);
	}

	iterator end() {
		return iterator(this, tail);
	}
	const_iterator end() const {
		return const_iterator(this, tail);
	}
	/*------运算符重载-----*/



public:
	/*-------------功能函数-------------*/
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

