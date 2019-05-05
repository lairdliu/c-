#include "Deque.h"


template<class T1, class T2>
bool Pair<T1, T2>::operator < (const Pair<T1, T2> & p) const
	//Pair�ĳ�Ա���� operator <
{ //"С"����˼���ǹؼ���С
	return key < p.key;
}



//template <class T, class Alloc = alloc, size_t BufSiz = 0>
//CDeque<T, Alloc, BufSiz>::CDeque(size_type n, const value_type& value)
//: start(), finish(), map(0), map_size(0)
//{
//	//fill_initialize(n, value);
//}

//template <class T, class Alloc = alloc, size_t BufSiz = 0>
//CDeque<T, Alloc, BufSiz>::~CDeque()
//{
//
//
//}


#if 0
template <class T, class Alloc, size_t BufSize>
void CDeque<T, Alloc, BufSize>::fill_initialize(size_type n, const value_type& value)
{
	create_map_and_nodes(n);
	map_pointer cur;
	__STL_TRY
	{
		//Ϊÿ���ڵ�Ļ������趨��ֵ   
		for (cur = start.node;cur < finish.node; ++cur)
			uninitialized_fill(*cur, *cur + buffer_size(), value);
		uninitialized_fill(finish.first, finish.cur, value);
	}
}



template <class T, class Alloc, size_t BufSize>
void CDeque<T, Alloc, BufSize>::create_map_and_nodes(size_type num_elements)
{
		/*  ��Ҫ�ڵ�����Ҳ���ǻ������ĸ�����=��Ԫ�ظ���/ÿ�������������ɵ�Ԫ�ظ�����+1  �������Ǹպ��������ͻ�����һ���ڵ�  */  
	size_type num_nodes = num_elements / buffer_size() + 1;
		/*  һ��map����Ľڵ���Ϊ����Ϊ8��������������Ҫ�Ľڵ���+2���Թ�dequeǰ��  ��Ԥ��һ��������ʱ�Ϳ�ֱ��ʹ�� 
		static size_type initial_map_size() { return 8; }  */
		map_size = max(initial_map_size(), num_nodes + 2); 
		map = map_allocator::allocate(map_size);   
		/*  ��nstart��nfinishָ��map��ӵ��֮ȫ���ڵ�����������Σ������Ϳ���ʹ  ��ʼ��ʱ���������ߵĿ���ռ�������  */ 
		map_pointer nstart = map + (map_size - num_nodes) / 2; 
		map_pointer nfinish = nstart + num_nodes - 1;    
		map_pointer cur;  
		__STL_TRY
		{   
			//Ϊmap�ڵ�ÿ�����õĽڵ����û���������Щ�������Ĵ�С����Ŀǰdeque��    //���ÿռ�  
			for (cur = nstart; cur <= nfinish; ++cur)    
			*cur = allocate_node();
		} /*pointer allocate_node() { return data_allocator::allocate(buffer_size()); }*/
	#     ifdef  __STL_USE_EXCEPTIONS  
		catch(...) {  
			for (map_pointer n = nstart; n < cur; ++n)   
				deallocate_node(*n);  
			map_allocator::deallocate(map, map_size);  
			throw; 
		}
	#     endif /* __STL_USE_EXCEPTIONS */ 
		//Ϊdeque�ڵ�����������start��end�趨��ȷ���� 
		start.set_node(nstart); 
		finish.set_node(nfinish);  
		start.cur = start.first;
		finish.cur = finish.first + num_elements % buffer_size();
}
	






/*********************************************************
*
**********************************************************/
template<class T, class Ptr, size_t BufSiz = 0>
void CDeque<T, Ptr, BufSiz>::push_front(void *pData)
{

}


/*********************************************************
*
**********************************************************/
template<class T,  class Ptr, size_t BufSiz = 0>
void CDeque<T,  Ptr, BufSiz>::push_back(void *pData)
{

}

/*********************************************************
*
**********************************************************/
template<class T,  class Ptr, size_t BufSiz = 0>
int CDeque<T,  Ptr, BufSiz>::insert(unsigned int nIndex, void *pData)
{

}

/*********************************************************
*
**********************************************************/
template<class T,  class Ptr, size_t BufSiz = 0>
void CDeque<T,  Ptr, BufSiz>::erase(unsigned int nIndex)
{

}

/*********************************************************
*
**********************************************************/
template<class T,  class Ptr, size_t BufSiz = 0>
void CDeque<T, Ptr, BufSiz>::n_erase(unsigned int nFirst, unsigned int nSize)
{

}

/*********************************************************
*
**********************************************************/
template<class T,  class Ptr, size_t BufSiz = 0>
void CDeque<T,  Ptr, BufSiz>::pop_front()
{

}

/*********************************************************
*
**********************************************************/
template<class T,  class Ptr, size_t BufSiz = 0>
void CDeque<T,  Ptr, BufSiz>::pop_back()
{

}

/*********************************************************
*
**********************************************************/
template<class T,  class Ptr, size_t BufSiz = 0>
void CDeque<T, Ptr, BufSiz>::clear()
{

}

/*********************************************************
*
**********************************************************/
template<class T,  class Ptr, size_t BufSiz = 0>
void* CDeque<T,  Ptr, BufSiz>::at(unsigned int pos)
{

}

/*********************************************************
*
**********************************************************/
template<class T,  class Ptr, size_t BufSiz = 0>
bool CDeque<T,  Ptr, BufSiz>::empty()const
{

}

/*********************************************************
*
**********************************************************/
template<class T,  class Ptr, size_t BufSiz = 0>
unsigned int CDeque<T, Ptr, BufSiz>::size()const
{

}

#endif