#include <iostream>

using namespace std;

int interSearch(int arr[], int low, int high, int x)
{
    while (low <= high && x >= arr[low] && x <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == x) return low;
            return -1;
        }
        int pos = low + (((x - arr[low]) * (high - low)) / (arr[high] - arr[low]));
        if (arr[pos] == x) return pos;
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
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
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cout << "Введите число для поиска: " << endl;
    cin >> x;
    int res = interSearch(arr, 0, n - 1, x);
    if (res == -1) cout << "Элемент " << x << " не найдено" << endl;
    else cout << "Элемент " << x << " по индексу " << res << endl;
    return 0;
}
