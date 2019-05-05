#include"TestDeque.h"
#include<iostream>

using namespace std;

namespace STL {
	namespace testDeque {
		const static Str testStr = "hello deque";
		void myTest()
		{
			deque<int> ideq(20);
			deque<int>::iterator pos;
			int i; 	//使用assign()赋值  assign在计算机中就是赋值的意思	
			for (i = 0; i < 20; ++i)
			{
				ideq[i] = i;
			}
				
			//输出deque	printf("输出deque中数据:\n");	
			for (i = 0; i < 20; ++i)
			{
				cout << ideq[i] << "\t";
			}
			putchar('\n');

			cout << "\n1、push_front 打印基本数据..." << endl;
			ideq.push_front(100);
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}
			cout << "\n2、push_back 打印基本数据..." << endl;
			ideq.push_back(100);
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}

			//输出deque	
			cout << "\n4、erase打印基本数据:" << endl;
			ideq.erase(4);
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}
			
			cout << "\n5、n_erase打印基本数据:" << endl;
			ideq.n_erase(6,2);
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}
			
			cout << "\n5、insert 打印基本数据..." << endl;
			ideq.insert(3, (void*)50);
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}

			cout << "\n5、pop_front打印基本数据:" << endl;
			ideq.pop_front();
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}

			cout << "\n6、pop_back打印基本数据:" << endl;
			ideq.pop_back();
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}

			cout << "\n7、测试 at:" << endl;
			cout << "The second element is " << ideq.at(0) << endl;
			cout << "The first element is " << ideq.at(10) << endl;
			cout << "The second element is " << ideq.at(11) << endl;
			cout << "The second element is " << ideq.at(12) << endl;
			cout << "The first element is " << ideq.at(13) << endl; 
			cout << "The second element is " << ideq.at(14) << endl;
			cout << "The first element is " << ideq.at(15) << endl;
			cout << "The second element is " << ideq.at(16) << endl;
			cout << "The first element is " << ideq.at(17) << endl;
			cout << "The first element is " << ideq.at(18) << endl;
			
			cout << "\n9、测试empty:" << ideq.empty() << endl;
			cout << "\n9、测试size:" << ideq.size() << endl;

			cout << "\n8、测试 clear:" << endl;
			ideq.clear();
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}
			

			cout << "\n10、测试 :" << endl;
			myDeque<int >deq;
			for (int i = 0; i < 10; i++) {
				deq.push_back(i);
			}
			for (pos = deq.begin(); pos != deq.end(); pos++)
			{
				cout << *pos << "\t";
			}

			cout << "\n11、测试 :" << endl;
			deque<Str>::iterator pos1;
			myDeque<Str >deqStr;
			for (int i = 0; i < 10; i++) {
				deqStr.push_back(testStr);
			}
			
			for (pos1 = deqStr.begin(); pos1 != deqStr.end(); pos1++)
			{
				cout << *pos1 << "\t";
			}
			putchar('\n');
			return ;
		}

	}
}
