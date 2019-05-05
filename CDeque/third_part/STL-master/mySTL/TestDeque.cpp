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
			int i; 	//ʹ��assign()��ֵ  assign�ڼ�����о��Ǹ�ֵ����˼	
			for (i = 0; i < 20; ++i)
			{
				ideq[i] = i;
			}
				
			//���deque	printf("���deque������:\n");	
			for (i = 0; i < 20; ++i)
			{
				cout << ideq[i] << "\t";
			}
			putchar('\n');

			cout << "\n1��push_front ��ӡ��������..." << endl;
			ideq.push_front(100);
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}
			cout << "\n2��push_back ��ӡ��������..." << endl;
			ideq.push_back(100);
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}

			//���deque	
			cout << "\n4��erase��ӡ��������:" << endl;
			ideq.erase(4);
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}
			
			cout << "\n5��n_erase��ӡ��������:" << endl;
			ideq.n_erase(6,2);
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}
			
			cout << "\n5��insert ��ӡ��������..." << endl;
			ideq.insert(3, (void*)50);
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}

			cout << "\n5��pop_front��ӡ��������:" << endl;
			ideq.pop_front();
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}

			cout << "\n6��pop_back��ӡ��������:" << endl;
			ideq.pop_back();
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}

			cout << "\n7������ at:" << endl;
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
			
			cout << "\n9������empty:" << ideq.empty() << endl;
			cout << "\n9������size:" << ideq.size() << endl;

			cout << "\n8������ clear:" << endl;
			ideq.clear();
			for (pos = ideq.begin(); pos != ideq.end(); pos++)
			{
				cout << *pos << "\t";
			}
			

			cout << "\n10������ :" << endl;
			myDeque<int >deq;
			for (int i = 0; i < 10; i++) {
				deq.push_back(i);
			}
			for (pos = deq.begin(); pos != deq.end(); pos++)
			{
				cout << *pos << "\t";
			}

			cout << "\n11������ :" << endl;
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
