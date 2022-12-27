#include "BookList.h"

int main()
{

    system("CLS");
    SetConsoleTitle(L"Kursach");
    setlocale(LC_ALL, "Russian");
    ConsoleCursorVisible(false, 100);
    int active_menu = 0;

    BookList* booklist = new BookList;
    BookItem* _head;
    BookItem* newitem;
    int id = 0;

    string Menu[] = {
      "Выход",
      "Очистить список",
      "Добавить книгу в начало списка",
      "Добавить книгу в конец списка",
      "Добавить книгу по индексу",
      "Вывести список книг",
      "Вывести книгу по индексу",
      "Редактировать выбранную книгу (по индексу)",
      "Удалить книгу из начала списка",
      "Удалить книгу из конца списка",
      "Удалить книгу по индексу",
      "Поиск книги по названию",
      "Поиск книги по автору",
      "Сортировать книги по названию (в алфавитном порядке)",
      "Сортировать книги по автору (в алфавитном порядке)",
      "Вывести список в файл",
      "Считать список из файла",

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
                //break;
            case 1:
                system("CLS");
                clearList(booklist);
                cout << "Список был очищен" << endl;
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            case 2:
                system("CLS");
                newitem = new BookItem;
                newitem->data = new Book;
                inputBook(newitem->data);
                addItemHead(booklist, newitem);
                cout << "Элемент был добавлен в список" << endl;
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            case 3:
                system("CLS");
                newitem = new BookItem;
                newitem->data = new Book;
                inputBook(newitem->data);
                addItemTail(booklist, newitem);
                cout << "Элемент был добавлен в список" << endl;
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            case 4:
                system("CLS");
                id = inputInt("Введите ID, на месте которого нужно вставить новую запись: ");
                newitem = new BookItem;
                newitem->data = new Book;
                inputBook(newitem->data);
                addItemByID(booklist, newitem, id);
                cout << "Элемент был добавлен в список" << endl;
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            case 5:
                system("CLS");
                outList(booklist);
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;

            case 6:
                system("CLS");
                id = inputInt("Введите ID элемента списка: ");
                outItemByID(booklist, id);
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
             
            case 7:
                system("CLS");
                id = inputInt("Введите ID элемента списка для редактирования: ");
                updateItemByID(booklist, id);
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            
            case 8:
                system("CLS");
                deleteItemFront(booklist);
                cout << "Элемент был удален из списка" << endl;
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            case 9:
                system("CLS");
                deleteItemTail(booklist);
                cout << "Элемент был удален из списка" << endl;
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            case 10:
                system("CLS");
                id = inputInt("Введите ID элемента списка, который нужно удалить: ");
                deleteItemByID(booklist, id);
                cout << "Элемент был удален из списка" << endl;
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            case 11:
                system("CLS");
                searchBookByTitle(booklist);
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            case 12:
                system("CLS");
                searchBookByAuthor(booklist);
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            case 13:
                system("CLS");
                _head = sortListByTitle(booklist->head);
                booklist->head = _head;
                cout << "Список был отсортирован" << endl;
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            case 14:
                system("CLS");
                _head = sortListByAuthor(booklist->head);
                booklist->head = _head;
                cout << "Список был отсортирован" << endl;
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            case 15:
                system("CLS");
                outListFile(booklist);
                cout << "Список был записан в файл" << endl;
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            case 16:
                system("CLS");
                clearList(booklist);
                readListFile(booklist);
                cout << "Список был прочитан из файла" << endl;
                cout << "Для продолжения работы программы, нажмите любую клавишу ... " << endl;
                _getch();
                system("CLS");
                break;
            }

            break;
        }
    }
}
