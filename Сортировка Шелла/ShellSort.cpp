#include <iostream>
using namespace std;

void shellSort(int * arr, int n)
{

    for (int h = n / 2; h > 0; h /= 2)
    {

        for (int i = h; i < n; i++)
        {
            int tmp = arr[i];
            int j;
            for (j = i; j >= h && arr[j - h] > tmp; j -= h)
            {
                arr[j] = arr[j - h];
            }
            arr[j] = tmp;
        }
    }
}

int main()
{
    int m;
    cout << "Введите числа: " << endl;
    cin >> m;
    int arr[m];
    for(int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    cout << "Массив:" << endl;
    for(int i = 0; i < m; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int n = sizeof(arr) / sizeof(arr[0]);
    shellSort(arr, n);
    cout << "Отсортированный:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
