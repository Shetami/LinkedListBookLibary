#include <iostream>

using namespace std;

struct Book{
	int isbn;			//����� ISBN �����;
	string author;		//�����;
	string title;		//��������;
	int year;			//��� �������;
	int count;			//���������� �����������.
};

struct BookItem {
	Book* data = NULL;			// ��������� �� ���������� ��������
	BookItem* next = NULL;		// ��������� �� ��������� �������
	//BookItem* prev = NULL;      // ��������� �� ���������� �������
};

struct BookList {
	BookItem* head = NULL;		// ��������� �� ������ �������
	BookItem* cur = NULL;		// ��������� �� ������� �������
	BookItem* tail = NULL;		// ��������� �� ��������� �������
};

