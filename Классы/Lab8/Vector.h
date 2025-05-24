#pragma once
#include "Object.h"

class Vector
{
public:
    Vector(int n = 10);
public:
    ~Vector(void);
    void Add();
    void Del();
    void Show();
    
protected:
    Object**beg;
    int size;
    int cur;
};

