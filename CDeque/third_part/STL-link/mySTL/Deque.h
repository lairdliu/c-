
#ifndef DEQUE_H_

#define DEQUE_H_

template <class T>
class Deque 
{
public:
	Deque(){}                               //构造函数
	virtual ~Deque(){}                     //析构函数
public:
	virtual bool getHead(void *pData)const = 0;        //读取队头元素，并将该元素的值保存至x
	virtual bool getTail(void *pData)const = 0;        //读取队尾元素，并将该元素的值保存至x
	virtual bool EnQueue(void *pData) = 0;       //新元素x入队——从队尾入队
	virtual bool EnQueueHead(void *pData) = 0;   //新元素x入队——从队头入队
	virtual bool EnQueueTail(void *pData) = 0;   //新元素x入队——从队尾入队
	virtual bool DeQueue(void *pData) = 0;             //队头元素出队，并将该元素的值保存至x
	virtual bool DeQueueHead(void *pData) = 0;         //队头元素出队，并将该元素的值保存至x
	virtual bool DeQueueTail(void *pData) = 0;         //队尾元素出队，并将该元素的值保存至x
	virtual bool IsEmpty() const = 0;           //判断队列是否为空
	virtual bool IsFull() const = 0;            //判断队列是否为满
	virtual void MakeEmpty() = 0;               //清空队列的内容
	virtual int getSize() const = 0;            //计算队列中元素个数
};
#endif












