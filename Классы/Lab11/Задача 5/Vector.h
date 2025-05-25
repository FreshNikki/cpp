#pragma once
#include <stack>
#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
    stack<T> data;
    void forEach(void (*func)(T&, T))
    {
        stack<T> tempStack;
        stack<T> original = data;

        while (!original.empty())
        {
            tempStack.push(original.top());
            original.pop();
        }

        while (!tempStack.empty())
        {
            T &elem = tempStack.top();
            func(tempStack.top(), elem);
            tempStack.pop();
        }
    }

public:
    Vector()
    {
        
    }

    void push(T value)
    {
        data.push(value);
    }

    void input(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            T val;
            cin >> val;
            data.push(val);
        }
    }

    void print() const
    {
        stack<T> temp = data;
        stack<T> reverse;
        while (!temp.empty())
        {
            reverse.push(temp.top());
            temp.pop();
        }
        while (!reverse.empty())
        {
            cout << reverse.top() << " ";
            reverse.pop();
        }
        cout << endl;
    }

    T findMin() const
    {
        if (data.empty()) throw runtime_error("Стек пуст!");

        stack<T> temp = data;
        T minVal = temp.top();
        temp.pop();

        while (!temp.empty())
        {
            if (temp.top() < minVal)
                minVal = temp.top();
            temp.pop();
        }
        return minVal;
    }

    T findMax() const
    {
        if (data.empty()) throw runtime_error("Стек пуст!");

        stack<T> temp = data;
        T maxVal = temp.top();
        temp.pop();

        while (!temp.empty())
        {
            if (temp.top() > maxVal)
                maxVal = temp.top();
            temp.pop();
        }
        return maxVal;
    }

    void addMinToEnd()
    {
        T minVal = findMin();
        stack<T> temp;
        while (!data.empty())
        {
            temp.push(data.top());
            data.pop();
        }
        data.push(minVal);

        while (!temp.empty())
        {
            data.push(temp.top());
            temp.pop();
        }
    }

    void removeByKey(T key)
    {
        stack<T> temp;
        while (!data.empty())
        {
            if (data.top() != key)
            {
                temp.push(data.top());
            }
            data.pop();
        }
        while (!temp.empty())
        {
            data.push(temp.top());
            temp.pop();
        }
    }

    void addMinMaxToAll()
    {
        T minVal = findMin();
        T maxVal = findMax();
        T sum = minVal + maxVal;

        stack<T> temp;
        while (!data.empty())
        {
            T val = data.top() + sum;
            data.pop();
            temp.push(val);
        }
        
        while (!temp.empty())
        {
            data.push(temp.top());
            temp.pop();
        }
    }
};
