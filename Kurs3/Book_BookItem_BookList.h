#define UP 72
#define DOWN 80
#define ENTER 13
#define APP_H_INCLUDED
#define NOMINMAX

#include "Kurs3.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <conio.h>
#include <cstdio>
#include <windows.h>
#include <ConIO.h>
#include <wincon.h>
#include <iomanip>
#include <fstream>

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GoToXY(short x, short y);
void ConsoleCursorVisible(bool show, short size);

/******************************/

Book* addBook();
void addMultipleBook(BookList* list);
void addMultipleBookHead(BookList* list);
void outBook(Book* book);

/******************************/

void addItem(BookList* list);
void outList(BookList* list);
void clearList(BookList* list);

/******************************/

void searchAuthor(BookList* list);
void outputSearchingAuthor(BookList* list);
void outputsearchBook(BookList* list);

/******************************/

BookItem* sort(BookItem* head);
