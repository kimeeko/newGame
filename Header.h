#include <iostream>
#include <string>

namespace Nastolki {
    class ni
    {
        std::string _name;
        std::string _vid;
        int _vozrast;
        std::string _sloznost;
        int _chislo_people;
        int _price;
        ni* _next;
        ni* _first;
        ni* _last;
        int _n;
public:
        ni() = default;
        ni(std::string name, std::string vid, int vozrast, std::string sloznost, int chislo_people, int price, ni* next = nullptr, ni* first = nullptr, ni* last = nullptr, int n = 0);
        std::string name();
        std::string vid();
        int vozrast();
        std::string sloznost();
        int chislo_people();
        int price();
        ni* next;
        ni* first;
        ni* last;
        int n;
        friend std::istream& operator >> (std::istream& in, ni& p);
    };
    void push(ni* l, std::string name, std::string vid, int vozrast, std::string sloznost, int chislo_people, int price);
    void load(ni* l, const std::string igri1);
    void save(ni* l, const std::string igri1);
    ni* get(ni* l, int index);
    void deletes(ni* l, int index);
    void print(ni* l);
    void search(ni* l, std::string vid, int min_price);
    void edit(ni* l, int index);

}
