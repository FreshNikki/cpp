#include "Money.h"

Money::Money() : rubles(0), kopecks(0) {}

Money::Money(long rub, int kop) : rubles(rub), kopecks(kop) { normalize(); }


Money::Money(const Money& other) : rubles(other.rubles), kopecks(other.kopecks) {}

Money Money::operator=(const Money& other)
{
    if (this != &other)
    {
        rubles = other.rubles;
        kopecks = other.kopecks;
    }
    return *this;
}

void Money::normalize()
{
    if (kopecks >= 100 || kopecks < 0)
    {
        rubles += kopecks / 100;
        kopecks = kopecks % 100;

        if (kopecks < 0)
        {
            rubles--;
            kopecks += 100;
        }
    }
}

bool Money::operator>(const Money& other) const
{
    if (rubles > other.rubles) return true;
    if (rubles == other.rubles && kopecks > other.kopecks) return true;
    return false;
}

bool Money::operator<(const Money& other) const
{
    if (rubles < other.rubles) return true;
    if (rubles == other.rubles && kopecks < other.kopecks) return true;
    return false;
}

Money Money::operator+(const Money& m)
{
    long int temp1 = rubles * 100 + kopecks;
    long int temp2 = m.rubles * 100 + m.kopecks;
    Money p;
    p.rubles = (temp1 + temp2) / 100;
    p.kopecks = (temp1 + temp2) % 100;
    return p;
}

Money Money::operator*(const Money& m)
{
    long int temp1 = rubles * 100 + kopecks;
    long int temp2 = m.rubles * 100 + m.kopecks;
    Money p;
    p.rubles = (temp1 * temp2) / 10000;
    p.kopecks = (temp1 * temp2) % 10000;
    return p;
}

Money Money::operator*(const int& t)
{
    long int temp1 = rubles * 100 + kopecks;
    Money p;
    p.rubles = (temp1 * t) / 10000;
    p.kopecks = (temp1 * t) % 10000;
    return p;
}


Money Money::operator/(const Money& m)
{
    long int temp1 = rubles * 100 + kopecks;
    long int temp2 = m.rubles * 100 + m.kopecks;
    Money p;
    p.rubles = (temp1 / temp2) / 100;
    p.kopecks = (temp1 / temp2) % 100;
    return p;
}

Money Money::operator/(const int& t)
{
    long int temp1 = rubles * 100 + kopecks;
    Money p;
    p.rubles = (temp1 / t) / 100;
    p.kopecks = (temp1 / t) % 100;
    return p;
}

ostream& operator<<(ostream& out, const Money& m)
{
    out << "Money: " << m.rubles << "," << (m.kopecks < 10 ? "0" : "") << m.kopecks;
    return out;
}

istream& operator>>(istream& in, Money& m)
{
    char comma;
    cout << "Rubles: ";
    in >> m.rubles;
    cout << "Koples: "; in >> m.kopecks;
    m.normalize();
    return in;
}
