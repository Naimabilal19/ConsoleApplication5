#include <iostream>
#include <cstring> 
using namespace std;

class Book
{
	char* name;
	int pages;
public:
	Book(const char* n);
	Book(const char* n, int p); // реализовать делегирование!!!
	void Print();
	~Book();
};

class Student
{
	char* name;
	const double step;// !!
	Book book; //!!!
public:
	Student();
	Student(const char* n, double st, const char* bookName, int bookPages);// использовать инициализаторы!!!
	~Student();
	void Print();

};
Book::Book(const char* n)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

Book::Book(const char* n, int p) :Book(n)
{
	pages = p;
}

void Book :: Print()
{ 
	cout << "Book name: " << name << ",  Pages: " << pages << endl << endl;
}

Book::~Book()
{
	delete[]name;
}

Student::Student():step(0), book(nullptr, 0)
{
	name = nullptr;
}

Student::Student(const char* n, double st, const char* bookName, int bookPages): step(st), book(bookName, bookPages)
{
	if (name != nullptr)
	{
		delete[]name;
	}
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

void Student::Print()
{
	cout << "Student: " << name << "\nStep: " << step << endl;
	book.Print();
}

Student::~Student()
{
	delete[]name;
}
// показать использование объектом в функции main
int main()
{
	Book obj1("Lolita", 400);
	obj1.Print();

	Student obj2("Naima Bilal", 3200, "Lolita", 400);
	obj2.Print();
}