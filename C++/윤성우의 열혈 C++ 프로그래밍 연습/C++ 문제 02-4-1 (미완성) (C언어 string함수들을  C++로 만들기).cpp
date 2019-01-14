#include <iostream>
using namespace std;

int strlength(char *str)
{
	int i = 0, count = 0;
	for (i = 0;   ; i++)
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

char strcopy(char *str)
{
	char *str2[strlength(str)];
	int i = 0;
	for (i = 0; i <= strlength(str); i++)
	{
		str2[i] = str[i];
		
	}
	return *str2;

}


int main()
{
	char *test1 = "Hello";
	cout << strcopy(test1) << endl;
	
	return 0;
}

