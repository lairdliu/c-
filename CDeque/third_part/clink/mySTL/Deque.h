
#ifndef DEQUE_H_

#define DEQUE_H_

class Deque 
{
public:
	Deque(){}                               //构造函数
	virtual ~Deque(){}                     //析构函数
public:
	virtual void push_front(void *pData)=0;
	virtual void push_back(void *pData) = 0;
	virtual int insert(unsigned int nIndex, void *pData) = 0;
	virtual void erase(unsigned int nIndex) = 0;
	virtual void n_erase(unsigned int nFirst, unsigned int nSize) = 0;
	virtual void pop_front() = 0;
	virtual void pop_back() = 0;
	virtual void clear() = 0;
	virtual void* at(unsigned int pos) = 0;
	virtual bool empty()const = 0;
	virtual unsigned int size()const = 0;
};
#endif












