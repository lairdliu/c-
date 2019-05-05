#include "Deque.h"


template<class T1, class T2>
bool Pair<T1, T2>::operator < (const Pair<T1, T2> & p) const
	//Pair的成员函数 operator <
{ //"小"的意思就是关键字小
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
		//为每个节点的缓冲区设定初值   
		for (cur = start.node;cur < finish.node; ++cur)
			uninitialized_fill(*cur, *cur + buffer_size(), value);
		uninitialized_fill(finish.first, finish.cur, value);
	}
}



template <class T, class Alloc, size_t BufSize>
void CDeque<T, Alloc, BufSize>::create_map_and_nodes(size_type num_elements)
{
		/*  需要节点数（也就是缓冲区的个数）=（元素个数/每个缓冲区可容纳的元素个数）+1  如果如果是刚好整除，就会多分配一个节点  */  
	size_type num_nodes = num_elements / buffer_size() + 1;
		/*  一个map管理的节点数为至少为8个，至多是所需要的节点数+2，以供deque前后  各预留一个，扩充时就可直接使用 
		static size_type initial_map_size() { return 8; }  */
		map_size = max(initial_map_size(), num_nodes + 2); 
		map = map_allocator::allocate(map_size);   
		/*  令nstart和nfinish指向map所拥有之全部节点的最中央区段，这样就可以使  开始的时候，左右两边的空余空间大致相等  */ 
		map_pointer nstart = map + (map_size - num_nodes) / 2; 
		map_pointer nfinish = nstart + num_nodes - 1;    
		map_pointer cur;  
		__STL_TRY
		{   
			//为map内的每个现用的节点配置缓冲区，这些缓冲区的大小就是目前deque的    //可用空间  
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
		//为deque内的两个迭代器start和end设定正确内容 
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