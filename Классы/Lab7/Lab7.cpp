#include "Vector.h"
#include "Time.h"
#include <iostream>
using namespace std;

int main ()
{
    Vector<Time> v1 (3, Time(0, 0));
    Vector<Time> v2 (3, Time(0, 0));
    cout << "Введите 3 временных интервала (минуты:секунды):" << endl;
    cin >> v1;
    cout << "Введите ещё для сложения:" << endl;
    cin >> v2;
    
    cout << "Первый вектор: " << v1 << endl;
    cout << "Второй вектор: " << v2 << endl;
    
    Vector<Time> sum = v1 + v2;
    cout << "Результат сложения: " << sum << endl;
    cout << "Размер вектора: " << sum() << endl;
    return 0;
}
