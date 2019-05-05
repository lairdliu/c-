
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
	LinkedDeque();              //���캯��
	virtual ~LinkedDeque();     //��������
public:
	virtual bool getHead(T& x)const;        //��ȡ��ͷԪ�أ�������Ԫ�ص�ֵ������x
	virtual bool getTail(T& x)const;        //��ȡ��βԪ�أ�������Ԫ�ص�ֵ������x
	virtual bool EnQueue(const T& x);       //��Ԫ��x��ӡ����Ӷ�β���
	virtual bool EnQueueHead(const T& x);   //��Ԫ��x��ӡ����Ӷ�ͷ���
	virtual bool EnQueueTail(const T& x);   //��Ԫ��x��ӡ����Ӷ�β���
	virtual bool DeQueue(T& x);             //��ͷԪ�س��ӣ�������Ԫ�ص�ֵ������x
	virtual bool DeQueueHead(T& x);         //��ͷԪ�س��ӣ�������Ԫ�ص�ֵ������x
	virtual bool DeQueueTail(T& x);         //��βԪ�س��ӣ�������Ԫ�ص�ֵ������x
	virtual bool IsEmpty() const;           //�ж϶����Ƿ�Ϊ��
	virtual bool IsFull() const;            //�ж϶����Ƿ�Ϊ��
	virtual void MakeEmpty();               //��ն��е�����
	virtual int getSize() const;            //���������Ԫ�ظ���

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
	friend ostream& operator<<(ostream& os, const LinkedDeque<T>& q);   //�������Ԫ�ص����ز���<<
private:
	LinkNode<T> *front; //��ͷָ�룬����ͷָ��
	LinkNode<T> *rear;  //��βָ�룬����βָ��
};

//���캯��
template <class T>
LinkedDeque<T>::LinkedDeque()
: front(NULL), rear(NULL)
{
	cout << "$ ִ�й��캯��" << endl;
}

//��������
template <class T>
LinkedDeque<T>::~LinkedDeque()
{
	cout << "$ ִ����������" << endl;
	MakeEmpty();
}

//��ȡ��ͷԪ�أ�������Ԫ�ص�ֵ������x
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

//��ȡ��βԪ�أ�������Ԫ�ص�ֵ������x
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

//��Ԫ��x��ӡ����Ӷ�β���
template <class T>
bool LinkedDeque<T>::EnQueue(const T& x)
{
	return EnQueueTail(x);
}

//��Ԫ��x��ӡ����Ӷ�ͷ���
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

//��Ԫ��x��ӡ����Ӷ�β���
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

//��ͷԪ�س��ӣ�������Ԫ�ص�ֵ������x
template <class T>
bool LinkedDeque<T>::DeQueue(T& x)
{
	return DeQueueHead(x);
}

//��ͷԪ�س��ӣ�������Ԫ�ص�ֵ������x
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

//��βԪ�س��ӣ�������Ԫ�ص�ֵ������x
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

//�ж϶����Ƿ�Ϊ��
template <class T>
bool LinkedDeque<T>::IsEmpty() const
{
	return (NULL == front) ? true : false;
}

//�ж϶����Ƿ�Ϊ��
template <class T>
bool LinkedDeque<T>::IsFull() const
{
	return false;
}

//��ն��е�����
template <class T>
void LinkedDeque<T>::MakeEmpty()
{
	LinkNode<T> *curNode = NULL;
	while (NULL != front)           //������Ϊ��ʱ��ɾȥ���������н��
	{
		curNode = front;            //���汻ɾ���
		front = curNode->link;      //��ɾ������һ������Ϊͷ���
		delete curNode;             //��������ժ�±�ɾ���
	}
}

//���������Ԫ�ظ���
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

//�������Ԫ�ص����ز���<<
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
