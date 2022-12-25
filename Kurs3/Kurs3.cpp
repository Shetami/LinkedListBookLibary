#include "App.h"

int main()
{

    system("CLS");
    SetConsoleTitle(L"Kursach");
    setlocale(LC_ALL, "Russian");
    ConsoleCursorVisible(false, 100);
    int active_menu = 0;
    BookItem* _head;
    BookList* booklist = new BookList;

    string Menu[] = {
      "Выход",
      "Добавить книги в начало",
      "Добавить книги по индексу",
      "Добавить книги в конец",
      "Вывести список книг",
      "Поиск по автору",
      "Поиск по названию",
      "Сортировать по названию книги",
      "Сортировать по автору",
      "Удалить книгу из начала",
      "Удалить книгу по индексу",
      "Удалить книгу из конца",
      "Вывести запись по ID",
      "Вывести список в документ",
      "Считать данные из документа",
      "Редактировать выбранную книгу"

    };
    char ch;
    while (true)
    {
        int x = 0, y = 0;
        GoToXY(x, y);
        for (int i = 0; i < size(Menu); i++)
        {
            if (i == active_menu)SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            GoToXY(x, y++);
            cout << Menu[i] << endl;
        }
        ch = _getch();
        if (ch == -32) ch = _getch();
        switch (ch) {
        case UP:
            if (active_menu > 0)
                --active_menu;
            break;
        case DOWN:
            if (active_menu < size(Menu) - 1)
                ++active_menu;
            break;
        case ENTER:
            switch (active_menu)
            {
            case 0:
                clearList(booklist);
                delete booklist;
                exit(0);
            case 1:
                system("CLS");
                addMultipleBookHead(booklist);
                system("CLS");
                break;
            case 2:
                system("CLS");
                addItemID(booklist);
                system("CLS");
                break;
            case 3:
                system("CLS");
                addMultipleBook(booklist);
                system("CLS");
                break;
            case 4:
                system("CLS");
                outList(booklist);
                system("CLS");
                break;

            case 5:
                system("CLS");
                searchAuthor(booklist);
                system("CLS");
                break;
             
            case 6:
                system("CLS");
                outputsearchBook(booklist);
                system("CLS");
                break;
            
            case 7:
                system("CLS");
                _head = sort(booklist->head);
                booklist->head = _head;
                system("CLS");
                break;
            case 8:
                system("CLS");
                _head = sortAuthor(booklist->head);
                booklist->head = _head;
                system("CLS");
                break;
            case 9:
                system("CLS");
                deleteFront(booklist);
                system("CLS");
                break;
            case 10:
                system("CLS");
                deleteID(booklist);
                system("CLS");
                break;
            case 11:
                system("CLS");
                deleteTail(booklist);
                system("CLS");
                break;
            case 12:
                system("CLS");
                outOneItemByID(booklist);
                system("CLS");
                break;
            case 13:
                system("CLS");
                outXLS(booklist);
                system("CLS");
                break;
            case 14:
                system("CLS");
                readFile(booklist);
                system("CLS");
                break;
            case 15:
                system("CLS");
                changeBook(booklist);
                system("CLS");
                break;
            }



            break;
        }
    }


}
