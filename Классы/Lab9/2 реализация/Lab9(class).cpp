#include "Vector.h"
#include <iostream>

using namespace std;

int main ()
{
    try
    {
        int n;
        cout << "Введите начальный размер вектора: ";
        cin >> n;
        
        Vector v(n);
        v.Input();
        
        cout << "Начальный вектор: ";
        v.Print();
        
        cout << "\nОператор тестирования+ (добавить элементы):\n";
        v = v + 2;
        
        cout << "Вектор после +2 элементов: ";
        v.Print();
        
        cout << "\nОператор тестирования- (удалить элементы):\n";
        v = v - 3;
        
        cout << "Вектор после -3 элементов: ";
        v.Print();
        
        cout << "\nТестирование [] (индексирование):\n";
        cout << "Элемент с индексом 1: " << v[1] << endl;
        cout << "\nТестирование int() (размер): " << int(v) << endl;
    }
    catch (error& e)
    {
        e.what();
    }
    return 0;
}
