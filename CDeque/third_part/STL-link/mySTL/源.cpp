#include "link.h"

int main(int argc, char* argv[])
{
	int data=100;
	LinkedDeque *linkedDeque = new LinkedDeque();

	cout << "deque test:" <<  endl;
	for (int i = 0; i< 20; i++)
	{
		linkedDeque->EnQueue((void*)&i);
	}

	linkedDeque->getHead((void*)&data);          //获取头
	cout <<"getHead:"<< data << endl;

	linkedDeque->getTail((void*)&data);			//获取尾
	cout << "getTail:" << data << endl;

	linkedDeque->EnQueueHead((void*)&data);		//头入队
	cout << "EnQueueHead:" << data << endl;

	linkedDeque->EnQueueTail((void*)&data);		//尾入队
	cout << "EnQueue:" << data << endl;

	linkedDeque->DeQueueHead((void*)&data);		//删除头
	cout << "DeQueueHead:" << data << endl;

	linkedDeque->DeQueueTail((void*)&data);		//删除尾
	cout << "DeQueueTail:" << data << endl;

	cout << linkedDeque->getSize() << endl;		//获取队列大小
	
	cout << linkedDeque->IsEmpty() << endl;		//判断是否为空

	cout << linkedDeque->IsFull() << endl;		//判断是否为满

	linkedDeque->MakeEmpty();					//判断是否为满

	//linkedDeque->insert(3,(void*)4);	//插入

	//linkedDeque->erase(3);			//删除

	//linkedDeque->n_erase(3,4);		//删除

	//linkedDeque->at(3);				//取元素

	system("pause");
	return 0;
}
