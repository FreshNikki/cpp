#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    Vector<float> vec;
    cout << "Введите элементы:\n";
    vec.input(n);

    cout << "\nИсходный стек (Vector):\n";
    vec.print();

    vec.addMinToEnd();
    cout << "\nПосле добавления минимального элемента в конец:\n";
    vec.print();

    float key;
    cout << "\nВведите ключ для удаления: ";
    cin >> key;
    vec.removeByKey(key);
    cout << "\nПосле удаления:\n";
    vec.print();

    vec.addMinMaxToAll();
    cout << "\nПосле добавления суммы min и max ко всем элементам:\n";
    vec.print();

    return 0;
}
