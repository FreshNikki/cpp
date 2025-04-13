#include <iostream>

using namespace std;

int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x) return i;
    }
    return -1;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    int m;
    cout << "Введите числа: " << endl;
    cin >> m;
    int arr[m];
    for(int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    cout << "Введите номер, чтобы найти" << endl;
    int x;
    cin >> x;
    int res = search(arr, arrLength, x);
    if (res == -1) cout << "Элемент " << x << " не найдено" << endl;
    else cout << "Элемент " << x << " по индексу " << res << endl;
    return 0;
}
