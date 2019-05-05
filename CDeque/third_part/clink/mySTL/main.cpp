#include"link.h"
#include<stdlib.h>
#include<iostream>
using namespace std;


struct data
{
	int num;
	//char data[1024];
	
};

void Test1()
{
	int i = 0;
	data *num;
	data *num1;
	data *num2;
	data *num3;
	data *num4;

	CDeque list2;

	CDeque list1; 

	num = new data();
	num->num = 0;
	list2.push_back((void*)num);

	num1 = new data();
	num1->num = 1;
	list2.push_back((void*)num1);

	num2 = new data();
	num2->num = 2;
	list2.push_back((void*)num2);

	num3 = new data();
	num3->num = 3;
	list2.push_back((void*)num3);

	data* num6 = (data*)list2.at(1);
	cout << "list2.at(1):" << num6->num << endl;

	list2.PrintSList();

	list2.pop_back();
	list2.pop_back();

	list2.PrintSList();


	num4 = new data();
	num4->num = 100;

	list2.push_front((void*)num4);

	list2.PrintSList();

	list1 = list2;
	list1.PrintSList();

	list2.pop_front();
	list2.PrintSList();

	list2.push_back((void*)num4);
	list2.push_back((void*)num4);
	list2.push_back((void*)num4);
	list2.push_back((void*)num4);
	list2.push_back((void*)num4);
	list2.PrintSList();

	list2.pop_back();
	list2.PrintSList();
	
	int ret1=list2.size();
	cout <<"list2.size():" <<ret1 << endl;

	i = 100;
	list2.insert(5, (void*)num4);
	list2.PrintSList();

	list2.erase(5);
	list2.PrintSList();

	list2.n_erase(1,3);
	list2.PrintSList();

	list2.clear();
	list2.PrintSList();
	delete num;
	delete num1;
	delete num2;
	delete num3;
	delete num4;
}

int main()
{
	Test1();
	system("pause");
}
