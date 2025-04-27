#include "Time.h"
#include <iostream>
using namespace std;

int main ()
{
    Time t1, t2;
    cout << "Введите первый интервал:\n";
    cin >> t1;
    cout << "Введите второй интервал:\n";
    cin >> t2;
    cout << "\nПервый интервал: " << t1 << endl;
    cout << "Второй интервал: " << t2 << endl;
    Time diff = t1 - t2;
    cout << "\nРазность интервалов: " << diff << endl;
    
    if (t1 != t2)
        cout << "\nИнтервалы разные.\n";
    else
        cout << "\nИнтервалы равные.\n";
    return 0;
}
