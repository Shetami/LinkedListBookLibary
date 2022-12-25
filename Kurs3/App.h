#include "Book_BookItem_BookList.h"


/*********************************************************************/
/*
	user interface
*/
/*********************************************************************/

string inputString(string prompt) {
	string text;
	cout << prompt;
	getline(cin, text);
	return text;
}

int inputInt(string prompt) {
	int value = 0;
	cout << prompt;
	if (!(cin >> value)) {
		cout << "Incorrect number!\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		inputInt(prompt);
	}
	else {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return value;
	}
}

Book* addBook() {
	Book* book = new Book;
	cout << "enter the book data: " << endl;
	book->isbn = inputInt("isbn: ");
	book->author = inputString("author: ");
	book->title = inputString("title: ");
	book->year = inputInt("year: ");
	book->count = inputInt("count: ");

	return book;

}

void outBook(Book* book) {
	cout << "isbn: " << book->isbn << endl;
	cout << "author: " << book->author << endl;
	cout << "title: " << book->title << endl;
	cout << "year: " << book->year << endl ;
	cout << "count: " << book->count << endl;
}

void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}
void ConsoleCursorVisible(bool show, short size)
{

	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	structCursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);

}

/*********************************************************************/
/*
	Base function
*/
/*********************************************************************/

void addItem(BookList* list) {
	BookItem* newitem = new BookItem;
	newitem->data = addBook();
	if (list->tail == NULL) {
		list->tail = newitem;
		list->head = newitem;
	}
	else {
		list->tail->next = newitem;
		list->tail = newitem;
	}
	cout << endl;
}

void addItemHead(BookList* list) {
	BookItem* newitem = new BookItem;
	newitem->data = addBook();
	if (list->head == NULL) {
		list->tail = newitem;
		list->head = newitem;
	}
	else {
		newitem->next=list->head;
		list->head = newitem;
	}
}

void addItemID(BookList* list) {
	int id = inputInt("Введите ID после которго нужно вставить запись: ");
	BookItem* newitem = new BookItem;
	newitem->data = addBook();
	if (list->tail == NULL) {
		list->tail = newitem;
		list->head = newitem;
	}
	else {
		int i = 1;
		list->cur = list->head;
		while ((i < id) || (id <= 0)) {
			list->cur = list->cur->next;
			i++;
		}
		newitem->next = list->cur->next;
		list->cur->next = newitem;
	}
}

void addMultipleBookHead(BookList* list) {
	int count = inputInt("Колличество добавляемых книг: ");
	cout << "enter the list: " << endl << endl;
	for (int i = 0; i < count; i++) {
		addItemHead(list);
	}
}

void addMultipleBook(BookList* list) {
	int count = inputInt("Колличество добавляемых книг: ");
	cout << "enter the list: " << endl << endl;
	for (int i = 0; i < count; i++) {
		addItem(list);
	}
}

void addMultipleBookID(BookList* list) {

}

void outList(BookList* list) {
	list->cur = list->head;
	int id = 1;
	while (list->cur != NULL) {
		cout << id << endl;
		outBook(list->cur->data);
		cout << endl;
		list->cur = list->cur->next;
		id++;
	}
	_getch();
}

void clearList(BookList* list) {
	list->cur = list->head;
	while (list->cur != NULL) {
		list->head = list->cur->next;
		delete list->cur->data;
		delete list->cur;
		list->cur = list->head;
	}
	list->tail = NULL;
}

void outOneItemByID(BookList* list) {
	int id = inputInt("Введите ID книги: ");
	int i = 1;
	list->cur = list->head;
	while ((i < id) || (id <= 0)) {
		list->cur = list->cur->next;
		i++;
	}
	outBook(list->cur->data);
	_getch();
}

void changeBook(BookList* list) {
	int id = inputInt("Введите ID книги: ");
	if (id <= 0) {
		cout << "Неверное значение" << endl;
		_getch();
		changeBook(list);
	}
	int i = 1;
	list->cur = list->head;
	while ((i < id) || (id <= 0)) {
		list->cur = list->cur->next;
		i++;
	}

	cout << "enter the book data: " << endl;
	list->cur->data->isbn = inputInt("isbn: ");
	list->cur->data->author = inputString("author: ");
	list->cur->data->title = inputString("title: ");
	list->cur->data->year = inputInt("year: ");
	list->cur->data->count = inputInt("count: ");
}

/*********************************************************************/
/*
	searching Author
*/
/*********************************************************************/

void searchAuthor(BookList* list) {
	string author = "";
	author = inputString("Введите автора: ");
	list->cur = list->head;
	while (list->cur != NULL) {
		if (list->cur->data->author == author) {
			cout << "isbn: " << list->cur->data->isbn << endl;
			cout << "author: " << list->cur->data->author << endl;
			cout << "title: " << list->cur->data->title << endl;
			cout << "year: " << list->cur->data->year << endl;
			cout << "count: " << list->cur->data->count << endl;
			cout << "================" << endl;
		}
		list->cur = list->cur->next;
	}
	_getch();
}

/*********************************************************************/
/*
	searching Book
*/
/*********************************************************************/

Book* searchBook(BookList* list) {
	string book = "";
	book = inputString("Введите книгу: ");
	list->cur = list->head;
	Book* result = NULL;
	while (list->cur != NULL) {
		if (list->cur->data->title == book) {
			result = list->cur->data;
		}
		list->cur = list->cur->next;
	}
	if (result == NULL) {
		cout << "Is no found" << endl;
		return searchBook(list);
	}
	return result;
}

void outputsearchBook(BookList* list) {
	Book a = *searchBook(list);
	cout << "isbn: " << a.isbn << endl;
	cout << "author: " << a.author << endl;
	cout << "title: " << a.title << endl;
	cout << "year: " << a.year << endl;
	cout << "count: " << a.count << endl;
	cout << "================" << endl;

	_getch();
}

/*********************************************************************/
/*
	sorting on Book name
*/
/*********************************************************************/

BookItem* merge(BookItem* firstNode, BookItem* secondNode)
{
	BookItem* merged = new BookItem;
	BookItem* temp = new BookItem;

	merged = temp;

	while (firstNode != NULL && secondNode != NULL) {
		int comp = firstNode->data->title.compare(secondNode->data->title);
		if (comp <= 0) {
			temp->next = firstNode;
			firstNode = firstNode->next;
		}

		else {
			temp->next = secondNode;
			secondNode = secondNode->next;
		}
		temp = temp->next;
	}


	while (firstNode != NULL) {
		temp->next = firstNode;
		firstNode = firstNode->next;
		temp = temp->next;
	}

	while (secondNode != NULL) {
		temp->next = secondNode;
		secondNode = secondNode->next;
		temp = temp->next;
	}

	return merged->next;
}


BookItem* middle(BookItem* head)
{
	BookItem* slow = head;
	BookItem* fast = head->next;

	while (!slow->next && (!fast && !fast->next)) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


BookItem* sort(BookItem* head)
{

	if (head->next == NULL) {
		return head;
	}

	BookItem* mid = new BookItem;
	BookItem* head2 = new BookItem;
	mid = middle(head);
	head2 = mid->next;
	mid->next = NULL;
	BookItem* finalhead = merge(sort(head), sort(head2));
	return finalhead;
}

/*********************************************************************/
/*
	sorting on author Author
*/
/*********************************************************************/

BookItem* mergeAuthor(BookItem* firstNode, BookItem* secondNode)
{
	BookItem* merged = new BookItem;
	BookItem* temp = new BookItem;

	merged = temp;

	while (firstNode != NULL && secondNode != NULL) {
		int comp = firstNode->data->author.compare(secondNode->data->author);
		if (comp <= 0) {
			temp->next = firstNode;
			firstNode = firstNode->next;
		}

		else {
			temp->next = secondNode;
			secondNode = secondNode->next;
		}
		temp = temp->next;
	}


	while (firstNode != NULL) {
		temp->next = firstNode;
		firstNode = firstNode->next;
		temp = temp->next;
	}

	while (secondNode != NULL) {
		temp->next = secondNode;
		secondNode = secondNode->next;
		temp = temp->next;
	}

	return merged->next;
}


BookItem* sortAuthor(BookItem* head)
{

	if (head->next == NULL) {
		return head;
	}

	BookItem* mid = new BookItem;
	BookItem* head2 = new BookItem;
	mid = middle(head);
	head2 = mid->next;
	mid->next = NULL;
	BookItem* finalhead = mergeAuthor(sortAuthor(head), sortAuthor(head2));
	return finalhead;
}

/*********************************************************************/
/*
	sorting on author Author
*/
/*********************************************************************/

void deleteFront(BookList* list) {
	list->cur = list->head->next;
	delete list->head;
	list->head = list->cur;
}

void deleteID(BookList* list) {
	int id = inputInt("Введите ID записи которую нужно удалить: ");
	int i = 1;
	list->cur = list->head;
	while ((i < id) || (id <= 0)) {
		list->cur = list->cur->next;
		i++;
	}

}

void deleteTail(BookList* list) {
	list->tail = list->head;
	bool single = true;
	while (list->tail->next != NULL) {
		list->cur = list->tail;
		list->tail = list->tail->next;
		single = false;
	}
	if (single == false) {
		delete list->tail;
		list->tail = list->cur;
		list->tail->next = nullptr;
	}
	else {
		delete list->head;
		list->head = list->tail = nullptr;
	}
	
}

/*********************************************************************/
/*
	Parse to XLS file
*/
/*********************************************************************/

string inputFilename(string prompt) {
	string filename = inputString(prompt);
	if (filename == "") {
		cout << "Incorrect file name!" << endl;
		inputFilename(prompt);
	}
	else {
		return filename;
	}
}

string checkOpenFile() {
	string path = inputFilename("Введите имя файла: ");
	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);
	try
	{
		fin.open(path);
		fin.close();
		return path;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
		cout << "Не удалось открыть файл для чтения!" << endl;
		checkOpenFile();
	}
}

int inputIntFile(ifstream& fin) {
	string k = "";
	int value = 0;
	if (!fin.eof())
	{
		getline(fin, k);
	}
	if (!(value = stoi(k)))
	{
		return value;
	}
}

string inputStringFile(ifstream& fin) {
	string word = "";
	if (!fin.eof())
	{
		getline(fin, word);
	}
	return word;
}

Book* addBookFile(ifstream& fin) {
	Book* book = new Book;
	cout << "enter the book data: " << endl;
	book->isbn = inputIntFile(fin);
	book->author = inputStringFile(fin);
	book->title = inputStringFile(fin);
	book->year = inputIntFile(fin);
	book->count = inputIntFile(fin);

	return book;

}

void addItemFile(BookList* list, ifstream& fin) {
	BookItem* newitem = new BookItem;
	newitem->data = addBookFile(fin);
	if (list->tail == NULL) {
		list->tail = newitem;
		list->head = newitem;
	}
	else {
		list->tail->next = newitem;
		list->tail = newitem;
	}
	cout << endl;
}

void readFile(BookList* list) {
	ifstream fin;
	string path = checkOpenFile();
	fin.open(path);
	while (!fin.eof())
	{
		addItemFile(list, fin);
		string line;
		if (!fin.eof())
		{
			getline(fin, line);
		}
	}

	fin.close();

}

void outXLS(BookList* list) {
	fstream f;
	string path = checkOpenFile();
	f.open(path, ios::out);
	list->cur = list->head;
	f << "ISBN" << "\t" << "Author" << "\t" << "Book title" << "\t" << "Year" << "\t" << "Count" << "\t" << endl;
	while (list->cur != NULL) {
		f << list->cur->data->isbn << "\t" << list->cur->data->author << "\t" << list->cur->data->title << "\t" << list->cur->data->year << "\t" << list->cur->data->count << "\t" << endl;
		list->cur = list->cur->next;
	}

	f.close();
	
}