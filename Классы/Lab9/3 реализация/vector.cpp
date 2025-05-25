#include "vector.h"
#include <iostream>

using namespace std;

Vector::Vector(int cap)
{
    if (cap > MAX_SIZE) throw MaxSizeError();
    size = 0;
    capacity = cap;
    beg = new int[capacity];
}

Vector::~Vector()
{
    delete[] beg;
}

int& Vector::operator[](int index)
{
    if (index < 0) throw IndexError1();
    if (index >= size) throw IndexError2();
    return beg[index];
}

Vector::operator int() const
{
    return size;
}

Vector& Vector::operator+(int n)
{
    if (size + n > capacity) throw MaxSizeError();
    cout << "Введите " << n << " элементов:\n";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ": ";
        cin >> beg[size++];
    }
    return *this;
}

Vector& Vector::operator-(int n)
{
    if (size == 0) throw EmptySizeError();
    if (n > size) size = 0;
    else size -= n;
    return *this;
}

void Vector::Input()
{
    cout << "Введите количество элементов: ";
    int n;
    cin >> n;
    if (n > capacity) throw MaxSizeError();
    cout << "Введите " << n << " элементы:\n";
    for (int i = 0; i < n; ++i) {
        cin >> beg[i];
    }
    size = n;
}

void Vector::Print() const
{
    cout << "Векторные элементы: ";
    for (int i = 0; i < size; ++i)
    {
        cout << beg[i] << " ";
    }
    cout << endl;
}

