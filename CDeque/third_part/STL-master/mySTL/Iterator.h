#ifndef _ITERATOR_H_
#define _ITERATOR_H_

namespace STL {
	//五种迭代器类型
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag :public input_iterator_tag {};
	struct bidirectional_iterator_tag :public forward_iterator_tag {};
	struct random_access_iterator_tag :public bidirectional_iterator_tag {};

	template<class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T* , class Reference = T& >
		struct iterator								//智能指针基类
	{
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};
	
	template<class T>
	struct iterator_traits							//智能指针基类
	{//  型别“榨汁机”
		typedef typename random_access_iterator_tag	 iterator_category;
		typedef typename T		                     value_type;
		typedef typename size_t 	                 difference_type;
		typedef typename T*							 pointer;
		typedef typename T&			                 reference;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef random_access_iterator_tag 	iterator_category;
		typedef T 							value_type;
		typedef size_t 					difference_type;
		typedef T*							pointer;
		typedef T& 							reference;
	};
}

#endif