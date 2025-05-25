#include <iostream>
#include <stack>

using namespace std;

void findMinMax(stack<float> s, float& minVal, float& maxVal)
{
    if (s.empty()) return;

    minVal = s.top();
    maxVal = s.top();

    while (!s.empty())
    {
        float val = s.top();
        s.pop();
        if (val < minVal) minVal = val;
        if (val > maxVal) maxVal = val;
    }
}

void addElementToBottom(stack<float>& s, float element)
{
    stack<float> tmp;
    while (!s.empty())
    {
        tmp.push(s.top());
        s.pop();
    }
    s.push(element);

    while (!tmp.empty())
    {
        s.push(tmp.top());
        tmp.pop();
    }
}

void removeByKey(stack<float>& s, float key)
{
    stack<float> tmp;
    while (!s.empty())
    {
        if (s.top() != key)
            tmp.push(s.top());
        s.pop();
    }

    while (!tmp.empty())
    {
        s.push(tmp.top());
        tmp.pop();
    }
}

void addMinMaxToAll(stack<float>& s)
{
    float minVal, maxVal;
    findMinMax(s, minVal, maxVal);
    float sum = minVal + maxVal;

    stack<float> tmp;
    
    while (!s.empty())
    {
        float val = s.top() + sum;
        s.pop();
        tmp.push(val);
    }

    while (!tmp.empty())
    {
        s.push(tmp.top());
        tmp.pop();
    }
}

void printStack(stack<float> s)
{
    stack<float> tmp;
    while (!s.empty())
    {
        tmp.push(s.top());
        s.pop();
    }
    while (!tmp.empty())
    {
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << endl;
}

int main()
{
    stack<float> s;
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите элементы:\n";
    for (int i = 0; i < n; ++i) {
        float val;
        cin >> val;
        s.push(val);
    }

    cout << "\nИсходный стек:\n";
    printStack(s);

    float minVal, maxVal;
    findMinMax(s, minVal, maxVal);

    addElementToBottom(s, minVal);
    cout << "\nПосле добавления минимального элемента в конец:\n";
    printStack(s);

    float key;
    cout << "\nВведите ключ для удаления: ";
    cin >> key;
    removeByKey(s, key);
    cout << "\nПосле удаления элемента с ключом:\n";
    printStack(s);

    addMinMaxToAll(s);
    cout << "\nПосле добавления суммы min и max ко всем элементам:\n";
    printStack(s);

    return 0;
}
