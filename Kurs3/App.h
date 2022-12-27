#define UP 72
#define DOWN 80
#define ENTER 13
#define APP_H_INCLUDED
#define NOMINMAX

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

using namespace std;


HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GoToXY(short x, short y);
void ConsoleCursorVisible(bool show, short size);


/*********************************************************************/
/*
	user interface
*/
/*********************************************************************/

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
	base functions
*/
/*********************************************************************/


int inputInt(string prompt)
{
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

string inputString(string prompt)
{
	string text = "";
	cout << prompt; // << endl;
	getline(cin, text);
	return text;
}

/*********************************************************************/
/*
	Parse to XLS file
*/
/*********************************************************************/

string inputFilename(string prompt)
{
	string filename = inputString(prompt);
	if (filename == "")
	{
		cout << "Incorrect file name!" << endl;
		inputFilename(prompt);
	}
	else
	{
		return filename;
	}
}

string checkOpenFile()
{
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
		cout << "Не удалось открыть файл для чтения!" << endl;
		cout << ex.what() << endl;
		checkOpenFile();
	}
}

int inputIntFile(ifstream& fin)
{
	string k = "";
	int value = 0;
	if (!fin.eof())
	{
		getline(fin, k);
	}
	if (!(value = stoi(k)))
	{
		value = 0;
	}
	return value;
}

string inputStringFile(ifstream& fin)
{
	string word = "";
	if (!fin.eof())
	{
		getline(fin, word);
	}
	return word;
}
