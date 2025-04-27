#include "book.h"
#include <iostream>
#include <string>
using namespace std;

Book::Book()
{
    name = "";
    author = "";
    year_of_publication = 0;
    cout << "Конструктор без параметров для объекта" << this << endl;
}

Book::Book (string N, string A, int Y)
{
    name = N;
    author = A;
    year_of_publication = Y;
    cout << "Конструктор с параметрами для объекта" << this << endl;
}

Book::Book(const Book &b)
{
    name = b.name;
    author = b.author;
    year_of_publication =b.year_of_publication;
    cout << "Конструктор копирования для объекта" << this << endl;
}

Book::~Book()
{
    cout << "Деструктор для объекта" << this << endl;
}

string Book::get_name()
{
    return name;
}

string Book::get_author()
{
    return author;
}

int Book::get_year_of_publication()
{
    return year_of_publication;
}

void Book::set_name(string N)
{
    name = N;
}

void Book::set_author(string A)
{
    author = A;
}

void Book::set_year_of_publication(int Y)
{
    year_of_publication = Y;
}

void Book::show()
{
    cout << "Название: " << name << endl;
    cout << "Автор: " << author << endl;
    cout << "Год издания: " << year_of_publication << endl;
}



