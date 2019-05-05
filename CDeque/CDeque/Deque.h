#pragma once

template <class T1, class T2>
class Pair
{
public:
	T1 key;  //关键字
	T2 value;  //值
	Pair(T1 k, T2 v) :key(k), value(v) { };
	bool operator < (const Pair<T1, T2> & p) const;
};


inline size_t __deque_buf_size(size_t n, size_t sz)
{
	return n != 0 ? n : (sz < 512 ? size_t(512 / sz) : size_t(1));
}







#ifndef __STL_NON_TYPE_TMPL_PARAM_BUG
template <class T, class Ref, class Ptr, size_t BufSiz>
struct __deque_iterator {
	typedef __deque_iterator<T, T&, T*, BufSiz>             iterator;
	typedef __deque_iterator<T, const T&, const T*, BufSiz> const_iterator;
	static size_t buffer_size() { return __deque_buf_size(BufSiz, sizeof(T)); }
#else /* __STL_NON_TYPE_TMPL_PARAM_BUG */
template <class T, class Ref, class Ptr>
struct __deque_iterator {
	typedef __deque_iterator<T, T&, T*>             iterator;
	typedef __deque_iterator<T, const T&, const T*> const_iterator;
	static size_t buffer_size() { return __deque_buf_size(0, sizeof(T)); }
#endif

	typedef size_t ptrdiff_t;
	//typedef random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef Ptr pointer;
	typedef Ref reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef T** map_pointer;

	typedef __deque_iterator self;

	T* cur;
	T* first;
	T* last;
	map_pointer node;

	__deque_iterator(T* x, map_pointer y)
		: cur(x), first(*y), last(*y + buffer_size()), node(y) {}
	__deque_iterator() : cur(0), first(0), last(0), node(0) {}
	__deque_iterator(const iterator& x)
		: cur(x.cur), first(x.first), last(x.last), node(x.node) {}

	reference operator*() const { return *cur; }
#ifndef __SGI_STL_NO_ARROW_OPERATOR
	pointer operator->() const { return &(operator*()); }
#endif /* __SGI_STL_NO_ARROW_OPERATOR */

	difference_type operator-(const self& x) const {
		return buffer_size() * (node - x.node - 1) +
			(cur - first) + (x.last - x.cur);
	}

	self& operator++() {
		++cur;
		if (cur == last) {
			set_node(node + 1);
			cur = first;
		}
		return *this;
	}
	self operator++(int)  {
		self tmp = *this;
		++*this;
		return tmp;
	}

	self& operator--() {
		if (cur == first) {
			set_node(node - 1);
			cur = last;
		}
		--cur;
		return *this;
	}
	self operator--(int) {
		self tmp = *this;
		--*this;
		return tmp;
	}

	self& operator+=(difference_type n) {
		difference_type offset = n + (cur - first);
		if (offset >= 0 && offset < buffer_size())
			cur += n;
		else {
			difference_type node_offset =
				offset > 0 ? offset / buffer_size()
				: -difference_type((-offset - 1) / buffer_size()) - 1;
			set_node(node + node_offset);
			cur = first + (offset - node_offset * buffer_size());
		}
		return *this;
	}

	self operator+(difference_type n) const {
		self tmp = *this;
		return tmp += n;
	}

	self& operator-=(difference_type n) { return *this += -n; }

	self operator-(difference_type n) const {
		self tmp = *this;
		return tmp -= n;
	}

	reference operator[](difference_type n) const { return *(*this + n); }

	bool operator==(const self& x) const { return cur == x.cur; }
	bool operator!=(const self& x) const { return !(*this == x); }
	bool operator<(const self& x) const {
		return (node == x.node) ? (cur < x.cur) : (node < x.node);
	}

	void set_node(map_pointer new_node) {
		node = new_node;
		first = *new_node;
		last = first + buffer_size();
	}
};


template<class T, class Alloc>
class simple_alloc {
public:
	static T *allocate(size_t n)
	{
		return 0 == n ? 0 : (T*)Alloc::allocate(n * sizeof (T));
	}
	static T *allocate(void)
	{
		return (T*)Alloc::allocate(sizeof (T));
	}
	static void deallocate(T *p, size_t n)
	{
		if (0 != n) Alloc::deallocate(p, n * sizeof (T));
	}
	static void deallocate(T *p)
	{
		Alloc::deallocate(p, sizeof (T));
	}
};


template<class T, class Alloc = alloc, size_t BufSiz = 0>
class CDeque
{
public:
	typedef T   value_type;
	typedef value_type* pointer;
	typedef size_t  size_type;
public:
	typedef __deque_iterator<T, T&, T*, BufSiz>  iterator;
protected:
	//元素的指针的指针(pointer of pointer of T)  
	typedef pointer*    map_pointer;


protected:                      // Data members  
	iterator start;   //指向第一个缓冲区  
	iterator finish;  //指向最后一个缓冲区  
	map_pointer map;  //指向map，map是块连续空间  
	size_type map_size;  //map内有多少个指针

public:
	//CDeque(size_type n, const value_type& value);

	CDeque(size_type n, const value_type& value)

		: start(), finish(), map(0), map_size(0)
	{
		fill_initialize(n, value);

	}
	//~CDeque();

	void fill_initialize(size_type n, const value_type& value)
	{
		create_map_and_nodes(n);
		map_pointer cur;
		//__STL_TRY
		//{
		//	//为每个节点的缓冲区设定初值   
		//	for (cur = start.node; cur < finish.node; ++cur)
		//	uninitialized_fill(*cur, *cur + buffer_size(), value);
		//	uninitialized_fill(finish.first, finish.cur, value);
		//}
	
	}
	void create_map_and_nodes(size_type num_elements)
	{
		/*  需要节点数（也就是缓冲区的个数）=（元素个数/每个缓冲区可容纳的元素个数）+1  如果如果是刚好整除，就会多分配一个节点  */
		size_type num_nodes = num_elements / __deque_iterator::buffer_size() + 1;
		/*  一个map管理的节点数为至少为8个，至多是所需要的节点数+2，以供deque前后  各预留一个，扩充时就可直接使用
		static size_type initial_map_size() { return 8; }  */
		//map_size = max(initial_map_size(), num_nodes + 2);
		//map = map_allocator::allocate(map_size);
		/*  令nstart和nfinish指向map所拥有之全部节点的最中央区段，这样就可以使  开始的时候，左右两边的空余空间大致相等  */
		map_pointer nstart = map + (map_size - num_nodes) / 2;
		map_pointer nfinish = nstart + num_nodes - 1;
		map_pointer cur;

		//__STL_TRY
		{
			//为map内的每个现用的节点配置缓冲区，这些缓冲区的大小就是目前deque的    //可用空间  
			//for (cur = nstart; cur <= nfinish; ++cur)
			//*cur = allocate_node();
		} /*pointer allocate_node() { return data_allocator::allocate(buffer_size()); }*/
#     ifdef  __STL_USE_EXCEPTIONS  
		catch (...) {
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
		finish.cur = finish.first + num_elements % __deque_iterator::buffer_size();
	}


#if 0
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

#endif

};

