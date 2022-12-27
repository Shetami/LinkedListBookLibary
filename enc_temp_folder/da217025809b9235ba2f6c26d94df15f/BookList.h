#include "Book.h"

struct BookItem
{
	Book* data = NULL;			// Указатель на содержание элемента
	BookItem* next = NULL;		// Указатель на следующий элемент
};

struct BookList
{
	BookItem* head = NULL;		// Указатель на первый элемент
	BookItem* cur = NULL;		// Указатель на текущий элемент
	BookItem* tail = NULL;		// указатель на последний элемент
};


/******************************/
/*
void addMultipleBook(BookList* list);
void addMultipleBookHead(BookList* list);
void outBook(Book* book);
*/
/******************************/

/*
void addItem(BookList* list);
void outList(BookList* list);
void clearList(BookList* list);
*/
/******************************/
/*
void searchAuthor(BookList* list);
void outputSearchingAuthor(BookList* list);
void outputsearchBook(BookList* list);
*/
/******************************/

//BookItem* sort(BookItem* head);


/*********************************************************************/
/*
	Add functions
*/
/*********************************************************************/

void addItemHead(BookList* list, BookItem* newitem)
{
	if (list->head == NULL)
	{
		list->head = newitem;
		list->tail = newitem;
	}
	else
	{
		newitem->next = list->head;
		list->head = newitem;
	}
}

void addItemTail(BookList* list, BookItem* newitem)
{
	if (list->tail == NULL)
	{
		list->tail = newitem;
		list->head = newitem;
	}
	else
	{
		list->tail->next = newitem;
		list->tail = newitem;
	}
}

void addItemByID(BookList* list, BookItem* newitem, int id)
{
	if (id <= 0)
	{
		cout << "Error! Wrong index" << endl;
		return;
	}
	if (list->tail == NULL)
	{
		list->tail = newitem;
		list->head = newitem;
	}
	else
	{
		int i = 1;
		list->cur = list->head;
		while ((i < id - 1) && (list->cur != list->tail))
		{
			list->cur = list->cur->next;
			i++;
		}
		newitem->next = list->cur->next;
		list->cur->next = newitem;
	}
}

/*
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
*/
/*********************************************************************/
/*
	output functiona
*/
/*********************************************************************/

void outList(BookList* list)
{
	list->cur = list->head;
	int id = 1;
	while (list->cur != NULL)
	{
		cout << id << ": " << endl;
		outputBook(list->cur->data);
		cout << endl; // вывести красивый разделитель между элементами списка
		list->cur = list->cur->next;
		id++;
	}
	//_getch();
}

void outItemByID(BookList* list, int id)
{
	if (id <= 0)
	{
		cout << "Error! Wrong index" << endl;
		return;
	}
	int i = 1;
	list->cur = list->head;
	while ((i < id) && (list->cur != list->tail))
	{
		list->cur = list->cur->next;
		i++;
	}
	if (list->cur != NULL)
	{
		outputBook(list->cur->data);
	}
	//_getch();
}

/*********************************************************************/
/*
	update functiona
*/
/*********************************************************************/

void updateItemByID(BookList* list, int id)
{
	if (id <= 0)
	{
		cout << "Error! Wrong index" << endl;
		return;
	}
	int i = 1;
	list->cur = list->head;
	while ((i < id) && (list->cur != list->tail))
	{
		list->cur = list->cur->next;
		i++;
	}
	if (list->cur != NULL)
	{
		updateBook(list->cur->data);
	}
}


/*********************************************************************/
/*
	Deleting functions
*/
/*********************************************************************/

void deleteItemFront(BookList* list)
{
	if (list->head == NULL)
	{
	}
	else if (list->head == list->tail)
	{
		delete list->tail;
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->cur = list->head->next;
		delete list->head;
		list->head = list->cur;
	}
}

void deleteItemTail(BookList* list)
{
	if (list->head == NULL)
	{
	}
	else if (list->head == list->tail)
	{
		delete list->tail;
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->cur = list->head;
		while (list->cur->next != list->tail)
		{
			list->cur = list->cur->next;
		}
		delete list->tail;
		list->cur->next = NULL;
		list->tail = list->cur;
	}
}

void deleteItemByID(BookList* list, int id)
{
	if (id <= 0)
	{
		cout << "Error! Wrong index" << endl;
		return;
	}
	if (list->head == NULL)
	{
	}
	//else if ((list->head == list->tail) && (id == 1))
	else if (list->head == list->tail)
	{
		delete list->tail;
		list->head = NULL;
		list->tail = NULL;
	}
	else if (id == 1)
	{
		list->cur = list->head->next;
		delete list->head;
		list->head = list->cur;
	}
	else
	{
		int i = 1;
		list->cur = list->head;
		while ((i < id - 1) && (list->cur->next != list->tail))
		{
			list->cur = list->cur->next;
			i++;
		}
		BookItem* deleteitem = list->cur->next;
		list->cur->next = deleteitem->next;
		if (list->tail == deleteitem)
		{
			list->tail = list->cur;
		}
		delete deleteitem;
	}
}

void clearList(BookList* list)
{
	list->cur = list->head;
	while (list->cur != NULL)
	{
		BookItem* deleteitem = list->cur;
		list->cur = list->cur->next;
		delete deleteitem->data;
		delete deleteitem;
	}
	list->head = NULL;
	list->tail = NULL;
}

/*********************************************************************/
/*
	searching functions
*/
/*********************************************************************/

void searchBookByTitle(BookList* list)
{
	string book = "";
	book = inputString("Введите книгу: ");
	list->cur = list->head;
	//Book* result = NULL;
	while (list->cur != NULL)
	{
		if (list->cur->data->title == book)
		{
			outputBook(list->cur->data);
			cout << endl; // можно сделать красивый разделитель между элементами списка
			//result = list->cur->data;
		}
		list->cur = list->cur->next;
	}
/*
	if (result == NULL) {
		cout << "Is no found" << endl;
		return searchBook(list);
	}
	return result;
*/
}

void searchBookByAuthor(BookList* list)
{
	string author = "";
	author = inputString("Введите автора книги: ");
	list->cur = list->head;
	while (list->cur != NULL)
	{
		if (list->cur->data->author == author)
		{
			outputBook(list->cur->data);
			cout << endl; // можно сделать красивый разделитель между элементами списка
		}
		list->cur = list->cur->next;
	}
}

/*
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
*/

/*********************************************************************/
/*
	sorting functions
*/
/*********************************************************************/

BookItem* mergeTitle(BookItem* firstNode, BookItem* secondNode)
{
	BookItem* temp = new BookItem;
	BookItem* merged = temp;

	while ((firstNode != NULL) && (secondNode != NULL))
	{
		int comp = firstNode->data->title.compare(secondNode->data->title);
		if (comp <= 0)
		{
			temp->next = firstNode;
			firstNode = firstNode->next;
		}
		else
		{
			temp->next = secondNode;
			secondNode = secondNode->next;
		}
		temp = temp->next;
	}

	while (firstNode != NULL)
	{
		temp->next = firstNode;
		firstNode = firstNode->next;
		temp = temp->next;
	}

	while (secondNode != NULL)
	{
		temp->next = secondNode;
		secondNode = secondNode->next;
		temp = temp->next;
	}

	temp = merged;
	merged = merged->next;
	delete temp;
	return merged;
}


BookItem* middle(BookItem* head)
{
	BookItem* slow = head;
	BookItem* fast = head->next;

	//while (!slow->next && (!fast && !fast->next))
	while ((slow != NULL) && (slow->next != NULL) && (fast != NULL) && (fast->next != NULL))
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

BookItem* sortListByTitle(BookItem* head)
{
	if (head == NULL)
	{
		return NULL;
	}

	if (head->next == NULL)
	{
		return head;
	}

	BookItem* mid = new BookItem;
	BookItem* head2 = new BookItem;
	mid = middle(head);
	head2 = mid->next;
	mid->next = NULL;
	BookItem* finalhead = mergeTitle(sortListByTitle(head), sortListByTitle(head2));
	return finalhead;
}

/*********************************************************************/
/*
	sorting  by Author
*/
/*********************************************************************/

BookItem* mergeAuthor(BookItem* firstNode, BookItem* secondNode)
{
	BookItem* temp = new BookItem;
	BookItem* merged = temp;

	while ((firstNode != NULL) && (secondNode != NULL))
	{
		int comp = firstNode->data->author.compare(secondNode->data->author);
		if (comp <= 0)
		{
			temp->next = firstNode;
			firstNode = firstNode->next;
		}
		else
		{
			temp->next = secondNode;
			secondNode = secondNode->next;
		}
		temp = temp->next;
	}

	while (firstNode != NULL)
	{
		temp->next = firstNode;
		firstNode = firstNode->next;
		temp = temp->next;
	}

	while (secondNode != NULL)
	{
		temp->next = secondNode;
		secondNode = secondNode->next;
		temp = temp->next;
	}

	temp = merged;
	merged = merged->next;
	delete temp;
	return merged;
}


BookItem* sortListByAuthor(BookItem* head)
{
	if (head == NULL)
	{
		return NULL;
	}

	if (head->next == NULL)
	{
		return head;
	}

	BookItem* mid = new BookItem;
	BookItem* head2 = new BookItem;
	mid = middle(head);
	head2 = mid->next;
	mid->next = NULL;
	BookItem* finalhead = mergeAuthor(sortListByAuthor(head), sortListByAuthor(head2));
	return finalhead;
}

/*********************************************************************/
/*
	File functions
*/
/*********************************************************************/

/*
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
*/

void outListFile(BookList* list)
{
	string path = checkOpenFile();
	ofstream fout;
	//fout.open(path, ios::out);
	fout.open(path);
	cout << "Enter any key ..." << endl;
	_getch();
	list->cur = list->head;
	while (list->cur != NULL)
	{
		outputBookFile(list->cur->data, fout);
		if (list->cur != list->tail)
		{
			fout << endl;
		}
		list->cur = list->cur->next;
	}
	fout.close();
}

void readListFile(BookList* list)
{
	string path = checkOpenFile();
	ifstream fin;
	fin.open(path);
	while (!fin.eof())
	{
		BookItem* newitem = new BookItem;
		newitem->data = new Book;
		readBookFile(newitem->data, fin);
		addItemTail(list, newitem);
		string line;
		if (!fin.eof())
		{
			getline(fin, line);
		}
	}
	fin.close();
}
