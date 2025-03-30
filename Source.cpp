#include <fstream>
#include "Header.h"

using namespace Nastolki;
using namespace std;

string ni::name() { return _name; }
string ni::vid() { return _vid; }
int ni::vozrast() { return _vozrast; }
string ni::sloznost() { return _sloznost; }
int ni::chislo_people() { return _chislo_people; }
int ni::price() { return _price; }

ni::ni(std::string name, std::string vid, int vozrast, std::string sloznost, int chislo_people, int price, ni* next, ni* first, ni* last, int n) : _name(name), _vid(vid), _vozrast(vozrast), _sloznost(sloznost), _chislo_people(chislo_people), _price(price), _next(next), _first(first), _last(last), _n(n) {}
istream& Nastolki::operator >> (istream& in, ni& p) {
    in >> p._name >> p._vid >> p._vozrast >> p._sloznost >> p._chislo_people >> p._price;
    return in;
}

void Nastolki::push(ni* l, std::string name, std::string vid, int vozrast, std::string sloznost, int chislo_people, int price) {
    ni* ne = new ni(name, vid, vozrast, sloznost, chislo_people, price);
    ne->next = nullptr;
    if (l->n == 0)
    {
        l->first = ne;
    }
    else
    {
        l->last->next = ne;
    }
    l->last = ne;
    l->n++;
}
void Nastolki::load(ni* l, const string igri1)
{
    ifstream file(igri1);
    if (!file.is_open())
    {
        cout << "файл не найден. Создайте новый файл" << endl;
        ofstream newFile(igri1);
        if (!file.is_open())
        {
            cout << "Ошибка! Не удалось создать файл." << endl;
            return;
        }
        file.close();
        return;
    }
    string name, vid, sloznost;
    int vozrast, chislo_people, price;
    while (file >> name >> vid >> vozrast >> sloznost >> chislo_people >> price)
    {
        push(l, name, vid, vozrast, sloznost, chislo_people, price);
    }
    file.close();
}
void Nastolki::save(ni* l, const string igri1)
{
    ofstream file(igri1);
    if (!file.is_open())
    {
        cout << "Ошибка! Не удалось сохранить файл." << endl;
        return;
    }
    ni* current = l->first;
    while (current)
    {
        file << current->name() << " " << current->vid() << " " << current->vozrast() << " " << current->sloznost() << " " << current->chislo_people() << " " << current->price() << endl;
        current = current->next;
    }
    file.close();
}
ni* Nastolki::get(ni* l, int index)
{
    if (index < 0 || index >= l->n)
    {
        return NULL;
    }
    ni* current = l->first;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current;
}
void Nastolki::deletes(ni* l, int index)
{
    if (l->n == 0 || index < 0 || index >= l->n)
    {
        cout << "Неверный индекс." << endl;
        return;
    }
    if (index == 0)
    {
        ni* temp = l->first;
        l->first = temp->next;
        delete(temp);
    }
    else
    {
        ni* prev = get(l, index - 1);
        if (!prev)
        {
            cout << "Товар не найден." << endl;
            return;
        }
        ni* current = prev->next;
        if (current == l->last)
        {
            prev->next = NULL;
            l->last = prev;
        }
        else
        {
            prev->next = current->next;
        }
        delete(current);
    }
    l->n--;
}
void Nastolki::print(ni* l)
{
    ni* current = l->first;
    int index = 0;
    if (l -> first == nullptr) {
        cout << "Товаров нет." << endl;
    }
    while (current)
    {
        cout << "Индекс: " << index << " " << "Имя: " << current->name() << " " << "Вид:  " << current->vid() << " " << "Возраст: " << current->vozrast() << " " << "Сложность: " << current->sloznost() << " " << "Количество игроков:  " << current->chislo_people() << " " << " Цена: " << current->price() << endl;
        current = current->next;
        index++;
    }
}
void Nastolki::search(ni* l, string vid, int min_price)
{
    ni* current = l->first;
    int found = 0;
    while (current)
    {
        if (current->vid().compare(vid) == 0 && current->price() == min_price)
        {
            cout << "Найдено: Имя = " << current->name() << " " << "Цена: " << current->price() << endl;
            found = 1;
        }
        current = current->next;
    }
    if (!found)
    {
        cout << "Товар не найден." << endl;
    }
}
void Nastolki::edit(ni* l, int index)
{
    if (l->n == 0 || index < 0 || index >= l->n)
    {
        cout << "Неверный индекс." << endl;
        return;
    }

    ni* current = get(l, index);
    if (!current)
    {
        cout << "ERROR!" << endl;
        return;
    }
    cout << "Введите Новое имя, Новый тип, Новый минимальный возраст игрока, Новую сложность, Новое количество игроков, Новую цену товара: ";
    cin >> *current;
}
