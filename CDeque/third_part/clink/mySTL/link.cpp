#include<iostream>
#include<assert.h>
#include <string.h>
#include"link.h"

using namespace std;
//节点类构造函数*
LinkNode::LinkNode(void* pData)
{
	_pdata = pData;
	_next = NULL;
	_prev=NULL;
}

LinkNode::~LinkNode()
{
	_pdata = NULL;
}

//链表类*
CDeque::CDeque()         //构造函数   参数列表多用
: _head(NULL)
, _tail(NULL)
, m_nLength(0)
{}

CDeque::CDeque(const CDeque& s)          //拷贝构造链表
: _head(NULL)
, _tail(NULL)
, m_nLength(0)
{
	if (s._head == NULL)
	{
		return;
	}
	LinkNode* tmp = s._head;
	while (tmp)
	{
		push_back(tmp->_pdata);
		m_nLength++;
		tmp = tmp->_next;
	}
}

CDeque& CDeque::operator=(CDeque &s)     //赋值运算符的重载再优化(推荐写法)
{
	//todo3 自己实现
	//1、首先清空列表 再给列表赋值

	clear();
	if (s._head == NULL)
	{
		return *this;
	}
	LinkNode* tmp = s._head;

	while (tmp)
	{
		push_back(tmp->_pdata);
		tmp = tmp->_next;
	}

	return *this;
}
CDeque::~CDeque()    //析构
{
	clear();
}

//打印链表*
void CDeque::PrintSList()
{
	//头结点为空时，无需打印链表
	if (_head == NULL)
	{
		cout << "This SList is Empty !" << endl;
		return;
	}
	else
	{
		LinkNode* tmp = _head;
		while (tmp)
		{
			cout << *(int*)tmp->_pdata << "-->";

			tmp = tmp->_next;
		}
		cout << "NULL" << endl;
	}
}

void CDeque::push_back(void* pData)    //在尾部插入一个节点*
{
	//如果链表为空，插入节点后只有一个节点，此时_head=_tail
	if (_head == NULL)
	{
		_head = new LinkNode(pData);
		_tail = _head;
		m_nLength++;
	}
	else
	{
		_tail->_next = new LinkNode(pData); //尾部新建节点
		_tail->_next->_prev = _tail;      //新节点前指针指向尾部节点
		_tail = _tail->_next;				//将新节点设置为尾部节点
		m_nLength++;
	}
}

void CDeque::clear()         //链表置空*
{
	LinkNode* begin = _head;
	while (begin != _tail)
	{
		_head = _head->_next;  //将下一个变成头
		delete begin;			//释放旧的头
		begin = _head;			//在将头指针给 begin
	}
	_head = NULL;
	_tail = NULL;
	m_nLength = 0;
}

void CDeque::pop_back()    //尾删
{
	if (_head == NULL)
	{
		cout << "This SList is empty !" << endl;
	}
	else if (_head == _tail)
	{
		delete _head;
		_head = NULL;
		_tail = NULL;
		m_nLength--;
	}
	else
	{
		//优化删除尾指针（重新实现）
		LinkNode* tmp = _tail;		//
		_tail = _tail->_prev;		//1、重新指定尾节点
		_tail->_next = NULL;		//2、新尾节点的下一个置为空
		m_nLength--;
		delete tmp;					//3、删除旧的尾节点

	}
}

void CDeque::push_front(void* pData)  //头插*
{
	if (_head == NULL)
	{
		push_back(pData);
		m_nLength++;
	}
	else
	{
		LinkNode* tmp = _head;
		_head = new LinkNode(pData);
		_head->_next = tmp;
		tmp->_prev = _head;
		m_nLength++;
	}
}

void CDeque::pop_front()    //删除首节点
{
	if (_head == NULL)
	{
		cout << "This SList is empty !" << endl;
		return;
	}
	LinkNode* tmp = _head;
	_head = _head->_next;
	_head->_prev = NULL;
	m_nLength--;
	delete tmp;
}

int CDeque::insert(unsigned int nIndex, void *pData)   //*
{
	if (nIndex > size())
	{
		return -1;
	}
	int i = 1;

	LinkNode* tmp1 = _head;
	for (; tmp1 != NULL; tmp1 = tmp1->_next, i++)
	{
		if (i == nIndex)
		{
			LinkNode* tmp = new LinkNode(pData);
			tmp->_next = tmp1->_next;		// 1、旧节点所指地址赋值给新节点所指
			tmp1->_next = tmp;				// 2、旧节点指向新节点
			tmp->_next->_prev = tmp;		//3、下一节点前一个指向新节点
			tmp->_prev = tmp1;				//4、新节点指向旧节点
			m_nLength++;
			return 0;
		}
	}
	return -1;
}

unsigned int CDeque::size()const  //计算链表节点的数目 
{
	//todo2 优化size
	if (_head == NULL)
	{
		return 0;
	}
	else
	{
		return m_nLength;
	}
}

void CDeque::erase(unsigned int nIndex)      //查找某节点并删除
{	
	if (_head == NULL)
	{
		cout << "This SList is empty !" << endl;
	}
	else
	{
		n_erase(nIndex, 1);
	}
}

void  CDeque::n_erase(unsigned int nFirst, unsigned int nSize)
{
	//todo1 优化n_erase， 越界问题处理
	if (nFirst + nSize > size() || _head == NULL)
	{
		cout << "Crossing the line or This SList is empty !" << endl;
		return ;
	}
	int i=0,j=0;
	LinkNode* tmp = _head;
	while (tmp)
	{
		if (nFirst==i)
		{
			for (j = 0; j < nSize; j++)
			{
				tmp->_prev->_next = tmp->_next;
				tmp->_next->_prev = tmp->_prev;
				LinkNode* tmp1 = tmp;
				tmp = tmp->_next;
				delete tmp1;
			}	
			break;
		}
		i++;
		tmp = tmp->_next;
	}
	cout << endl;
}

bool  CDeque::empty()const
{
	if (_head == NULL)
	{
		return 1;
	}
	return 0;
}
void* CDeque::at(unsigned int pos)
{
	if (pos > size() || _head == NULL)
	{
		return nullptr;
	}

	int count = 0;
	LinkNode* cur = _head;
	while (cur != _tail)
	{
		if (count == pos)
		{
			return cur->_pdata;
		}
		count++;
		cur = cur->_next;
	}
	return nullptr;
}