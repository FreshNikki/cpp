#pragma once
#include <iostream>
using namespace std;

template <class T>
class Vector
{
public:
    Vector (int s, T k);
    Vector (const Vector <T>& a);
    ~Vector ();
    Vector& operator= (const Vector<T>&a);
    T&operator [] (int index);
    T operator [] (int index) const;
    Vector operator+ (const Vector<T>&b) const;
    int operator () () const;
    template <class U>
    friend ostream& operator << (ostream& out, const Vector<U>&a);
    template <class U>
    friend istream& operator >> (istream& in, Vector<U>&a);
private:
    int size;
    T*data;
};

template <class T>
Vector<T>::Vector (int s, T k)
{
    size = s;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = k;
}

template <class T>
Vector<T>::Vector (const Vector<T>&a)
{
    size = a.size;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
}

template <class T>
Vector<T>::~Vector()
{
    delete[] data;
}

template <class T>
Vector<T>& Vector<T>::operator= (const Vector<T>&a)
{
    if (this != &a)
    {
        delete[] data;
        size = a.size;
        data = new T[size];
        for (int i = 0; i < size; i++)
            data[i] = a.data[i];
    }
    return *this;
}

template <class T>
T& Vector<T>::operator[] (int index)
{
    return data[index];
}

template <class T>
Vector<T> Vector<T>::operator+ (const Vector<T>& b) const
{
    int minSize;
    if (size < b.size)
    {
        minSize = size;
    }
    else
    {
        minSize = b.size;
    }
    Vector<T> result(minSize, T());
    for (int i = 0; i < minSize; ++i)
    {
        result.data[i] = data[i] + b.data[i];
    }
    return result;
}

template <class T>
int Vector<T>::operator () () const
{
    return size;
}

template <class T>
ostream& operator << (ostream&out, const Vector<T>&a)
{
    for (int i = 0; i < a.size; i++)
        out << a.data[i] << " ";
    return out;
}

template <class T>
istream& operator >> (istream&in, Vector<T>&a)
{
    for (int i = 0; i < a.size; i++)
        in >> a.data[i];
    return in;
}

template <class T>
T Vector<T>::operator [] (int index) const
{
    return data[index];
}
