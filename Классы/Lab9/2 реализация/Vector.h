#pragma once
#include "error.h"
#include <iostream>

using namespace std;

class Vector
{
public:
    Vector();
    Vector(int size);
    ~Vector();
    
    int& operator[] (int index);
    Vector& operator+(int n);
    Vector& operator-(int n);
    operator int() const;
    void Print() const;
    void Input();
private:
    int* data;
    int size;
};
