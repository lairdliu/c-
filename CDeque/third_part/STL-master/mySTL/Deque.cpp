#include"Deque.h"
#ifndef _DEQUE_DETAIL_H_
#define _DEQUE_DETAIL_H_
namespace STL {
	namespace Detail {

		template<class T>		 //��ģ������
		deque_iterator<T>& deque_iterator<T>::operator = (const deque_iterator & it) {
			if (this != &it) {
				this->cur_ = it.cur_;
				this->mapIndex_ = it.mapIndex_;
				this->container_ = it.container_;
			}
			return *this;
		}

		template<class T>
		deque_iterator<T>  & deque_iterator<T>::operator++() {
			if (cur_ != getNowBuckTail()) {//+1֮����Ȼ��Ͱ��
				++cur_;
			}
			else if (mapIndex_ + 1 < container_->map_size_) {//�Ѿ���Ͱ�Ľ�β������֮�����µ�mapָ��
				++mapIndex_;
				cur_ = getNowBuckHead();//ָ����һ��Ͱ�Ŀ�ͷ
			}
			else {//mapIndex_ +1֮��û����map
				mapIndex_ = container_->map_size_;

				cur_ = container_->map_[mapIndex_];//ָ�����һ��Ͱ�����һ��Ԫ�صĺ�����
			}
			return *this;
		}
		template<class T>
		deque_iterator<T> deque_iterator<T>::operator++(int) {
			auto tmp = *this;
			++*this;
			return tmp;
		}
		template<class T>
		deque_iterator<T>  & deque_iterator<T>::operator--() {
			if (cur_ != getNowBuckHead()) {
				--cur_;
			}
			else if (mapIndex_ - 1 >= 0) {
				--mapIndex_;
				cur_ = getNowBuckTail();
			}
			else {
				mapIndex_ = 0;
				cur_ = container_->map_[mapIndex_];
			}
			return *this;
		}
		template<class T>
		deque_iterator<T> deque_iterator<T>::operator--(int)
		{
			auto retIter = *this;
			--*this;
			return retIter;
		}
		template<class T>
		bool deque_iterator<T>::operator==(const deque_iterator & rhs) const {
			return ((mapIndex_ == rhs.mapIndex_)
				&& (cur_ == rhs.cur_)
				&& (container_ == rhs.container_));
		}
		template<class T>
		inline bool deque_iterator<T>::operator!=(const deque_iterator & rhs) const {
			return !(rhs == *this);
		}
		template<class T>
		T* deque_iterator<T>::getNowBuckTail()const
		{
			//int num = container_->getBuckSize();
			return container_->map_[mapIndex_] + (container_->getBuckSize() - 1);
		}
		template<class T>
		T* deque_iterator<T>::getNowBuckHead()const
		{
			return container_->map_[mapIndex_];
		}
		template<class T>
		size_t deque_iterator<T>::getBuckSize() const {
			return container_->getBuckSize();
		}
		template<class T>
		typename deque_iterator<T>::difference_type operator -(const deque_iterator<T>& lhs
			, const deque_iterator<T>& rhs) {
			if (lhs.container_ != rhs.container_) {
				return 0;
			}
			else if (lhs.container_ == rhs.container_&&lhs.container_ == nullptr) {
				return 0;
			}
			typename deque_iterator<T>::difference_type retDis =
				typename deque_iterator<T>::difference_type(
				(lhs.mapIndex_ - rhs.mapIndex_ - 1)*lhs.getBuckSize()
					+ (lhs.cur_ - lhs.getNowBuckHead() + 1)
					+ (rhs.getNowBuckTail() - rhs.cur_)
				);
			return retDis;
		}
		template<class T>
		deque_iterator<T> operator +(const deque_iterator<T>& it
			, typename deque_iterator<T>::difference_type n) {
			deque_iterator<T> retIt(it);
			auto leftSize = retIt.getNowBuckTail() - retIt.cur_;
			if (n <= leftSize) {//ǰ��n������Ȼ�ڵ�ǰͰ��   ���ж��Ƿ��ڵ�ǰͰ��
				retIt.cur_ += n;
			}
			else {
				n -= leftSize;
				size_t newBuckIndex = n % retIt.getBuckSize() - 1;
				size_t newMapIndex = retIt.mapIndex_ + n / retIt.getBuckSize() + 1;
				retIt.mapIndex_ = newMapIndex;
				retIt.cur_ = retIt.getNowBuckHead() + newBuckIndex;
			}
			return retIt;
		}
		template<class T>
		deque_iterator<T> operator -(const deque_iterator<T>& it
			, typename deque_iterator<T>::difference_type n) {
			deque_iterator<T> retIt(it);
			auto leftSize = retIt.cur_ - retIt.getNowBuckHead();
			if (leftSize >= n) {//����n������Ȼ�ڵ�ǰͰ��
				retIt.cur_ -= n;
			}
			else {
				n -= leftSize;
				size_t newBuckIndex = n % retIt.getBuckSize() - 1;
				size_t newMapIndex = retIt.mapIndex_ + n / retIt.getBuckSize() + 1;
				retIt.mapIndex_ = newMapIndex;
				retIt.cur_ = retIt.getNowBuckHead() + newBuckIndex;
			}
			return retIt;
		}
	}//end of Detail


	//�ռ�������
	template<class T, class Alloc>
	void deque<T, Alloc>::deallocateABuck(size_t index) {
		dataAllocator::deallocate(map_[index], getBuckSize());
	}
	template<class T, class Alloc>
	void deque<T, Alloc>::__pop_front() {
		STL::destroy(start_.cur_);
		deallocateABuck(start_.mapIndex_);
		start_.mapIndex_ += 1;
		start_.cur_ = start_.getNowBuckHead();
	}
	template<class T, class Alloc>
	void  deque<T, Alloc>::__pop_back() {
		deallocateABuck(finish_.mapIndex_);
		finish_.mapIndex_ -= 1;
		finish_.cur_ = finish_.getNowBuckTail();
		STL::destroy(finish_.cur_);
	}
	template<class T, class Alloc>
	T * deque<T, Alloc>::getANewBuck() {
		return dataAllocator::allocate(getBuckSize());//����ռ�
	}
	template<class T, class Alloc>
	T**  deque<T, Alloc>::GetNewMap(const size_t& size) {
		T **map = new T*[size];
		return map;
	}

	template<class T, class Alloc>
	T ** deque<T, Alloc>::getNewMapAndGetNewBucks(const size_t& size) {

		T **map = mapAllocator::allocate(size);
		for (int i = 0; i != size; ++i) {
			map[i] = getANewBuck();  //ѭ����ȡ����ڵ�
		}
		return map;
	}

	template<class T, class Alloc>
	size_t deque<T, Alloc>::getNewMapSize(const size_t size) {
		return (size == 0 ? 2 : size * 2);
	}
	template<class T, class Alloc>
	void deque<T, Alloc>::__deque(size_t n
		, const value_type& value
		, std::true_type) {
		creat_map_and_nodes(n);
		for (int i = start_.mapIndex_; i < finish_.mapIndex_; ++i) {
			std::uninitialized_fill(map_[i], map_[i] + getBuckSize(), value);
		}
		//���һ��Ͱ�Ĺ���
		std::uninitialized_fill(map_[finish_.mapIndex_], finish_.cur_, value);
	}
	template<class T, class Alloc>
	template<class InputIterator>
	void deque<T, Alloc>::__deque(InputIterator first
		, InputIterator last
		, std::false_type) {
		auto size = last - first;
		creat_map_and_nodes(size);
//		uninitialized_copy(first, last, start_);
		iterator indexIterator = start_;
		for (; first != last; ++first,++indexIterator) {
			STL::construct(indexIterator.cur_, *(first.cur_));
		}

	}	
	template<class T, class Alloc>
	void deque<T, Alloc>::creat_map_and_nodes(size_t num_elements) {
		//����map�ڵ�ռ�
		size_type num_bucks = num_elements / getBuckSize() + 1;
		map_size_ = max(size_type(2), num_bucks + 2);					//�����������
		map_ = mapAllocator::allocate(map_size_);						//����ռ�
		size_type newStartIndex = (map_size_ - num_bucks) / 2;			//ȷ����ʼ����
		size_type newFinishIndex = newStartIndex + num_bucks - 1;		//ȷ��ĩβ����
		
		for (auto i = newStartIndex; i <= newFinishIndex; ++i) {
			map_[i] = getANewBuck();			//ѭ�����뻺������
		}
		start_.mapIndex_ = newStartIndex;
		finish_.mapIndex_ = newFinishIndex;
		start_.cur_ = map_[newStartIndex];									 //ͷָ��λ��
		finish_.cur_ = map_[newFinishIndex] + num_elements % getBuckSize();  //βָ��λ��
		start_.container_ = finish_.container_ = this;
	}
	template<class T, class Alloc>
	void deque<T, Alloc>::reallocateMap(size_t nodes_to_add, bool add_at_front) {
		size_t old_num_mapNodes = finish_.mapIndex_ - start_.mapIndex_ + 1;  //�ɵĽڵ���
		size_t new_num_mapNodes = old_num_mapNodes + nodes_to_add;
		map_Pointer newStart;
		size_t newStartIndex;

		if (map_size_ > 2 * new_num_mapNodes) {		//ʣ��map�ռ仹�кܶ�
			newStartIndex = (map_size_ - new_num_mapNodes) / 2
				+ (add_at_front ? nodes_to_add : 0);
			newStart = map_ + newStartIndex;
			if (newStartIndex < start_.mapIndex_) {
				STL::copy(map_ + start_.mapIndex_, map_ + finish_.mapIndex_, newStart);
			}
			else {
				STL::copy_backward(map_ + start_.mapIndex_, map_ + finish_.mapIndex_, newStart + old_num_mapNodes);
			}
		}
		else {
			size_t new_map_size = map_size_ + max(map_size_, nodes_to_add) + 2;
			//������map�ռ�
			map_Pointer new_map = GetNewMap(new_map_size);
			newStartIndex = (new_map_size - new_num_mapNodes) / 2
				+ (add_at_front ? nodes_to_add : 0);
			newStart = new_map + newStartIndex;
			//����ԭmap������
			STL::copy(map_ + start_.mapIndex_, map_ + finish_.mapIndex_, newStart);
			//�ͷ�ԭmap
			mapAllocator::deallocate(map_);
			//�趨�µ�map�ĵ�ַ�ʹ�С
			map_ = new_map;
			map_size_ = new_map_size;
		}
		start_ = iterator(newStartIndex, start_.cur_, this);
		finish_ = iterator(newStartIndex + old_num_mapNodes - 1, finish_.cur_, this);
	}
	template<class T, class Alloc>
	void  deque<T, Alloc>::__push_back(const value_type& value) {

		//1����������� ��һ������ 
		if (isBackFull()) {//map�������
			reallocateMap(1, false);//��ָ�������ָ��������ȥ�µĸ��������ռ�
		}

		map_[finish_.mapIndex_ + 1] = getANewBuck();//�ڵ�ǰ�����ַԪ�صĺ�һ��Ԫ�ظ�ֵΪ�·�����ڴ�ռ�

		STL::construct(finish_.cur_, value);//����
		++finish_.mapIndex_;//����finish_������λ��
		finish_.cur_ = finish_.getNowBuckHead();//ָ���µ�����Ŀ�ͷ
	}
	template<class T, class Alloc>
	void  deque<T, Alloc>::__push_front(const value_type& value) {
		if (isFrontFull()) {//ǰ��û�л�����
			reallocateMap(1, true);
		}
		map_[start_.mapIndex_ - 1] = getANewBuck();
		--start_.mapIndex_;
		start_.cur_ = start_.getNowBuckTail();
		STL::construct(start_.cur_, value);
	}
	//Ԫ�ط���
	template<class T, class Alloc>
	typename deque<T, Alloc>::reference deque<T, Alloc>::operator[] (size_type n) {
		return *(begin() + n);
	}
	template<class T, class Alloc>
	typename deque<T, Alloc>::const_reference deque<T, Alloc>::operator[] (size_type n) const {
		return *(begin() + n);
	}
	template<class T, class Alloc>
	typename deque<T, Alloc>::reference deque<T, Alloc>::front() {
		return *begin();
	}
	template<class T, class Alloc>
	typename deque<T, Alloc>::reference deque<T, Alloc>::back() {
		return *(end() - 1);
	}
	//���캯�����
	template<class T, class Alloc>
	deque<T, Alloc>::deque(const deque&& rhs) {
		start_ = rhs.start_;
		finish_ = rhs.finish_;
		map_ = rhs.map_;
		map_size_ = rhs.map_size_;
		rhs.start_ = rhs.finish_ = iterator();
		rhs.map_ = nullptr;
		rhs.map_size_ = 0;
	}
	template<class T, class Alloc>
	deque<T, Alloc>::deque()		//1��
		:map_size_(0), map_(nullptr) {			//c++11 ����nullptr
	}

	template<class T, class Alloc>
	deque<T, Alloc>::deque(size_type n, const value_type & value = value_type())
		: map_size_(0), map_(nullptr) {
		__deque(n, value, typename std::is_integral<size_type>::type());
	}
	template<class T, class Alloc>
	template <class InputIterator>
	deque<T, Alloc>::deque(InputIterator first, InputIterator last)
		:map_size_(0), map_(nullptr) {
		__deque(first, last, typename std::is_integral<InputIterator>::type());
	}
	template<class T, class Alloc>
	deque<T, Alloc>::deque(const deque& rhs) {
		deque(rhs.begin(), rhs.end());
	}
	template<class T, class Alloc>
	deque<T, Alloc>::~deque() {
		if (map_ != nullptr) {
			clear();
			dataAllocator::deallocate(map_[start_.mapIndex_]);
			mapAllocator::deallocate(map_, map_size_);
		}
	}

	//Ԫ�ز������
	template<class T, class Alloc>
	void deque<T, Alloc>::push_back(const value_type& value) {

		//1����ʼ���ڵ�
		if (empty()) {
			init();
		}

		//2���жϵ�ǰ�����Ƿ�����
		if (finish_.cur_ != finish_.getNowBuckTail()) {//�����ǰ����û�б�����
			STL::construct(finish_.cur_, value);
			++finish_;
		}
		else {//��ǰ���鱻������
			__push_back(value);
		}

	}
	template<class T, class Alloc>
	void deque<T, Alloc>::pop_back() {
		if (finish_.cur_ != finish_.getNowBuckHead()) {//��ǰ������ǰ�˻���Ԫ��
			--finish_;
			STL::destroy(finish_.cur_);
		}
		else {
			__pop_back();
		}
	}
	template<class T, class Alloc>
	void deque<T, Alloc>::push_front(const value_type& value) {
		if (empty()) {
			init();
		}
		if (start_.cur_ != start_.getNowBuckHead()) {
			--start_;
			STL::construct(start_.cur_, value);
		}
		else {
			__push_front(value);
		}
	}
	template<class T, class Alloc>
	void deque<T, Alloc>::pop_front() {

		//�����ǰ
		if (start_.cur_  != start_.getNowBuckTail()) {
			STL::destroy(start_.cur_);
			++start_;
		}
		else {
			__pop_front();
		}
	}
	template<class T, class Alloc>
	void deque<T, Alloc>::clear() {
		//������ͷβ������֮������л������е�Ԫ���������䶼�Ǳ���״̬��
		for (map_Pointer node = map_ + start_.mapIndex_ + 1; node < map_ + finish_.mapIndex_; ++node) {
			STL::destroy(*node, *(node + getBuckSize()));
			dataAllocator::deallocate(*node, getBuckSize());
		}
		//�ͷ�ͷβ������
		if (start_.mapIndex_ != finish_.mapIndex_) {//������ͷβ����������
			//��������ͷβ������Ԫ��
			STL::destroy(start_.cur_, start_.getNowBuckTail());
			STL::destroy(finish_.getNowBuckHead(), finish_.cur_);

			//�ͷ�β����������������ƣ�������Ҫ����һ��������
			dataAllocator::deallocate(map_[finish_.mapIndex_], getBuckSize());
		}
		else {//ֻ��һ��������
			STL::destroy(start_.cur_, finish_.cur_);
		}
		finish_ = start_;
	}

	//�м����  ���׶˻���ĩ�� ���Ԫ�� ��������ʼλ���� ����λ�õ�Ԫ�أ� ��Ҫ���������д��ָ��λ��
	template<class T, class Alloc>
	int deque<T, Alloc>::insert(unsigned int nIndex, void *pData) {

		if ((start_ + nIndex).cur_ == this->start_.cur_)
		{
			push_front((int)pData);
			return 0;
		}
		else if ((start_ + nIndex).cur_ == this->finish_.cur_)
		{
			push_back((int)pData);
			return 0;
		}
		else
		{
			difference_type __index =/* this->start_;*/nIndex;
			value_type __x_copy = (int)pData;			// XXX copy
			if (static_cast<size_type>(__index) < size() / 2)
			{
				push_front(front());				//��ǰ��� 1
				iterator __front1 = start_;
				--__front1;							//Ŀ������
				iterator __front2 = __front1;
				++__front2;							//��ʼλ��
				//nIndex = this->start_ + __index;	
				iterator __pos1 = start_ + nIndex;	//Ŀ��λ��
				++__pos1;
				STL::copy(__front2, __pos1, __front1);    //�����ֱ�Ϊ��ʵλ�� Ŀ��λ��  ��������

				//++start_;
				return *(start_ + nIndex) = __x_copy;
			}
			return 0;
		}
	}

	//ɾ���м����� �ж���ĩ�˻����׶�ɾ�����ݣ�������ʵλ���� ���� ��ɾ��β����ͷ������
	template<class T, class Alloc>
	void deque<T, Alloc>::erase(unsigned int nIndex) {
		if ((start_ + nIndex).cur_ == this->start_.cur_)
		{
			pop_front();
			return ;
		}
		else if ((start_ + nIndex).cur_ == this->finish_.cur_)
		{
			pop_front();
			return ;
		}
		else
		{
			//n_erase(nIndex,1);

			difference_type __index =nIndex;
		
			for (int i = nIndex; i >0; i--)
			{
				if (i == 1)
				{
					int num = *start_;
					*(start_ + i) = *start_;
					int num1 = *(start_ + i);
					int a=0;
				}
				else
				{
					*(start_ + i) = *(start_ + i - 1);
				}
				
			}
			pop_front();
			return ;
			
		}
		return ;
	}

	template<class T, class Alloc>
	void deque<T, Alloc>::n_erase(unsigned int nFirst, unsigned int nSize) {

		difference_type __index =/* this->start_;*/nFirst;

		if (static_cast<size_type>(__index) < size() / 2)
		{
			for (int i = nFirst; i >0; i--)
			{
				*(start_ + i + nSize-1) = *(start_ + i-1);
			}
			for (int i = 0; i < nSize; i++)
			{
				pop_front();
			}
			//STL::copy(__front2, __pos1, __front1);    //�����ֱ�Ϊ��ʵλ�� Ŀ��λ��  ��������
			return;
		}
	}

	template<class T, class Alloc>
	T deque<T, Alloc>::at(unsigned int pos){

		//return *(begin().cur_-10);

		return *(start_+pos);
	}

	template<class T, class Alloc>
	void deque<T, Alloc>::init() {			//����ǿ�  ��ʼ���ڴ�
		map_size_ = 2;                      //��ʼ������mapָ��

		map_ = getNewMapAndGetNewBucks(map_size_);//��ô�СΪmap_size_��ָ��ռ䲢��Ϊ�����δ������ڴ�ռ�

		//����ʼ��������м�   ����ʼ���ڵ㣩
		start_.container_ = finish_.container_ = this;
		start_.mapIndex_ = finish_.mapIndex_ = map_size_ - 1;
		start_.cur_ = finish_.cur_ = map_[map_size_ - 1];
	}
	template<class T, class Alloc>
	bool deque<T, Alloc>::isBackFull()const {
		return map_[map_size_ - 1] && end().cur_ == (map_[map_size_]);
	}
	template<class T, class Alloc>
	bool deque<T, Alloc>::isFrontFull()const {
		return map_[0] && begin().cur_ == map_[0];
	}

}


#endif // !_DEQUE_DETAIL_H_
