#pragma once
#include <iostream>
using namespace std;

class Time
{
public:
    Time ();
    Time (int m, int s);
    Time (const Time&t);
    ~Time () = default;
    Time& operator= (const Time& t);
    Time operator+ (const Time& t) const;
    friend ostream& operator << (ostream&out, const Time& t);
    friend istream& operator >> (istream&in, Time& t);
private:
    int min, sec;
};
