#pragma once
#pragma once

#include "Config.h"
#include "Exception_Iterator.h"
using namespace std;
/*********************************************************************
 *
 *  Copyright (c) 2019, gcu_hzk
 *  All rights reserved.
 *
 *  @Project  : Homework_Grade_Management_System1.0
 *  @FileName : DataBase.h
 *  @Abstract : 
 *  @Log      : 
 *
 *  @Legacy   : 
 *  @Author   : HZK
 *  @Date     : 2019/04/28 13
 *
 *********************************************************************/
//
template <typename T>
class TPList {
protected:
	struct Node {
		T val;
		Node *next;
		Node *prev;
		Node(T va = { 0 }, Node *pre = nullptr, Node *ne = nullptr) : val(va), prev(pre), next(ne) {}
	};

public:
	/*------内部迭代器类-----*/
	/*------构造函数-----*/
	class const_iterator {
	public:
		const_iterator() : cur(nullptr) {}
		//Node *p也行, 但不要写成const Node *p; 否则会出现底层const不相容问题
	private:
		/*node是TPList的封装成员,不能public*/
		//构造函数
		const_iterator(Node * const p) : cur(p) {}

	protected:
		//注意！不然嵌套类不能访问外部类
		friend class TPList<T>; //友元TPList,用于迭代器访问
		Node *cur;
		const TPList<T> *theList;		//记录指向的链表的指针，用作标识。
		const_iterator(const TPList<T>* list, Node * const p) : cur(p), theList(list) {}

		/*------构造函数-----*/
	public:
		/*------运算符重载-----*/
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

	public:

		/*------运算符重载-----*/
		T &operator*()
		{
			return cur->val;
		}

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

		bool operator==(const iterator &iter) const
		{
// 			cout << cur << endl;
// 			cout << iter.cur << endl;
			return cur == iter.cur;
		}

		bool operator!=(const iterator &iter) const
		{
			//调用operator==
			return !(*this == iter);
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
		iterator save;
		//erase的返回约定,如果p->prev时,会访问到头结点,Insert会出错,头结点是不能修改的
		save = iterator(this, p->next);
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
		Append(val);
		//Insert(end(), val);
	}

	//出栈,用于给链表回收,--end用于移动迭代器
	void Pop_back() {
		Erase(--end());
	}

public:
	/*----用于给迭代器初始化-- --*/
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
		if (head->next != tail) {
			Node *p = head->next;
			cout << "[" << p->val << "]" << endl;
			p = p->next;
			while (p != tail) {
				cout << "[";
				cout << p->val << "]" << endl;
				p = p->next;
			}
		}
		else cout << "没有数据" << endl;
	}

	iterator Append(const T &val) {
		const iterator &iter = end();
		Node *p = iter.cur;
		++size;
		//在p所在位置插入节点
		//p->prev : p的前趋
		//p->prev->next : p的前趋的后趋
		//new Node(val, p->prev, p));
		//@param:  p->prev :头节点
		//@param:  p(第一个有效节点)
		//代码含义:
		/*p->prev->next = new Node(val, p->prev, p)
		(此时的)头节点->next = 新节点
		p->prev = p->prev->next
		将p->prev更新为新节点
		*/
		return iterator(this, p->prev = p->prev->next = new Node(val, p->prev, p));
	}


	vector<iterator> Find(const T &val) {
		vector<iterator> iters;
		iterator search_iter;
		int count = 0;
		for (search_iter = begin(); search_iter != end(); ++search_iter)
		{
			if (*search_iter == val)
			{
				cout << "Successfully found" << endl;
				count++;
				iters.push_back(search_iter);
			}
		}
		if(!iters.size()) 
			cout << "Not found" << endl;
		return iters;
	}


	vector<iterator> Find_iters(const T &val){
		vector<iterator> iters;
		iterator search_iter;
		for (search_iter = begin(); search_iter != end(); ++search_iter)
		{
			if (*search_iter == val)
				iters.push_back(search_iter);
		}	
		return iters;
	}

	//查找单个
	iterator Find_iter(const T &val) {
		iterator iter;
		for (iter = begin(); iter != end(); ++iter)
		{
			if(*iter == val) break;
		}	return iter;
	}

	//
	bool Delete_by_find(const T &val) {
		iterator location = Find_iter(val);
		if (location != nullptr && location != end()) {
			Node *p = location.cur;
			iterator save(this, p->next);
			//erase的返回约定
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			--size;
			return true;
		}
		return false;
	}

	vector<iterator> Edit_by_find(const T &val)
	{
		vector<iterator> results = {0};
		if (IsEmpty())
		{
			printf("表空\n");
			return results;
		}
		else
		{		
			results = Find_iters(val);
			if (results.size() != 0)
			{
				printf("查找结束\n");
			}
			else
			{
				printf("查找失败\n");
			}
			return results;
		}
	}

// 	iterator Edit(const iterator &iter, const T &val) {
// 		//检查迭代器是否有效，因为在end()前插入是允许的，所以排除该特殊情况
// 		iterator &iter = begin();
// /////////////////////////////////////////////////
// 		Node *p = iter.cur;
// 		++size;
// 
// 
// 		return iterator(this, p->prev = p->prev->next = new Node(val, p->prev, p));
// 	}

	bool IsEmpty() const {
		return size == 0;
	}
	size_t Size() const {
		return size;
	}


	//返回开头的值
	T & front() {
		return *begin();
	}
	const T & front() const {
		return *begin();
	}


	//返回节尾的值
	T & back() {
		return *--end();
	}
	const T & back() const {
		return *--end();
	}
};
