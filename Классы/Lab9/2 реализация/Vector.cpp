#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector()
{
    size = 0;
    data = nullptr;
}

Vector::Vector(int s)
{
    if (s < 0) throw error("Размер не может быть отрицательным");
    size = s;
    data = new int[size];
    for (int i = 0; i < size; ++i) data[i] = 0;
}

Vector::~Vector()
{
    delete[] data;
}

int& Vector::operator[] (int index)
{
    if (index < 0 || index >= size) throw error("Индекс вне диапозона");
    return data[index];
}

Vector::operator int() const
{
    return size;
}

Vector& Vector::operator+(int n)
{
    if (n < 0) throw error("Нельзя добавить отрицательное количество элементов");
    int* new_data = new int[size + n];
    for (int i = 0; i < size; ++i) new_data[i] = data[i];
    for (int i = size; i < size + n; ++i)
    {
        cout << "Ведите число " << i << ": ";
        cin >> new_data[i];
    }
    delete[] data;
    data = new_data;
    size += n;
    return *this;
}

Vector& Vector::operator-(int n)
{
    if (n < 0) throw error("Нельзя удалить отрицательное количество элементов");
    if (n > size) throw error("Нельзя удалить больше, чем имеется элементов");
    
    int* new_data = new int[size - n];
    for (int i = 0; i < size - n; ++i) new_data[i] = data[i];
    
    delete[] data;
    data = new_data;
    size -= n;
    return *this;
}

void Vector::Input()
{
    for (int i = 0; i < size; ++i)
    {
        cout << "Введите число " << i << ": ";
        cin >> data[i];
    }
}

void Vector::Print() const
{
    for (int i = 0; i < size; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

