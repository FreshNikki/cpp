#include <iostream>
#include <set>

using namespace std;

void printSet (const set<float>& s)
{
    for (float val:s)
    {
        cout << val << " ";
    }
    cout << endl;
}

float findMin(const set<float>& s)
{
    if (!s.empty())
    {
        return *s.begin();
    }
    throw runtime_error("Set is empty");
}

float findMax(const set<float>& s)
{
    if (!s.empty())
    {
        return *s.rbegin();
    }
    throw runtime_error("Set is empty");
}

void addElement(set<float>& s, float element)
{
    s.insert(element);
}

void removeByKey(set<float>& s, float key)
{
    s.erase(key);
}

void addMinMaxToAll(set<float>& s)
{
    if (s.empty()) return;

    float minVal = findMin(s);
    float maxVal = findMax(s);
    float sum = minVal + maxVal;

    set<float> result;
    for (float val : s)
    {
        result.insert(val + sum);
    }

    s = result;
}

int main()
{
    set<float> s;
    int n;

    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите элементы:\n";
    for (int i = 0; i < n; ++i) {
        float val;
        cin >> val;
        s.insert(val);
    }

    cout << "\nИсходное множество:\n";
    printSet(s);

    float minVal = findMin(s);
    addElement(s, minVal);
    cout << "\nПосле добавления минимального элемента:\n";
    printSet(s);

    float key;
    cout << "\nВведите элемент для удаления: ";
    cin >> key;
    removeByKey(s, key);
    cout << "\nПосле удаления элемента:\n";
    printSet(s);

    addMinMaxToAll(s);
    cout << "\nПосле добавления суммы min и max ко всем элементам:\n";
    printSet(s);

    return 0;
}

