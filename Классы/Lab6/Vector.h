#pragma once
#include <iostream>
using namespace std;

class Iterator
{
private:
    int* ptr;
public:
    Iterator():
    ptr(nullptr) {}
    Iterator(int* p):
    ptr(p) {}
    Iterator operator+(int n)
    {
        return Iterator(ptr + n);
    }
    Iterator& operator++()
    {
        ++ptr;
        return *this;
    }
    int& operator*() const
    {
        return *ptr;
    }
    bool operator!=(const Iterator& other) const
    {
        return ptr != other.ptr;
    }
};

class Vector
{
public:
    Vector (int s, int k = 0);
    Vector (const Vector&a);
    ~Vector ();
    Vector& operator = (const Vector&a);
    int& operator [] (int index);
    Vector operator+ (const Vector& b);
    int operator () ();
    friend ostream& operator << (ostream& out, const Vector&a);
    friend istream& operator >> (istream& in, Vector&a);
    Iterator begin() {return Iterator(data);}
    Iterator end() {return Iterator(data + size);}
private:
    int size;
    int* data;
};

