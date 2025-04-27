#include "Time.h"
#include <iostream>
using namespace std;

void Time::normalize()
{
    if (sec >= 60)
    {
        min += sec / 60;
        sec %= 60;
    }
    else if (sec < 0)
    {
        int borrow =(abs(sec) + 59) / 60;
        min -= borrow;
        sec += borrow * 60;
    }
}

Time& Time::operator=(const Time& t)
{
    if (this != &t)
    {
        min = t.min;
        sec = t.sec;
    }
    return *this;
}

Time& Time::operator++()
{
    sec++;
    normalize();
    return *this;
}

Time Time::operator++(int)
{
    Time tmp = *this;
    sec++;
    normalize();
    return tmp;
}

Time Time::operator+(const Time& t)
{
    Time tmp;
    tmp.min = min + t.min;
    tmp.sec = sec + t.sec;
    tmp.normalize();
    return tmp;
}

Time Time::operator-(const Time& t)
{
    Time tmp;
    tmp.min = min - t.min;
    tmp.sec = sec - t.sec;
    tmp.normalize();
    return tmp;
}

bool Time::operator!=(const Time& t) const
{
    return (min != t.min) || (sec != t.sec);
}

istream& operator >> (istream&in, Time& t)
{
    cout << "Введите минуты: ";
    in >> t.min;
    cout << "Введите секунды: ";
    in >> t.sec;
    t.normalize();
    return in;
}

ostream& operator << (ostream&out, const Time& t)
{
    out << t.min << ":";
    if (t.sec < 10)
        out << "0";
    out << t.sec;
    return out;
}
