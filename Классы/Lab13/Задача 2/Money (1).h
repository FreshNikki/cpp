#pragma once
#include <iostream>
#include <string>
using namespace std;

class Money
{
public:
    Money();
    Money(long rub, int kop);
    Money(const Money&);
    Money operator=(const Money&);
    Money operator+(const Money&);
    Money operator*(const Money&);
    Money operator*(const int&);
    Money operator/(const Money&);
    Money operator/(const int&);

    bool operator>(const Money& other) const;
    bool operator<(const Money& other) const;

    friend ostream& operator<<(ostream& out, const Money& m);
    friend istream& operator>>(istream& in, Money& m);


private:
    long rubles;
    int kopecks;
    void normalize();
};


