#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Time
{
public:
    Time();
    Time (int, int);
    Time (const Time&);
    Time operator = (const Time&);
    Time operator - (const Time&);
    bool operator != (const Time&);
    void decrease(int m, int s);
    friend ostream& operator << (ostream &out, const Time&t);
    friend istream& operator >> (istream &in, Time &t);
    friend fstream& operator >> (fstream &fin, Time &t);
    friend fstream& operator << (fstream &fout, const Time&t);
public:
    ~Time();
private:
    int min;
    int sec;
};

