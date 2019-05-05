#include<stdio.h>
#include<string>
#include <cassert>

#include "CString.h"

/****************
���ڵ����⣺
1���ַ����ڴ����ò���֣������п��ܷ���Խ�磩
2����������δ�γ�ͬһ���
3�������δ����
4����ֹ���ñ������ַ���ʵ�л����������ڴ�
5��ע������Ҫ����ʵ������
6������ַ�������Ҫ�滻ʱ����Ҫ���ǵ�

****************/

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		if (strLength < other.strLength)
		{
			delete[] p_str;
			p_str = new char[other.strLength + 1];
		}
		strLength = other.strLength;

		memcpy(p_str, other.p_str, other.strLength);

	}			// �������ܻ���������δ�ͷŵĿռ�    
	return *this;
}

const char* MyString::c_str()
{
	return p_str;
}


//ע�⣺
MyString::MyString() :p_str(NULL), strLength(0)
{
	p_str = new char[strLength+1];
	*p_str = '\0';
}

//
MyString::MyString(const MyString& stringSrc)
{
	if (NULL == stringSrc.p_str)
	{
		return;
	}
	strLength = stringSrc.strLength;
	p_str = new char[strLength + 1];
	memcpy(p_str, stringSrc.p_str, strLength);
	p_str[strLength] = '\0';
}

//
MyString::MyString(char ch, int nRepeat)
{
	if (NULL == ch)
	{
		return;
	}
	strLength = nRepeat;
	p_str = new char[strLength + 1];
	for (size_t i = 0; i < strLength; i++)
	{
		p_str[i] = ch;
	}
	p_str[strLength] = '\0';		// ��Ϊstrset��'\0'������     
	cout << p_str << " &&" << endl;
}

//
MyString::MyString(char* lpch)
{
	if (NULL == lpch)
	{
		return;
	}
	strLength = strlen(lpch);
	p_str = new char[strLength + 1];
	memcpy(p_str, lpch, strLength);
	p_str[strLength] = '\0';
}

//
MyString::MyString(const char* psz, int nLength)
{
	if (NULL == psz)
	{
		return;
	}
	strLength = nLength;
	p_str = new char[strLength + 1];
	memcpy(p_str, psz, strLength);
	p_str[strLength] = '\0';
}

//
MyString::~MyString()
{
	delete[] p_str;
	p_str == NULL;
}

int MyString::GetLength() const
{
	return strLength;
}

void MyString::MakeReverse()
{
	char tmp;
	int i;

	//ע�����ַ���
	for (i = 0; i < strLength / 2; i++)		//vc6.0++������ں�����ʼ�����������ͣ���Ȼ�ͻ����г���
	{
		tmp = p_str[i];
		p_str[i] = p_str[strLength - 1 - i];
		p_str[strLength - 1 - i] = tmp;
	}
	return;
}
void MyString::MakeUpper()
{
	int i;
	for (i = 0; i < strLength; i++)//�˴�Ҫ��0��ʼ��������Ϊ�ַ�����һ���ַ���s[0] 
	{
		if (*(p_str + i) >= 65 && *(p_str + i) <= 92)
			*(p_str + i) += 32;
	}
}
void MyString::MakeLower()
{
	int i;
	for (i = 0; i < strLength; i++)//�˴�Ҫ��0��ʼ��������Ϊ�ַ�����һ���ַ���s[0] 
	{
		if (*(p_str + i) >= 97 && *(p_str + i) <= 122)
			*(p_str + i) -= 32;
	}
}
int MyString::Compare(char* lpsz) const
{
	char *p_s = p_str;
	for (; *lpsz == *p_s; ++lpsz, ++p_s)
	{
		if (*lpsz == '\O')    //���
			return(0);
	}
	return((*(unsigned char*)lpsz < *(unsigned char*)p_s) ? -1 : +1); // \0 == 0;
}

int MyString::CompareNoCase(char* lpsz) const
{
	int ch1, ch2;
	char* p_s1 = lpsz;
	char* p_s2 = p_str;
	do {
		ch1 = tolower(*p_s1++);
		ch2 = tolower(*p_s2++);
	} while (ch2 != 0 && ch1 == ch2 && ch1 != 0);
	return ch1 - ch2;
}

//��nIndex��ʼɾ��nCount ���ַ� 
int MyString::Delete(int nIndex, int nCount)
{
	if ((nIndex + nCount) > strLength)
	{
		//throw Outofbond();
	}
	char *p_tmp = p_str;
	strLength -= nCount;
	p_str = new char[strLength + 1];
	for (size_t i = 0; i < nIndex; i++)
	{
		p_str[i] = p_tmp[i];
	}
	for (size_t i = nIndex; i < strLength; i++)
	{
		p_str[i] = p_tmp[i + nCount];
	}
	*(p_str + strLength) = '\0';
	delete[] p_tmp;
	return 0;
}
int MyString::Insert(int nIndex, char ch)
{
	Insert(nIndex, &ch);
	return 0;
}
int MyString::Insert(int nIndex, char* pstr)
{
	if (nIndex < 0 || nIndex >= strLength)
	{
		cout << "not allow insert" << endl;
		return 0;
	}
	char *p_tmp = p_str;
	strLength += strlen(pstr);
	p_str = new char[strLength + 1];

	for (size_t i = 0; i < nIndex; i++)
	{
		*(p_str + i) = *(p_tmp + i);
	}
	for (size_t i = nIndex; i < strLength + 1; i++)
	{
		*(p_str + i) = pstr[i - nIndex];
	}
	for (size_t i = nIndex + strlen(pstr); i < strLength; i++)
	{
		*(p_str + i) = p_tmp[i - strlen(pstr)];
	}
	*(p_str + strLength) = '\0';
	delete[] p_tmp;
	return 0;
}

int MyString::Remove(char ch)
{
	int i = 0, j = 0;
	//ͳ��ָ���ַ��ĸ���
	for (i = 0; i < strLength; i++)
	{
		if (p_str[i] == ch)
		{
			j++;
		}
	}

	char *p_tmp = p_str;
	strLength -= j;
	p_str = new char[strLength + 1];
	for (j = 0,i=0; j < strLength; j++)
	{
		if (p_tmp[j + i] == ch)
		{
			i++;
			j--;
			continue;
		}
		p_str[j] = p_tmp[j+i];
	}

	*(p_str + strLength) = '\0';
	delete[] p_tmp;							//�ɵ��ַ����ռ䣬ʹ�����ͷ�
	return 0;
}

int MyString::Replace(char chOld, char chNew)
{
	if (NULL == chOld)
	{
		return -1;
	}
	for (size_t i = 0; i < strLength; i++)
	{
		if (p_str[i] == chOld)
		{
			p_str[i] = chNew;
		}
	}
	return 0;
}

int MyString::Replace(char* lpszOld, char* lpszNew)
{
	if (Find(lpszOld) == NULL)
	{
		cout << "not find old str" << endl;
		return -1;
	}
	char *p_tmp = p_str;
	strLength = strLength - strlen(lpszOld) + strlen(lpszNew);
	p_str = new char[strLength + 1];

	for (size_t i = 0; i < Find(lpszOld); i++)
	{
		*(p_str + i) = *(p_tmp + i);
	}
	for (size_t i = Find(lpszOld); i < Find(lpszOld) + strlen(lpszNew); i++)
	{
		*(p_str + i) = lpszNew[i - Find(lpszOld)];
	}
	for (size_t i = Find(lpszOld) + strlen(lpszNew); i < strLength; i++)
	{
		*(p_str + i) = p_tmp[i - strlen(lpszOld) + strlen(lpszNew)];
	}
	*(p_str + strLength) = '\0';
	delete[] p_tmp;
	return 0;
}

//ȥ����ߵĿո�
void MyString::TrimLeft()
{
	int i = 0, j = 0;
	char *p_tmp = p_str;
	while (p_str[i] == ' ')
		++i;
	strLength = strLength-i;
	p_str = new char[strLength + 1];

	for (j = 0; j < strLength; j++)
	{
		p_str[j] = p_tmp[j + i];
	}
	*(p_str + strLength) = '\0';
	delete[] p_tmp;
}

//ȥ����ߵ��ַ�
void MyString::TrimLeft(char chTarget)
{
	int i = 0, j = 0;
	char *p_tmp = p_str;
	while (p_str[i] == chTarget)
		++i;
	strLength = strLength - i;
	p_str = new char[strLength + 1];

	for (j = 0; j < strLength; j++)
	{
		p_str[j] = p_tmp[j + i];
	}
	*(p_str + strLength) = '\0';
	delete[] p_tmp;
}

//ȥ����ߵ��ַ���
void MyString::TrimLeft(char* lpszTargets)
{
	if (Find(lpszTargets) == NULL)
	{
		cout << "not find old str" << endl;
		return ;
	}

	int i = 0, j = 0;
	char *p_tmp = p_str;
	i = strlen(lpszTargets);
	strLength = strLength - i;
	p_str = new char[strLength + 1];

	for (j = 0; j < strLength; j++)
	{
		p_str[j] = p_tmp[j + i];
	}
	*(p_str + strLength) = '\0';
	delete[] p_tmp;
}

void MyString::TrimRight()
{
	int i = 0, j = 0;
	char *p_tmp = p_str;
	while (p_str[strLength] == ' ')
		--strLength;
	p_str = new char[strLength + 1];

	for (j = 0; j < strLength; j++)
	{
		p_str[j] = p_tmp[j ];
	}
	*(p_str + strLength) = '\0';
	delete[] p_tmp;
}

void MyString::TrimRight(char chTarget)
{
	int i = 0, j = 0;
	char *p_tmp = p_str;
	while (p_str[strLength] == chTarget)
		--strLength;
	p_str = new char[strLength + 1];

	for (j = 0; j < strLength; j++)
	{
		p_str[j] = p_tmp[j];
	}
	*(p_str + strLength) = '\0';
	delete[] p_tmp;
}

void MyString::TrimRight(char* lpszTargets)
{
	if (Find(lpszTargets) == NULL)
	{
		cout << "not find old str" << endl;
		return;
	}

	int i = 0, j = 0;
	char *p_tmp = p_str;
	i = strlen(lpszTargets);
	strLength = strLength - i;
	p_str = new char[strLength + 1];

	for (j = 0; j < strLength; j++)
	{
		p_str[j] = p_tmp[j];
	}
	*(p_str + strLength) = '\0';
	delete[] p_tmp;
}

void MyString::Empty()
{
	delete[] p_str;
	p_str = NULL;
	strLength = 0;
	//Delete(0, strLength);
}

BOOL MyString::IsEmpty() const
{
	return strLength == 0 ? tru : fal;
}
int MyString::Find(char ch) const
{
	return Find(ch, 0);
}
int MyString::Find(char*  lpszSub) const
{
	return Find(lpszSub, 0);
}
int MyString::Find(char ch, int nStart) const
{
	assert(NULL != ch && nStart < strLength);
	for (size_t i = nStart; i < strLength; i++)
	{
		if (p_str[i] == ch)
			return i;
	}
	return -1;
}
int MyString::Find(char* pstr, int nStart) const
{
	assert(pstr != NULL&&nStart < strLength);
	int i = 0, j = 0, tmp = 0;

	tmp = strlen(pstr);
	char *p_tmp = p_str;
	while (*p_tmp != '\0')
	{
		if (*pstr++ == *p_tmp)
		{
			for (j = 0; j < strlen(pstr); j++)
			{
				if (*pstr != *p_tmp)
				{
					break;
				}
				pstr++;
				p_tmp++;
			}
			if (j == tmp - 1)
			{
				return i;
			}
		}
		i++;
		++p_tmp;
	}
	return NULL;
}

//������� ch
int MyString::ReverseFind(char  ch) const
{
	int i = 0, j = 0;
	i = strLength;
	while (p_str[i] != ch)
	{
		--i;
	}
	return i;
}

//ȡ�ַ�
TCHAR MyString::GetAt(int nIndex) const
{
	return p_str[nIndex];
}

//(���ַ��滻)
void MyString::SetAt(int nIndex, char  ch)
{
	p_str[nIndex] = ch;
}

//ȡ����ַ�
MyString MyString::Left(int nCount) const
{
	int i = 0, j = 0;
	char* pStr = new char[nCount+1];
	for (i = 0; i < nCount; i++)
	{
		pStr[i] = p_str[i];
	}
	pStr[i] = '\0';
	return pStr;
}

//ȡ�ұ��ַ�
MyString MyString::Right(int nCount) const
{
	int i = 0, j = 0;
	char* pStr = new char[strLength - nCount+1];
	for (i = nCount; i < strLength; i++)
	{
		pStr[i - nCount] = p_str[i];
	}
	pStr[strLength - nCount] = '\0';
	return pStr;
}

//ȡ�м��ַ�
MyString MyString::Mid(int nFirst) const
{
	int i = 0, j = 0;
	char* pStr = new char[strLength - nFirst];
	for (i = nFirst; i < strLength; i++)
	{
		pStr[i - nFirst] = p_str[i];
	}
	pStr[i - nFirst] = '\0';
	return pStr;
}

//ȡ�м��ַ����ַ�
MyString MyString::Mid(int nFirst, int nCount) const
{
	int i = 0, j = 0;
	char* pStr = new char[nCount];
	for (i = nFirst; i < nFirst + nCount; i++)
	{
		pStr[i - nFirst] = p_str[i];
	}
	pStr[nCount] = '\0';
	return pStr;
}

//���·����ڴ�,�ڿ���ԭ��������
char* MyString::GetBuffer()
{
	int i = 0, j = 0;
	char* pStr = new char[strLength];
	for (i = 0; i < strLength; i++)
	{
		pStr[i] = p_str[i];
	}
	return pStr;
}

//��ȡ�ռ�
char* MyString::GetBufferSetLength(int nNewLength)
{
	p_str = new char[nNewLength];
	strLength = nNewLength;
	return p_str;
}

void MyString::printf_test()
{
	if (strLength == 0)
	{
		cout << "string is null" << endl;
		return;
	}
	cout << p_str << endl;
}
