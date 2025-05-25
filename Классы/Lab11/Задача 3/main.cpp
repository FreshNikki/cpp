#include <iostream>
#include "Vector.h"

using namespace std;

template<typename T>
bool lessThan(const T& a, const T& b)
{
    return a < b;
}

template<typename T>
T findMin(const Vector<T>& v)
{
    int sz = v();
    T minVal = v[0];
    for (int i = 1; i < sz; i++)
    {
        if (lessThan(v[i], minVal))
        {
            minVal = v[i];
        }
    }
    return minVal;
}

template<typename T>
T findMax(const Vector<T>& v)
{
    int sz = v();
    T maxVal = v[0];
    for (int i = 1; i < sz; i++)
    {
        if (lessThan(maxVal, v[i]))
        {
            maxVal = v[i];
        }
    }
    return maxVal;
}

template<typename T>
Vector<T> addElementToEnd(const Vector<T>& v, const T& elem)
{
    int sz = v();
    Vector<T> newV(sz + 1, T());
    for (int i = 0; i < sz; i++)
    {
        newV[i] = v[i];
    }
    newV[sz] = elem;
    return newV;
}

template<typename T>
Vector<T> removeByKey(const Vector<T>& v, const T& key)
{
    int sz = v();
    Vector<T> temp(sz, T());
    int count = 0;
    for (int i = 0; i < sz; i++) {
        if (!(v[i] == key))
        {
            temp[count++] = v[i];
        }
    }
    Vector<T> newV(count, T());
    for (int i = 0; i < count; i++)
    {
        newV[i] = temp[i];
    }
    return newV;
}

template<typename T>
void addMinMaxToAll(Vector<T>& v)
{
    int sz = v();
    if (sz == 0) return;
    T minVal = findMin(v);
    T maxVal = findMax(v);
    T sum = minVal + maxVal;
    for (int i = 0; i < sz; i++)
    {
        v[i] = v[i] + sum;
    }
}

int main()
{
    int n;
    cout << "Введите размер вектора: ";
    cin >> n;

    float defaultValue{};
    Vector<float> v(n, defaultValue);

    cout << "Введите элементы вектора:\n";
    cin >> v;

    cout << "\nИсходный вектор:\n" << v << endl;

    float minVal = findMin(v);
    v = addElementToEnd(v, minVal);
    cout << "\nПосле добавления минимального элемента в конец:\n" << v << endl;

    float key;
    cout << "\nВведите элемент для удаления: ";
    cin >> key;
    v = removeByKey(v, key);
    cout << "\nПосле удаления элемента:\n" << v << endl;

    addMinMaxToAll(v);
    cout << "\nПосле добавления суммы min и max ко всем элементам:\n" << v << endl;

    return 0;
}
