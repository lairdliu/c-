#include<iostream>
#include"CString.h"

using namespace std;

int main()
{  
	MyString s1;  
	MyString s2("hello");   
	MyString s3 = "HELLO1111111111111111111111111"; 
	cout << "***** welcome use CString *****"<<endl;

	cout << "s1:" << s1.Mid(0).c_str() << endl;
	cout << "s2:" << s2.Mid(0).c_str() << endl;
	cout << "s3:" << s3.Mid(0).c_str() << endl;

	cout << "s3.GetLength " << s3.GetLength() << endl;

	s3.MakeReverse();
	cout << "s3:" << s3.Mid(0).c_str() << endl;

	s2.MakeUpper();
	cout << "s2:" << s2.Mid(0).c_str() << endl;

	s3.MakeLower();
	cout << "s3:" << s3.Mid(0).c_str() << endl;

	cout << "s3.Compare " << s3.Compare("11111") << endl;

	cout << "s3.CompareNoCase " << s3.CompareNoCase("heLLO") << endl;

	s3.Delete(2,2);
	cout << "s3:" << s3.Mid(0).c_str() << endl;

	s3.Insert(1, "abcdef");		
	cout << "s3:" << s3.Mid(0).c_str() << endl;

	s3.Insert(2, "t");			
	cout << "s3:" << s3.Mid(0).c_str() << endl;

	s3.Remove('t');   
	cout << "s3:" << s3.Mid(0).c_str() << endl;

	s3.Replace("f","g");   //有问题
	cout << "s3:" << s3.Mid(0).c_str() << endl;

	s3.Replace("de", "bbb");   //有问题
	cout << "s3:" << s3.Mid(0).c_str() << endl;

	MyString s4 = " HELLO world ";
	s4.TrimLeft();   
	cout << "s4:" << s4.Mid(0).c_str() << endl;

	s4.TrimLeft('H');  
	s4.printf_test();

	s4.TrimLeft("ELL");   //有问题
	s4.printf_test();

	s4.TrimRight();
	s4.printf_test();

	s4.TrimRight('d');
	s4.printf_test();

	s4.TrimRight("rl");   //有问题
	s4.printf_test();

	s4.Empty();       
	int t = s4.Compare("123");
	s4.printf_test();     //清空后打印字符串将提示无字符（没有问题）
	
	cout << "s4.IsEmpty " << s4.IsEmpty() << endl;

	MyString s5 = " HELLO world     ";

	cout << "s5.Find " << s5.Find('w') << endl;

	cout << "s5.Find " << s5.Find('or') << endl;

	cout << "s5.Find " << s5.Find('o', 2) << endl;

	cout << "s5.Find "<< s5.Find('or', 2) << endl;

	cout << "ReverseFind  "<<s5.ReverseFind('o') << endl;

	cout << "GetAt  " << s5.GetAt(4) << endl;

	s5.SetAt(4,'a');
	s5.printf_test();

	MyString s6 ;
	s6 = s5.Left(5);
	s6.printf_test();
	s6.Empty();

	s6 = s5.Right(4);
	s6.printf_test();
	s6.Empty();

	s6 = s5.Mid(4);
	s6.printf_test();
	s6.Empty();

	s6 = s5.Mid(4,4);
	s6.printf_test();

	cout <<"GetBuffer "<< s5.GetBuffer() << endl;

	s5.GetBufferSetLength(100);
	cout << "GetLength " << s5.GetLength() << endl;

	getchar();
	return 0;
}