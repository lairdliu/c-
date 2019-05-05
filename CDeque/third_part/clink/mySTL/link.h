/*************************************
*1、用户需求绝对不允许私自修改
*2、
*3、
*4、
**************************************/

struct LinkNode      //节点类(建议写法)
{
	LinkNode(void* pData);
	~LinkNode();
	void* _pdata;			//节点的数据
	LinkNode* _next;		//后继指针
	LinkNode* _prev;		//前驱指针
};

class CDeque    //链表类
{
public:
	CDeque();         //构造函数
	CDeque(const CDeque& s);        //拷贝构造

	CDeque &operator=(CDeque& s);    //赋值运算符的重载
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

	//测试函数
	void PrintSList();   //打印链表

private:
	LinkNode* _head;    //指向头结点
	LinkNode* _tail;    //指向尾节点
	int m_nLength;
};



