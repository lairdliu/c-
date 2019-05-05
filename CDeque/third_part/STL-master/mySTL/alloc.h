#ifndef _ALLOC_H_
#define _ALLOC_H_

#include<cstdlib>
namespace STL{
	/*
	** �ռ������������ֽ���Ϊ��λȥ�����ڴ�ռ�
	** ��Allocator�ڲ�ʹ��
	*/

	class alloc{
	private:
		enum { __ALIGN = 8 };//С��������ϵ��߽�
		enum { __MAX_BYTES = 128 };//С�����������,���� __MAX_BYTES ��ֱ����malloc����
		enum { __NFREELISTS = __MAX_BYTES / __ALIGN };//free_lists ����
		enum { NOBJS = 20 };//ÿ�����ӵĽڵ���


	private:
		static size_t ROUND_UP(size_t bytes) {//�� bytes �ϵ���8�ı���
			return (((bytes)+__ALIGN - 1)&~(__ALIGN - 1));
		}

	private:
		union obj {// free_lists �Ľڵ�
			union obj* free_list_link;
			char client_data[1];
		};

		//16��  free_list
		static obj* free_list[__NFREELISTS];
	private:
		//�Խ��ڴ��
		static char *start_free;//�ڴ����ʼλ��
		static char *end_free;//�ڴ�ؽ���λ��
		static size_t heap_size;

	private://���ú���
		
		//���������С������ʹ�õ�n��free_list�� n �� 0 ���� 
		static size_t FREELIST_INDEX(size_t bytes) {
			return (((bytes)+__ALIGN - 1)/__ALIGN - 1);
		}
		//����һ����СΪn�Ķ��󣬲����ܼ����СΪn���������鵽free_list
		static void *refill(size_t n);
		//����һ���ռ䣬������nobjs����СΪsize������
		//�������nobjs�������������㣬nobjs���ܻή��
		static char *chunk_alloc(size_t size, size_t& nobjs);

	public:
		static void *allocate(size_t bytes);
		static void deallocate(void *ptr, size_t bytes);
		static void *reallocate(void *ptr, size_t old_sz, size_t new_sz);
	public:
		alloc() {};
		~alloc() {};	
	};
}

#endif