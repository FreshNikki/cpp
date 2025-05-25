#include <iostream>
#include <list>
#include "Time.h"

using namespace std;

bool lessTime(const Time& a, const Time& b)
{
    if (a.get_min() != b.get_min())
        return a.get_min() < b.get_min();
    return a.get_sec() < b.get_sec();
}

bool equalTime(const Time& a, const Time& b)
{
    return a.get_min() == b.get_min() && a.get_sec() == b.get_sec();
}

Time findMin(const list<Time>& lst)
{
    Time minVal = *lst.begin();
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        if (lessTime(*it, minVal)) {
            minVal = *it;
        }
    }
    return minVal;
}

Time findMax(const list<Time>& lst)
{
    Time maxVal = *lst.begin();
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        if (lessTime(maxVal, *it)) {
            maxVal = *it;
        }
    }
    return maxVal;
}

void printList(const list<Time>& lst)
{
    for (auto it = lst.begin(); it != lst.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void addMinToEnd(list<Time>& lst)
{
    if (!lst.empty())
    {
        Time minVal = findMin(lst);
        lst.push_back(minVal);
    }
}

void removeByKey(list<Time>& lst, const Time& key)
{
    for (auto it = lst.begin(); it != lst.end(); )
    {
        if (equalTime(*it, key))
        {
            it = lst.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void addMinMaxToAll(list<Time>& lst)
{
    if (lst.empty()) return;
    Time minVal = findMin(lst);
    Time maxVal = findMax(lst);
    Time sum = minVal + maxVal;

    for (auto& t : lst)
    {
        t = t + sum;
    }
}

int main()
{
    list<Time> lst;
    int n;

    cout << "Введите количество элементов: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        Time t;
        cin >> t;
        lst.push_back(t);
    }

    cout << "\nИсходный список:\n";
    printList(lst);

    addMinToEnd(lst);
    cout << "\nПосле добавления минимального элемента в конец:\n";
    printList(lst);

    cout << "\nВведите элемент для удаления:\n";
    Time key;
    cin >> key;
    removeByKey(lst, key);
    cout << "\nПосле удаления элемента:\n";
    printList(lst);

    addMinMaxToAll(lst);
    cout << "\nПосле добавления (min + max) ко всем элементам:\n";
    printList(lst);

    return 0;
}
