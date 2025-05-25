#pragma once
#include "error.h"

const int MAX_SIZE=100;
class Vector
{
    int size;
    int* beg;
    int capacity;
public:
    Vector(int cap = 10);
    ~Vector();
    int& operator[] (int index);
    operator int() const;
    Vector& operator+(int n);
    Vector& operator-(int n);
    void Input();
    void Print() const;
};

