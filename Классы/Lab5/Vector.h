#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Vector
{
private:
    Object** data;
    int size;
    int capacity;
public:
    Vector (int cap);
    ~Vector ();
    void Add(Object* obj);
    void Show();
};
