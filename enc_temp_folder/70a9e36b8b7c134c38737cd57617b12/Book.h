#include "App.h"

struct Book
{
	int isbn;			//номер ISBN книги;
	string title;		//название;
	string author;		//автор;
	int year;			//год выпуска;
	int count;			//количество экземпляров.
};


void inputBook(Book* book)
{
	//Book* book = new Book;
	cout << "Еnter the book data: " << endl;
	book->isbn = inputInt("isbn: ");
	book->title = inputString("title: ");
	book->author = inputString("author: ");
	book->year = inputInt("year: ");
	book->count = inputInt("count: ");
	//return book;
}


void outputBook(Book* book)
{
	cout << "isbn: " << book->isbn << endl;
	cout << "title: " << book->title << endl;
	cout << "author: " << book->author << endl;
	cout << "year: " << book->year << endl;
	cout << "count: " << book->count << endl;
}

void updateBook(Book* book)
{
	cout << "Update the book data: " << endl;
	cout << "old isbn: " << book->isbn << endl;
	book->isbn = inputInt("new isbn: ");
	cout << "old title: " << book->title << endl;
	book->title = inputString("new title: ");
	cout << "old author: " << book->author << endl;
	book->author = inputString("new author: ");
	cout << "old year: " << book->year << endl;
	book->year = inputInt("new year: ");
	cout << "old count: " << book->count << endl;
	book->count = inputInt("new count: ");
}

void outputBookFile(Book* book, ofstream& fout)
{
	fout << book->isbn << endl;
	fout << book->title << endl;
	fout << book->author << endl;
	fout << book->year << endl;
	fout << book->count << endl;
}

void readBookFile(Book* book, ifstream& fin)
{
	//Book* book = new Book;
	cout << "enter the book data: " << endl;
	book->isbn = inputIntFile(fin);
	book->author = inputStringFile(fin);
	book->title = inputStringFile(fin);
	book->year = inputIntFile(fin);
	book->count = inputIntFile(fin);
	//return book;

}
