#include <iostream>
using namespace std;

int strlength(char *str);
void strcatenate(char *str1, char *str2);
char strcopy(char *str2, char *str1);
int strcompare(char *str1, char *str2);





int main()
{
	char *test1 = "Hello";
	char *test2 = "World";
	/* int test1Length = strlength(test1);
	int CompareResult = strcompare(test1, test2);
	
	
	cout << test1Length<<' '<<CompareResult << endl;
	strcatenate(test1, test2); */

	strcopy(test2, test1);
	cout << *test2 << endl;



	return 0;
}

int strlength(char *str)
{
	int i = 0, count = 0;
	for (i = 0; ; i++)
	{
		if (str[i] != '\0')
		{
			count++;
		}
		else
			break;

	}
	return count;
}

void strcatenate(char *str1, char *str2)
{
	cout << str1 << str2 << endl;
	/* 복잡한 방법
	int i = 0;
	char *ResultStr = new char(len1 + len2);
	for (i = 0; i <= (len1 + len2); i++)
	{
	if (i < len1)
	{
	ResultStr[i] = str1[i];
	}
	else if (i >= len1 && i < (len1 + len2))
	{
	ResultStr[i] = str2[i - len1];
	}
	else if (i == (len1 + len2))
	{
	ResultStr[i] = '\0';
	}
	}
	cout << len1 << ' ' << len2 << *ResultStr << endl; */

}

char strcopy(char *str2, char *str1)
{
	
	
	int i = 0;
	int len = strlength(str2);
	for (i = 0; i <= len; i++)
	{
		str2[i] = str1[i];
		if (i == strlength(str2))
		{
			str2[i] = '\0';
		}

	}
	return *str2;

}

int strcompare(char *str1, char *str2)
{
	int i = 0;
	int len1 = strlength(str1);
	int len2 = strlength(str2);

	if (len1 == len2)
		return 0;
	else
		return len1 - len2;


}
