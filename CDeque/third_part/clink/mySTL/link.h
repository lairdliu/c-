/*************************************
*1���û�������Բ�����˽���޸�
*2��
*3��
*4��
**************************************/

struct LinkNode      //�ڵ���(����д��)
{
	LinkNode(void* pData);
	~LinkNode();
	void* _pdata;			//�ڵ������
	LinkNode* _next;		//���ָ��
	LinkNode* _prev;		//ǰ��ָ��
};

class CDeque    //������
{
public:
	CDeque();         //���캯��
	CDeque(const CDeque& s);        //��������

	CDeque &operator=(CDeque& s);    //��ֵ�����������
	~CDeque();

public:
	void push_front(void *pData);
	void push_back(void *pData);
	int insert(unsigned int nIndex, void *pData);
	void erase(unsigned int nIndex);
	void n_erase(unsigned int nFirst, unsigned int nSize);
	void pop_front();
	void pop_back();
	void clear();
	void* at(unsigned int pos);
	bool empty()const;
	unsigned int size()const;

	//���Ժ���
	void PrintSList();   //��ӡ����

private:
	LinkNode* _head;    //ָ��ͷ���
	LinkNode* _tail;    //ָ��β�ڵ�
	int m_nLength;
};



