#include "Time.h"

Time::Time ()
{
    min = sec = 0;
}

Time::Time (int M, int S)
{
    min = M; sec = S;
}

Time::Time (const Time&t)
{
    min = t.min;
    sec = t.sec;
}

Time& Time::operator=(const Time &t)
{
    if (this != &t)
    {
        min = t.min;
        sec = t.sec;
    }
    return *this;
}

Time Time::operator+(const Time &t) const
{
    int total_sec = (min + t.min) * 60 + sec + t.sec;
    return Time (total_sec / 60, total_sec % 60);
}

ostream& operator << (ostream&out, const Time&t)
{
    out << t.min << ":";
    if (t.sec < 10)
    {
        out << "0";
    }
    out << t.sec;
    return out;
}

istream& operator >> (istream&in, Time&t)
{
    char colon;
    in >> t.min >> colon >> t.sec;
    return in;
}
    
