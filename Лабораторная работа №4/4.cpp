#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    int range_min, range_max;
    int n;
    int tmp = 1;
    range_min = 0;
    range_max = 10;
    cout << "Количество чисел в массиве" << endl;
    cin >> n;
    int a[100];

    for (int i = 0; i < 100; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;

    int counter = 0;
    bool flag = false;
    cout << "Массив 1:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            counter = i;
            flag = true;
            break;
        }
    
    }
    if (flag)
    {
        for (int i = counter; i < n; i++)
        {
            a[i] = a[i + 1];
        }
        n = n - 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;
    
    int la = 1;
    int count = 0;
    cout << "Полученный массив:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            count++;
        }
    }
    for (int i = 0; i < n + count; i++)
    {
        if (a[i] % 2 == 0)
        {
            for (int j = n + la; j > i + 1; j--)
            {
                tmp = a[j] = a[i-1] + 2;
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
        if (la < count)
        {
            la++;
        }
    }
    for (int i = 0; i < n + la; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
      
}
