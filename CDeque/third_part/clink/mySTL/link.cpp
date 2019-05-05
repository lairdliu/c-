#include<iostream>
#include<assert.h>
#include <string.h>
#include"link.h"

using namespace std;
//�ڵ��๹�캯��*
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

//������*
CDeque::CDeque()         //���캯��   �����б����
: _head(NULL)
, _tail(NULL)
, m_nLength(0)
{}

CDeque::CDeque(const CDeque& s)          //������������
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

CDeque& CDeque::operator=(CDeque &s)     //��ֵ��������������Ż�(�Ƽ�д��)
{
	//todo3 �Լ�ʵ��
	//1����������б� �ٸ��б�ֵ

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
CDeque::~CDeque()    //����
{
	clear();
}

//��ӡ����*
void CDeque::PrintSList()
{
	//ͷ���Ϊ��ʱ�������ӡ����
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

void CDeque::push_back(void* pData)    //��β������һ���ڵ�*
{
	//�������Ϊ�գ�����ڵ��ֻ��һ���ڵ㣬��ʱ_head=_tail
	if (_head == NULL)
	{
		_head = new LinkNode(pData);
		_tail = _head;
		m_nLength++;
	}
	else
	{
		_tail->_next = new LinkNode(pData); //β���½��ڵ�
		_tail->_next->_prev = _tail;      //�½ڵ�ǰָ��ָ��β���ڵ�
		_tail = _tail->_next;				//���½ڵ�����Ϊβ���ڵ�
		m_nLength++;
	}
}

void CDeque::clear()         //�����ÿ�*
{
	LinkNode* begin = _head;
	while (begin != _tail)
	{
		_head = _head->_next;  //����һ�����ͷ
		delete begin;			//�ͷžɵ�ͷ
		begin = _head;			//�ڽ�ͷָ��� begin
	}
	_head = NULL;
	_tail = NULL;
	m_nLength = 0;
}

void CDeque::pop_back()    //βɾ
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
		//�Ż�ɾ��βָ�루����ʵ�֣�
		LinkNode* tmp = _tail;		//
		_tail = _tail->_prev;		//1������ָ��β�ڵ�
		_tail->_next = NULL;		//2����β�ڵ����һ����Ϊ��
		m_nLength--;
		delete tmp;					//3��ɾ���ɵ�β�ڵ�

	}
}

void CDeque::push_front(void* pData)  //ͷ��*
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

void CDeque::pop_front()    //ɾ���׽ڵ�
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
			tmp->_next = tmp1->_next;		// 1���ɽڵ���ָ��ַ��ֵ���½ڵ���ָ
			tmp1->_next = tmp;				// 2���ɽڵ�ָ���½ڵ�
			tmp->_next->_prev = tmp;		//3����һ�ڵ�ǰһ��ָ���½ڵ�
			tmp->_prev = tmp1;				//4���½ڵ�ָ��ɽڵ�
			m_nLength++;
			return 0;
		}
	}
	return -1;
}

unsigned int CDeque::size()const  //��������ڵ����Ŀ 
{
	//todo2 �Ż�size
	if (_head == NULL)
	{
		return 0;
	}
	else
	{
		return m_nLength;
	}
}

void CDeque::erase(unsigned int nIndex)      //����ĳ�ڵ㲢ɾ��
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
	//todo1 �Ż�n_erase�� Խ�����⴦��
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