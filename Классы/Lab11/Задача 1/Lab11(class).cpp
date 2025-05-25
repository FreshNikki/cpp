#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

void printList(const list<float>& lst)
{
    for (float val : lst)
    {
        cout << val << " ";
    }
    cout << endl;
}

float findMin(const list<float>& lst)
{
    float minVal = *lst.begin();
    for (list<float>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        if (*it < minVal)
        {
            minVal = *it;
        }
    }
    return minVal;
}

float findMax(const list<float>& lst)
{
    float maxVal = *lst.begin();
    for (list<float>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        if (*it > maxVal)
        {
            maxVal = *it;
        }
    }
    return maxVal;
}

void addMinToEnd(list<float>& lst)
{
    if (lst.empty()) return;
    float minVal = findMin(lst);
    lst.push_back(minVal);
}

void removeByKey(list<float>& lst, float key)
{
    const float EPSILON = 1e-6f;
    for (auto it = lst.begin(); it != lst.end(); )
    {
        if (std::abs(*it - key) < EPSILON)
        {
            it = lst.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void addMinMaxToAll(list<float>& lst)
{
    if (lst.empty()) return;
    float minVal = findMin(lst);
    float maxVal = findMax(lst);
    float sum = minVal + maxVal;
    for (auto& val : lst)
    {
        val += sum;
    }
}

int main()
{
    list<float> myList;
    int n;

    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите " << n << " элементов (float):\n";
    for (int i = 0; i < n; ++i)
    {
        float val;
        cin >> val;
        myList.push_back(val);
    }

    cout << "\nИсходный список:\n";
    printList(myList);

    addMinToEnd(myList);
    cout << "\nПосле добавления минимального элемента в конец:\n";
    printList(myList);

    float key;
    cout << "\nВведите элемент для удаления: ";
    cin >> key;
    removeByKey(myList, key);
    cout << "\nПосле удаления элемента " << key << ":\n";
    printList(myList);

    addMinMaxToAll(myList);
    cout << "\nПосле добавления (min + max) ко всем элементам:\n";
    printList(myList);

    return 0;
}
