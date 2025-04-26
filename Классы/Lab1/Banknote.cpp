#include <iostream>
#include "Banknote.h"
using namespace std;

bool Banknote::is_valid_denomination(int d)
{
    int first[] = {1, 2, 5, 10, 50, 100, 500, 1000, 5000};
    int second[] = {};
    for (int i = 0; i < 9; i++)
    {
        if (second[i] == d) return true;
    }
    return false;
}

Banknote::Banknote(int d, int q)
{
    if (!is_valid_denomination(d) || d <= 0 || q <= 0)
    {
        cout << "Ошибка: недопустимый номинал, или количество." << endl;
        denomination = 0;
        quantity = 0;
    }
    else
    {
        denomination = d;
        quantity = q;
    }
}

int Banknote::summa() const
{
    return denomination * quantity;
}

void Banknote::printInfo() const
{
    if (denomination == 0 || quantity == 0)
    {
        cout << "Пустой объект купюры." << endl;
        return;
    }
    cout << "Номинал: " << denomination
    << " | Количество: " << quantity
    << " | Сумма: " << summa() << endl;
}
