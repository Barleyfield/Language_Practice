// 오후 8:10 2017-10-19
#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char * title;
	char * isbn;
	int price;
public:
	Book(char * ti, char * is, int pr) : price(pr)
	{
		title = new char[strlen(ti) + 1];
		isbn = new char[strlen(is) + 1];
		strcpy(title, ti);
		strcpy(isbn, is);
	}
	void ShowBookInfo()
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book
{
private:
	char * DRMKey;
public:
	EBook(char * ti, char * is, int pr, char * DRM) : Book(ti, is, pr)
	{
		DRMKey = new char[strlen(DRM) + 1];
		strcpy(DRMKey, DRM);
	}
	void ShowBookInfo()
	{
		Book::ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~EBook()
	{
		delete[] DRMKey;
	}
};

int main()
{
	Book book("좋은 C++", "123-123-123", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ Ebook", "123-123-124", 10000, "7sd89f7a");
	ebook.ShowBookInfo();
	return 0;
}



