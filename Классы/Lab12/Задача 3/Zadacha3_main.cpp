#include <iostream>
#include "/Users/nikita/Documents/PSTU/Лабы/Lab7/Lab7/Vector.h"

using namespace std;

float findMin(Vector<float>& v)
{
    float min = v[0];
    for (int i = 1; i < v(); ++i)
    {
        if (v[i] < min)
        {
            min = v[i];
        }
    }
    return min;
}

float findMax(Vector<float>& v)
{
    float max = v[0];
    for (int i = 1; i < v(); ++i)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    return max;
}

Vector<float> addToEnd(Vector<float>& v, float value)
{
    Vector<float> result(v() + 1, 0.0f);
    for (int i = 0; i < v(); ++i)
        result[i] = v[i];
    result[v()] = value;
    return result;
}

Vector<float> removeByKey(Vector<float>& v, float key)
{
    int newSize = 0;
    for (int i = 0; i < v(); ++i)
        if (v[i] != key) newSize++;

    Vector<float> result(newSize, 0.0f);
    int j = 0;
    for (int i = 0; i < v(); ++i)
        if (v[i] != key)
            result[j++] = v[i];
    return result;
}

void addSumMinMaxToAll(Vector<float>& v)
{
    float min = findMin(v);
    float max = findMax(v);
    float sum = min + max;

    for (int i = 0; i < v(); ++i)
        v[i] = v[i] + sum;
}

int main()
{
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    Vector<float> v(n, 0.0f);
    cout << "Введите элементы (float):\n";
    cin >> v;

    cout << "\nИсходный вектор:\n" << v << endl;

    float min = findMin(v);
    v = addToEnd(v, min);
    cout << "\nПосле добавления минимального элемента в конец:\n" << v << endl;

    float key;
    cout << "\nВведите элемент для удаления: ";
    cin >> key;
    v = removeByKey(v, key);
    cout << "\nПосле удаления элемента:\n" << v << endl;

    addSumMinMaxToAll(v);
    cout << "\nПосле добавления суммы min + max ко всем элементам:\n" << v << endl;

    return 0;
}
