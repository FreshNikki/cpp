#include "RECTANGLE.h"

Rectangle::Rectangle() : Pair()
{
    
}

Rectangle::Rectangle(int width, int height) : Pair(width, height)
{
    
}

Rectangle::Rectangle(const Rectangle& r) : Pair(r)
{
    
}

int Rectangle::area() const
{
    return first * second;
}

int Rectangle::perimeter() const
{
    return 2 * (first + second);
}

istream& operator >> (istream&in, Rectangle& r)
{
    cout << "Введите ширину прямоугольника: ";
    in >> r.first;
    cout << "Введите высоту прямоугольника: ";
    in >> r.second;
    return in;
}

ostream& operator << (ostream& out, const Rectangle& r)
{
    out << "Ширина: " << r.first << ", Высота: " << r.second;
    return out;
}

void Rectangle::Show ()
{
    cout << "Прямоугольник (ширина = " << first << ", высота = " << second << ")";
}

