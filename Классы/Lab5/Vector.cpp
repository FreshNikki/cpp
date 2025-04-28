#include "Vector.h"

Vector::Vector (int cap)
{
    capacity = cap;
    size = 0;
    data = new Object*[capacity];
}

Vector::~Vector()
{
    for (int i = 0; i < size; ++i)
    {
        delete data[i];
    }
    delete[] data;
}

void Vector::Add(Object* obj)
{
    if (size < capacity)
    {
        data[size++] = obj;
    }
    else
    {
        cout << "Вектор переполнен!" << endl;
    }
}

void Vector::Show()
{
    for (int i = 0; i < size; ++i)
    {
        if (data[i])
            data[i]->Show();
        cout << endl;
    }
}

