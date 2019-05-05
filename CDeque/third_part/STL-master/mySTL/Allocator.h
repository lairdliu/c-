#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

#include<new>
#include"alloc.h"
#include"Construct.h"

namespace STL{

	/*
    **��alloc�����ĵ�ַ�ռ����placement new ����
	**�Լ�����������������ݽ��ж�Ӧ������
	*/
	template <class T>
	class allocator{
	public:
		typedef T			value_type;
		typedef T*			pointer;
		typedef const T*	const_pointer;
		typedef T&			reference;
		typedef const T&	const_reference;
		typedef size_t		size_type;
		typedef ptrdiff_t	difference_type;

	public:
		//����δ������ڴ�ռ䣬ʹ���Դ���alloc
		static T *allocate();
		static T *allocate(size_t n);
		static void deallocate(T *ptr);
		static void deallocate(T *ptr, size_t n);


		/*
		**���µĹ��������������Դ��й��캯�������������Ķ���
		**���ڻ�������ֱ�ӷ����ڴ�ռ�
		*/
		static void construct(T *ptr);
		static void construct(T *ptr, const T& value);
		static void destroy(T *ptr);
		static void destroy(T *first, T *last);

	public:
		allocator() {};
		~allocator() {};
	};
	
	template<class T>
	T *allocator<T>::allocate() {
		return static_cast<T *>(alloc::allocate(sizeof(T)));
	}
	template<class T>
	T *allocator<T>::allocate(size_t n) {
		if (n == 0) return 0;
		return static_cast<T *>(alloc::allocate(sizeof(T) * n));
	}
	template<class T>
	void allocator<T>::deallocate(T *ptr) {
		alloc::deallocate(static_cast<void *>(ptr), sizeof(T));
	}
	template<class T>
	void allocator<T>::deallocate(T *ptr, size_t n) {
		if (n == 0) return;
		alloc::deallocate(static_cast<void *>(ptr), sizeof(T)* n);
	}

	template<class T>
	void allocator<T>::construct(T *ptr) {//����default placement new 
		STL::construct(ptr,T());
	}
	template<class T>
	void allocator<T>::construct(T *ptr, const T& value) {//���ε��� placement new 
		STL::construct(ptr, value);
	}
	template<class T>
	void allocator<T>::destroy(T *ptr) {// ���� operator delete ȥ���� T
		STL::destroy(ptr);
	}
	template<class T>
	void allocator<T>::destroy(T *first, T *last) {
		STL::destroy(first,last);
	}
}
#endif