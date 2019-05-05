#include <iostream>
#include <stdbool.h>

using namespace std;
enum BOOL{
	fal = 0,
	tru
};
typedef char TCHAR;

class MyString{

public:
	MyString& operator=(const MyString&);
	const char* c_str();

	MyString();
	MyString(const MyString& stringSrc);
	MyString(char ch, int nRepeat = 1);
	MyString(char* lpch);
	MyString(const char* psz, int nLength);
	~MyString();

	int GetLength() const;
	void MakeReverse();
	void MakeUpper();
	void MakeLower();
	int Compare(char* lpsz) const;
	int CompareNoCase(char* lpsz) const;
	int Delete(int nIndex, int nCount = 1);
	int Insert(int nIndex, char ch);
	int Insert(int nIndex, char* pstr);
	int Remove(char ch);
	int Replace(char chOld, char chNew);
	int Replace(char* lpszOld, char* lpszNew);
	void TrimLeft();
	void TrimLeft(char chTarget);
	void TrimLeft(char* lpszTargets);
	void TrimRight();
	void TrimRight(char chTarget);
	void TrimRight(char* lpszTargets);

	void Empty();
	BOOL IsEmpty() const;
	int Find(char ch) const;
	int Find(char*  lpszSub) const;
	int Find(char ch, int nStart) const;
	int Find(char* pstr, int nStart) const;
	int ReverseFind(char  ch) const;
	TCHAR GetAt(int nIndex) const;
	void SetAt(int nIndex, char  ch);

	MyString Left(int nCount) const;
	MyString Right(int nCount) const;
	MyString Mid(int nFirst) const;
	MyString Mid(int nFirst, int nCount) const;

	char* GetBuffer();
	char* GetBufferSetLength(int nNewLength);
	void printf_test();

private:
	char* p_str;
	size_t  strLength;

	/*char *m_pContent;
	size_t m_nLength;*/
};

