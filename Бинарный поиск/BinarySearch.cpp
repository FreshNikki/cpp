#include <iostream>

using namespace std;

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearchRec(int arr[], int low, int high, int x)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearchRec(arr, low, mid - 1, x);
        return binarySearchRec(arr, mid + 1, high, x);
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
    int res = binarySearch(arr, 0, n - 1, x);
    if (res == -1) cout << "Элемент " << x << " не найдено" << endl;
    else cout << "Элемент " << x << " по индексу " << res << endl;
    int resRec = binarySearchRec(arr, 0, n - 1, x);
    if (resRec == -1) cout << "Элемент " << x << " не найдено" << endl;
    else cout << "Элемент " << x << " по индексу " << resRec << endl;
    
    return 0;
}
