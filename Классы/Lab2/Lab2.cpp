#include "book.h"
#include <iostream>
#include <string>
using namespace std;

Book make_book()
{
    string n;
    string a;
    int y;
    cout << "Введите название: ";
    cin.ignore();
    getline(cin, n);
    cout << "Введите автора: ";
    getline(cin, a);
    cout << "Введите год издания: ";
    cin >> y;
    Book b(n, a, y);
    return b;
}

void print_book(Book b)
{
    b.show();
}

int main()
{
    Book b1;
    b1.show();
    Book b2=b1;
    b2.show();
    Book b3=b2;
    b3.set_name("Евгений Онегин");
    b3.set_author("А.С.Пушкин");
    b3.set_year_of_publication(1823);
    print_book (b3);
    b1=make_book();
    b1.show();
}

