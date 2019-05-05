#ifndef _DEQUE_H_
#define _DEQUE_H_
#include"Allocator.h"
#include"Iterator.h"
#include"Algorithm.h"
#include"UninitializedFunc.h"

/**********************************
*��Ҫ���⣺
*1�����ֺ���û����ϸ׷��ʵ��ԭ��
*2����ܽṹû���γ����ģʽ����
*3������ģʽ������
*
***********************************/


namespace STL {
	template<class T, class Alloc = allocator<T>>
	class deque;

	namespace Detail {
		//1��˫�˶���ָ���� deque_iterator
		template<class T>
		class deque_iterator :public iterator<random_access_iterator_tag, T> {//�̳��԰�����׼������typedef��iterator
			template<class T, class Alloc>
			friend class deque;							//������Ԫ  
			typedef deque<T>* containerPtr;
		private:
			containerPtr container_;						//����ָ����е�ָ��
			size_t    mapIndex_;							//
			T*           cur_;								//�˵�������ָ�������ĵ�ǰλ��
		public:
			//�������
			deque_iterator()											//1���޲ι���
				:mapIndex_(-1), cur_(nullptr), container_(nullptr) {}    //ʵ�л�����Ĭ�����޲ι���

			deque_iterator(size_t index, T *ptr, containerPtr container)//2���вι���
				:mapIndex_(index), cur_(ptr), container_(container) {}
			deque_iterator(const deque_iterator& it)					//3���вι���
				:mapIndex_(it.mapIndex_), cur_(it.cur_), container_(it.container_) {}
			
			deque_iterator& operator = (const deque_iterator& it);		//��ֵ���������

			//��������
			deque_iterator& operator ++ ();								//����ǰ��++
			deque_iterator operator ++ (int);							//���غ���++
			deque_iterator& operator -- ();
			deque_iterator operator -- (int);
			reference operator *() { return *cur_; }					//*�����
			const reference operator *()const { return *cur_; }			//const�޶�
			pointer operator ->() { return &(operator*()); }			//->�����
			const pointer operator ->()const { return &(operator*()); }

			bool operator ==(const deque_iterator& rhs)const;
			bool operator !=(const deque_iterator& rhs)const;

		public:
			template<class T>
			friend typename deque_iterator<T>::difference_type operator -(const deque_iterator<T>& lhs, const deque_iterator<T>& rhs);
			template<class T>
			friend deque_iterator<T> operator +(const deque_iterator<T>& it,  typename deque_iterator<T>::difference_type n);
			template<class T>
			friend deque_iterator<T> operator -(const deque_iterator<T>& it, typename deque_iterator<T>::difference_type n);
			
		private://�������
			T* getNowBuckTail()const;
			T* getNowBuckHead()const;
			size_t getBuckSize()const;
		};

	}//end of Detail

	template<class T, class Alloc = allocator<T>>
	class deque {
	public:
		typedef T                  value_type;
		typedef value_type*        pointer;
		typedef T&                 reference;
		typedef const reference    const_reference;
		typedef size_t             size_type;
		typedef ptrdiff_t          difference_type;
		typedef Alloc              allocator_type;
		typedef Detail::deque_iterator<T>   iterator;
	private:
		template<class T>
		friend class       ::STL::Detail::deque_iterator;
		typedef Alloc              dataAllocator;
		typedef allocator<T*>       mapAllocator;
		typedef pointer*      map_Pointer;

		//�ϱߵ�������߼��޹�
	private:
		iterator start_;				//ָ��map��ͷ��
		iterator finish_;				//ָ��map��β��
		map_Pointer map_;				//3��ָ��map��mapΪһ�������ռ䣩,���ڲ�Ԫ��Ϊָ�룬ÿ��ָ��ָ��һ��������
		size_type map_size_;			//4��map�ڲ�ָ��ĸ���
		static enum class BuckSize { BUCK_SIZE = 16};
	public:
		//Ԫ�ط���
		iterator begin() { return start_; }
		iterator end() { return finish_; }
		iterator begin()const { return start_; }
		iterator end() const { return finish_; }
		reference operator[] (size_type n);
		reference front();
		reference back();
		const_reference operator[] (size_type n) const;
		const_reference front() const;
		const_reference back() const;

		//�ռ�
		size_type size() const { return end() - begin(); }
		bool empty() const { return begin() == end(); }

	public:
		deque();											//1���޲ι���
		explicit deque(size_type n, const value_type& val = value_type());
		template <class InputIterator>
		deque(InputIterator first, InputIterator last);
		deque(const deque& rhs);
		deque(const deque&& rhs);
		~deque();
	private:
		//�ռ�������

		T * getANewBuck();
		T ** getNewMapAndGetNewBucks(const size_t& size);
		T**  GetNewMap(const size_t& size);
		void __deque(size_t n, const value_type& value, std::true_type);
		template<class InputIterator>
		void __deque(InputIterator first, InputIterator last, std::false_type);

		void __push_back(const value_type& value);
		void __push_front(const value_type& value);
		
		void reallocateMap(size_t nodes_to_add,bool add_at_front);
		void init();
		void __pop_front();
		void __pop_back();
		void deallocateABuck(size_t index);
		void creat_map_and_nodes(size_t n);
	public:

		//Ԫ�ز���
		void push_back(const value_type& val);
		void push_front(const value_type& val);
		void pop_back();
		void pop_front();
		void clear();

	
		int insert(unsigned int nIndex, void *pData);
		void erase(unsigned int nIndex);
		void n_erase(unsigned int nFirst, unsigned int nSize);
		T at(unsigned int pos);
		
	private:

		//��ȡ����(�ڲ��������ʹ�ã� ÿ�����ڴ�� 16��Ͱ
		size_type getBuckSize()const { return (size_type)BuckSize::BUCK_SIZE; }
		size_t getNewMapSize(const size_t size);
		bool isBackFull()const;
		bool isFrontFull()const;
	};
}


//Ҫ��Ҫ����
#include "Deque.cpp"

#endif // !_DEQUE_H_
