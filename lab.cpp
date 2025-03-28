#include <locale.h>
#include "Header.h"
using namespace std;
using namespace Nastolki;
int main()
{
    char* locale = setlocale(LC_ALL, "Rus");
    ni* l = new ni("", "", 0, "", 0, 0);
    ni* first = NULL;
    ni* last = NULL;
    ni* n = 0;
    load(l, "igri1");

    int choice;
    string vid;
    int min_price;

    do
    {
        cout << "Меню:" << endl;
        cout << "1. Показать все товары" << endl;
        cout << "2. Добавить новый товар" << endl;
        cout << "3. Удалить товар по индексу" << endl;
        cout << "4. Найти по типу и цене" << endl;
        cout << "5. Редактировать товар по индексу" << endl;
        cout << "6. Выход" << endl;
        cout << "Введите ваш выбор: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            print(l);
            break;
        case 2:
        {
            string name, sloznost, vid;
            int vozrast, chislo_people, price;
            cout << "Введите Имя, Тип, Минимальный возраст игрока, Сложность, Количество игроков, Цену товара: ";
            cin >> name >> vid >> vozrast >> sloznost >> chislo_people >> price;
            push(l, name, vid, vozrast, sloznost, chislo_people, price);
            save(l, "igri1");
        }
        break;
        case 3:
            print(l);
            {
                int index;
                cout << "Введите индекс товара для удаления: ";
                cin >> index;
                deletes(l, index);
                save(l, "igri1");
            }
            break;
        case 4:
            cout << "Введите тип и цену товара: ";
            cin >> vid >> min_price;
            search(l, vid, min_price);
            break;
        case 5:
            print(l);
            {
                int index;
                cout << "Введите индекс товара для редактирования: ";
                cin >> index;
                edit(l, index);
                save(l, "igri1");
            }
            break;
        case 6:
            cout << "Выход...";
            break;
        default:
            cout << "Неверный выбор, введите число от 1 до 6.";
        }
    } while (choice != 6);

    ni* current = l -> first;
    while (current)
    {
        ni* temp = current->next;
        delete (current);
        current = temp;
    }
    return 0;
}


