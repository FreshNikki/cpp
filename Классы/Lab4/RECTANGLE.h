#pragma once
#include "PAIR.h"

class Rectangle :
    public Pair
{
public:
    Rectangle ();
    Rectangle (int width, int height);
    Rectangle (const Rectangle&);
    int area() const;
    int perimeter() const;
    friend istream& operator >> (istream&in, Rectangle& r);
    friend ostream& operator << (ostream&out, const Rectangle& r);
};
