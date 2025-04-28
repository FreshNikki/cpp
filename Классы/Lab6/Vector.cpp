#include "Vector.h"

Vector::Vector(int s, int k)
{
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = k;
}

Vector::Vector(const Vector&a)
{
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
}

Vector::~Vector()
{
    delete[] data;
}

Vector& Vector::operator=(const Vector&a)
{
    if (this == &a) return *this;
    delete[] data;
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
    return *this;
}

int& Vector::operator[] (int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Индекс запрещен!" << endl;
        exit(1);
    }
    return data[index];
}

Vector Vector::operator+(const Vector& b)
{
    int minSize;
    if (size < b.size)
        minSize = size;
    else
        minSize = b.size;
    Vector tmp(minSize);
    for (int i = 0; i < minSize; i++)
    {
        tmp.data[i] = data[i] + b.data[i];
    }
    return tmp;
}

int Vector::operator () ()
{
    return size;
}

ostream& operator << (ostream&out, const Vector& a)
{
    for (int i = 0; i < a.size; i++)
        out << a.data[i] << " ";
    return out;
}

istream& operator >> (istream&in, Vector&a)
{
    for (int i = 0; i < a.size; i++)
    {
        cout << "Введите элемент [" << i << "]: ";
        in >> a.data[i];
    }
    return in;
}
