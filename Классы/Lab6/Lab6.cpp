#include "Vector.h"
#include <iostream>
using namespace std;

int main ()
{
    Vector v1(5);
    Vector v2(5);
    cout << "Введите элементы первого вектора:\n";
    cin >> v1;
    cout << "Введите элементы второго вектора:\n";
    cin >> v2;
    cout << "\nПервый вектор: " << v1 << endl;
    cout << "\nВторой вектор: " << v2 << endl;
    
    Vector v3 = v1 + v2;
    cout << "\nРезультат сложения векторов: " << v3 << endl;
    cout << "Элемент с индексом 2 в первом векторе: " << v1[2] << endl;
    cout << "Размер первого вектора: " << v1() << endl;
    
    Iterator it = v1.begin();
    Iterator it2 = it + 3;
    cout << "\nЭлемент через итератор +3: " << *it2 << endl;
    return 0;
 }
