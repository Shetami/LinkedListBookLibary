#include <iostream>

using namespace std;

struct Book{
	int isbn;			//номер ISBN книги;
	string author;		//автор;
	string title;		//название;
	int year;			//год выпуска;
	int count;			//количество экземпл€ров.
};

struct BookItem {
	Book* data = NULL;			// ”казатель на содержание элемента
	BookItem* next = NULL;		// ”казатель на следующий элемент
	//BookItem* prev = NULL;      // ”казатель на предыдущий элемент
};

struct BookList {
	BookItem* head = NULL;		// ”казатель на первый элемент
	BookItem* cur = NULL;		// ”казатель на текущий элемент
	BookItem* tail = NULL;		// указатель на последний элемент
};

