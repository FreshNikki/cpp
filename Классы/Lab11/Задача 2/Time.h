#pragma once
#include <iostream>
using namespace std;

class Time
{
    int min, sec;
public:
    Time () {min=0; sec=0; };
    Time (int m, int s) {min=m; sec=s; }
    Time (const Time&t) {min=t.min; sec=t.sec; }
    ~Time () {};
    int get_min () const {return min; }
    int get_sec () const {return sec; }
    void set_min (int m) {min = m; }
    void set_sec (int s) {sec = s; }
    Time&operator = (const Time&);
    Time& operator++ ();
    Time operator++ (int);
    Time operator+ (const Time&);
    Time operator- (const Time&);
    bool operator!= (const Time&) const;
    friend istream& operator >> (istream&in, Time&t);
    friend ostream& operator << (ostream&out, const Time&t);
private:
    void normalize();
};
