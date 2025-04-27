#include "PAIR.h"

Pair::Pair ()
{
    first = 0;
    second = 0;
}

Pair::~Pair ()
{
    
}

Pair::Pair (int F, int S)
{
    first = F;
    second = S;
}

Pair::Pair (const Pair& pair)
{
    first = pair.first;
    second = pair.second;
}

void Pair::Set_first(int F)
{
    first = F;
}

void Pair::Set_second(int S)
{
    second = S;
}

int Pair::multiply() const
{
    return first * second;
}

Pair& Pair::operator=(const Pair & p)
{
    if (this != &p)
    {
        first = p.first;
        second = p.second;
    }
    return *this;
}

istream& operator >> (istream&in, Pair& p)
{
    cout << "Введите первое число: ";
    in >> p.first;
    cout << "Введите второе число: ";
    in >> p.second;
    return in;
}

ostream& operator << (ostream&out, const Pair& p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

