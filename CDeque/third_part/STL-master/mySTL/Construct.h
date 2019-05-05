#ifndef _CONSTRUCT_H_
#define _CONSTRUCT_H_

#include"type_traits.h"
#include<new>
namespace STL {
	template<typename T1, typename T2>
	inline void construct(T1* p, const T2& value) {
		new(p)T1(value);
	}
	//������������,��һ���汾������һ��ָ��
	template<typename T>
	inline void destroy(T* pointer) {
		pointer->~T();
	}
	//��������������
	template<class ForwordIterator>
	inline void destroy(ForwordIterator first, ForwordIterator last) {
		__destroy(first, last);
	}

	template<class ForwardIterator>
	inline void __destroy(ForwardIterator first, ForwardIterator last) {
		typedef typename STL::__type_traits<ForwardIterator>::has_trivial_destructor trivial_destoructor;
		__destroy_aux(first, last, trivial_destoructor());
	}

	template<class ForwardIterator>
	inline void __destroy_aux(ForwardIterator first, ForwardIterator last, STL::__true_type) {}

	template<class ForwardIterator>
	void __destroy_aux(ForwardIterator first, ForwardIterator last, STL::__false_type) {
		for (; first < last; ++first) {
			destroy(&*first);
		}
	}
}
#endif