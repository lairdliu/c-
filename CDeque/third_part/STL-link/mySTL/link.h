
#ifndef LINKED_DEQUE_H_
#define LINKED_DEQUE_H_

#include "Deque.h"
//#include "LinkNode.h"

#include <iostream>
#include <string>
#include <strstream>
using namespace std;

template<class T>
struct LinkNode
{
	T data;
	LinkNode<T>*link;
	LinkNode(LinkNode<T> *ptr = NULL) { link = ptr; }
	LinkNode(const T&item, LinkNode<T> *ptr = NULL)
	{
		data = item;
		link = ptr;
	}
};
//typedef node LinkNode;

template <class T>
class LinkedDeque : public Deque<T>
{
public:
	LinkedDeque();              //构造函数
	virtual ~LinkedDeque();     //析构函数
public:
	virtual bool getHead(T& x)const;        //读取队头元素，并将该元素的值保存至x
	virtual bool getTail(T& x)const;        //读取队尾元素，并将该元素的值保存至x
	virtual bool EnQueue(const T& x);       //新元素x入队——从队尾入队
	virtual bool EnQueueHead(const T& x);   //新元素x入队——从队头入队
	virtual bool EnQueueTail(const T& x);   //新元素x入队——从队尾入队
	virtual bool DeQueue(T& x);             //队头元素出队，并将该元素的值保存至x
	virtual bool DeQueueHead(T& x);         //队头元素出队，并将该元素的值保存至x
	virtual bool DeQueueTail(T& x);         //队尾元素出队，并将该元素的值保存至x
	virtual bool IsEmpty() const;           //判断队列是否为空
	virtual bool IsFull() const;            //判断队列是否为满
	virtual void MakeEmpty();               //清空队列的内容
	virtual int getSize() const;            //计算队列中元素个数

	int insert(unsigned int nIndex, void *pData);
	void erase(unsigned int nIndex);
	void n_erase(unsigned int nFirst, unsigned int nSize);
	void* at(unsigned int pos);

	/*void push_front(void *pData);
	void push_back(void *pData);
	int insert(unsigned int nIndex, void *pData);
	void erase(unsigned int nIndex);
	void n_erase(unsigned int nFirst, unsigned int nSize);
	void pop_front();
	void pop_back();
	void clear();
	void* at(unsigned int pos);
	bool empty()const;
	unsigned int size()const;*/

public:
	template <class T>
	friend ostream& operator<<(ostream& os, const LinkedDeque<T>& q);   //输出队列元素的重载操作<<
private:
	LinkNode<T> *front; //队头指针，即链头指针
	LinkNode<T> *rear;  //队尾指针，即链尾指针
};

//构造函数
template <class T>
LinkedDeque<T>::LinkedDeque()
: front(NULL), rear(NULL)
{
	cout << "$ 执行构造函数" << endl;
}

//析构函数
template <class T>
LinkedDeque<T>::~LinkedDeque()
{
	cout << "$ 执行析构函数" << endl;
	MakeEmpty();
}

//读取队头元素，并将该元素的值保存至x
template <class T>
bool LinkedDeque<T>::getHead(T& x) const
{
	if (true == IsEmpty())
	{
		return false;
	}
	x = front->data;
	return true;
}

//读取队尾元素，并将该元素的值保存至x
template <class T>
bool LinkedDeque<T>::getTail(T& x) const
{
	if (true == IsEmpty())
	{
		return false;
	}
	x = rear->data;
	return true;
}

//新元素x入队——从队尾入队
template <class T>
bool LinkedDeque<T>::EnQueue(const T& x)
{
	return EnQueueTail(x);
}

//新元素x入队——从队头入队
template <class T>
bool LinkedDeque<T>::EnQueueHead(const T& x)
{
	LinkNode<T> *newNode = new LinkNode<T>(x);
	if (NULL == newNode)
	{
		return false;
	}

	if (NULL == front)
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		newNode->link = front;
		front = newNode;
	}
	return true;
}

//新元素x入队——从队尾入队
template <class T>
bool LinkedDeque<T>::EnQueueTail(const T& x)
{
	LinkNode<T> *newNode = new LinkNode<T>(x);
	if (NULL == newNode)
	{
		return false;
	}

	if (NULL == front)
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->link = newNode;
		rear = rear->link;
	}
	return true;
}

//队头元素出队，并将该元素的值保存至x
template <class T>
bool LinkedDeque<T>::DeQueue(T& x)
{
	return DeQueueHead(x);
}

//队头元素出队，并将该元素的值保存至x
template <class T>
bool LinkedDeque<T>::DeQueueHead(T& x)
{
	if (true == IsEmpty())
	{
		return false;
	}
	LinkNode<T> *curNode = front;
	front = front->link;
	x = curNode->data;
	delete curNode;
	return true;
}

//队尾元素出队，并将该元素的值保存至x
template <class T>
bool LinkedDeque<T>::DeQueueTail(T& x)
{
	if (true == IsEmpty())
	{
		return false;
	}

	x = rear->data;
	LinkNode<T> *curNode = front;
	if (curNode == rear)
	{
		delete rear;
		front = NULL;
		rear = NULL;
		return true;
	}
	while (curNode->link != rear)
	{
		curNode = curNode->link;
	}
	delete rear;
	curNode->link = NULL;
	rear = curNode;
	return true;
}

//判断队列是否为空
template <class T>
bool LinkedDeque<T>::IsEmpty() const
{
	return (NULL == front) ? true : false;
}

//判断队列是否为满
template <class T>
bool LinkedDeque<T>::IsFull() const
{
	return false;
}

//清空队列的内容
template <class T>
void LinkedDeque<T>::MakeEmpty()
{
	LinkNode<T> *curNode = NULL;
	while (NULL != front)           //当链表不为空时，删去链表中所有结点
	{
		curNode = front;            //保存被删结点
		front = curNode->link;      //被删结点的下一个结点成为头结点
		delete curNode;             //从链表上摘下被删结点
	}
}

//计算队列中元素个数
template <class T>
int LinkedDeque<T>::getSize() const
{
	int count = 0;
	LinkNode<T> *curNode = front;
	while (NULL != curNode)
	{
		curNode = curNode->link;
		count++;
	}
	return count;
}

//输出队列元素的重载操作<<
template <class T>
ostream& operator<<(ostream& os, const LinkedDeque<T>& q)
{
	int i = 0;
	LinkNode<T> *curNode = q.front;
	while (NULL != curNode)
	{
		os << "[" << i++ << "]" << " : " << curNode->data << endl;
		curNode = curNode->link;
	}
	return os;
}


#endif /* LINKED_DEQUE_H_ */
