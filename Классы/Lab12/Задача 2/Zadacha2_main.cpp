#include <iostream>
#include <set>
#include "/Users/nikita/Documents/PSTU/Лабы/Lab3(class)/Lab3(class)/Time.h"
#inclide "/Users/nikita/Documents/PSTU/Лабы/Lab3(class)/Lab3(class)/Time.cpp"

using namespace std;

bool operator<(const Time& a, const Time& b)
{
    if (a.get_min() == b.get_min())
        return a.get_sec() < b.get_sec();
    return a.get_min() < b.get_min();
}

void printSet(const set<Time>& s)
{
    for (const auto& t : s)
    {
        cout << t << " ";
    }
    cout << endl;
}

Time findMin(const set<Time>& s)
{
    if (!s.empty())
        return *s.begin();
    throw runtime_error("Множество пустое");
}

Time findMax(const set<Time>& s)
{
    if (!s.empty())
        return *s.rbegin();
    throw runtime_error("Множество пустое");
}

void addElement(set<Time>& s, const Time& t)
{
    s.insert(t);
}

void removeByKey(set<Time>& s, const Time& key)
{
    s.erase(key);
}

void addMinMaxToAll(set<Time>& s)
{
    if (s.empty()) return;

    Time min = findMin(s);
    Time max = findMax(s);
    Time sum = min + max;

    set<Time> result;
    for (const auto& t : s)
    {
        result.insert(t + sum);
    }

    s = result;
}

int main()
{
    set<Time> s;
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Time t;
        cin >> t;
        s.insert(t);
    }

    cout << "\nИсходное множество:\n";
    printSet(s);

    Time minVal = findMin(s);
    addElement(s, minVal);
    cout << "\nПосле добавления минимального элемента:\n";
    printSet(s);

    Time key;
    cout << "\nВведите элемент для удаления:\n";
    cin >> key;
    removeByKey(s, key);
    cout << "\nПосле удаления элемента:\n";
    printSet(s);

    addMinMaxToAll(s);
    cout << "\nПосле добавления суммы min и max ко всем элементам:\n";
    printSet(s);

    return 0;
}



