#include "Time.h"

Time::Time()
{
    min = 0; sec = 0;
}

Time::Time(int M, int S)
{
    min = M; sec = S;
}

Time::Time(const Time&t)
{
    min=t.min; sec=t.sec;
}

Time Time::operator = (const Time&t)
{
    if (&t==this) return *this;
    min = t.min; sec=t.sec;
    return *this;
}

Time Time::operator-(const Time&t)
{
    int total1 = min * 60 + sec;
    int total2 = t.min * 60 + t.sec;
    int res = max(0, total1 - total2);
    return Time(res / 60, res % 60);
}

bool Time::operator!=(const Time&t)
{
    return min != t.min || sec != t.sec;
}

void Time::decrease(int m, int s)
{
    int total = min * 60 + sec;
    int dec = m * 60 + s;
    total = max(0, total - dec);
    min = total / 60;
    sec = total % 60;
}

Time::~Time()
{
    
}

ostream& operator << (ostream& out , const Time &t)
{
    out << t.min << ":";
    if (t.sec < 10) out << "0";
    out << t.sec;
    return out;
}

istream& operator >> (istream& in, Time&t)
{
    char colon;
    in >> t.min >> colon >> t.sec;
    return in;
}

fstream& operator >> (fstream &fin, Time&t)
{
    fin >> t.min;
    fin >> t.sec;
    return fin;
}

fstream& operator << (fstream &fout, const Time &t)
{
    fout << t.min << " " << t.sec << "\n";
    return fout;
}

