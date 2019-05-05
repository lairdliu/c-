
#include <iostream>
#include <string>
#include<stdio.h>
#include "Deque.h"

using namespace std;

#if 1
int main()
{
	int de;
	CDeque < int, int,8>  ideq(20, 9);

	//deque<int, alloc, 8> ideq(20, 9);
	//cout << "size=" << ideq.size() << endl;
	/*for (int i = 0; i < ideq.size(); ++i)
		ideq[i] = i;
	​
	for (int i = 0; i < ideq.size(); ++i)
		cout << ideq[i] << ' ';
	cout << endl;
	​
	for (int i = 0; i < 3; i++)
		ideq.push_back(i);
	​
	for (int i = 0; i < ideq.size(); ++i)
		cout << ideq[i] << ' ';
	cout << endl;
	cout << "size=" << ideq.size() << endl;
	​
		ideq.push_back(3);
	for (int i = 0; i < ideq.size(); ++i)
		cout << ideq[i] << ' ';
	cout << endl;
	cout << "size=" << ideq.size() << endl;
	​
		ideq.push_front(99);
	for (int i = 0; i < ideq.size(); ++i)
		cout << ideq[i] << ' ';
	cout << endl;
	cout << "size=" << ideq.size() << endl;
	​
		ideq.push_front(98);
	ideq.push_front(97);
	for (int i = 0; i < ideq.size(); ++i)
		cout << ideq[i] << ' ';
	cout << endl;
	cout << "size=" << ideq.size() << endl;
	​
		deque<int>::iterator it = find(ideq.begin(), ideq.end(), 99);
	cout << *it << endl;

	system("pause");
	*/
	getchar();
	return 0;
}
#endif


#if 0
int main()
{
	Pair<string, int> student("Tom", 19); //实例化出一个类 Pair<string,int>
	cout << student.key << " " << student.value;
	getchar();
	return 0;
}
#endif 