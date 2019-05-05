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

	linkedDeque->getHead((void*)&data);          //��ȡͷ
	cout <<"getHead:"<< data << endl;

	linkedDeque->getTail((void*)&data);			//��ȡβ
	cout << "getTail:" << data << endl;

	linkedDeque->EnQueueHead((void*)&data);		//ͷ���
	cout << "EnQueueHead:" << data << endl;

	linkedDeque->EnQueueTail((void*)&data);		//β���
	cout << "EnQueue:" << data << endl;

	linkedDeque->DeQueueHead((void*)&data);		//ɾ��ͷ
	cout << "DeQueueHead:" << data << endl;

	linkedDeque->DeQueueTail((void*)&data);		//ɾ��β
	cout << "DeQueueTail:" << data << endl;

	cout << linkedDeque->getSize() << endl;		//��ȡ���д�С
	
	cout << linkedDeque->IsEmpty() << endl;		//�ж��Ƿ�Ϊ��

	cout << linkedDeque->IsFull() << endl;		//�ж��Ƿ�Ϊ��

	linkedDeque->MakeEmpty();					//�ж��Ƿ�Ϊ��

	//linkedDeque->insert(3,(void*)4);	//����

	//linkedDeque->erase(3);			//ɾ��

	//linkedDeque->n_erase(3,4);		//ɾ��

	//linkedDeque->at(3);				//ȡԪ��

	system("pause");
	return 0;
}
