
#ifndef DEQUE_H_

#define DEQUE_H_

template <class T>
class Deque 
{
public:
	Deque(){}                               //���캯��
	virtual ~Deque(){}                     //��������
public:
	virtual bool getHead(void *pData)const = 0;        //��ȡ��ͷԪ�أ�������Ԫ�ص�ֵ������x
	virtual bool getTail(void *pData)const = 0;        //��ȡ��βԪ�أ�������Ԫ�ص�ֵ������x
	virtual bool EnQueue(void *pData) = 0;       //��Ԫ��x��ӡ����Ӷ�β���
	virtual bool EnQueueHead(void *pData) = 0;   //��Ԫ��x��ӡ����Ӷ�ͷ���
	virtual bool EnQueueTail(void *pData) = 0;   //��Ԫ��x��ӡ����Ӷ�β���
	virtual bool DeQueue(void *pData) = 0;             //��ͷԪ�س��ӣ�������Ԫ�ص�ֵ������x
	virtual bool DeQueueHead(void *pData) = 0;         //��ͷԪ�س��ӣ�������Ԫ�ص�ֵ������x
	virtual bool DeQueueTail(void *pData) = 0;         //��βԪ�س��ӣ�������Ԫ�ص�ֵ������x
	virtual bool IsEmpty() const = 0;           //�ж϶����Ƿ�Ϊ��
	virtual bool IsFull() const = 0;            //�ж϶����Ƿ�Ϊ��
	virtual void MakeEmpty() = 0;               //��ն��е�����
	virtual int getSize() const = 0;            //���������Ԫ�ظ���
};
#endif












