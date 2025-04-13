#include <algorithm>
#include <iostream>
#include <clocale>

using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int num = 0;

    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] < pivot)
        {
            num++;
        }
    }

    int pos = low + num;
    std::swap(arr[pos], arr[low]);

    int i = low, j = high;
    while (i < pos && j > pos)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < pos && j > pos)
        {
            std::swap(arr[i++], arr[j--]);
        }
    }

    return pos;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high) return;

    int pI = partition(arr, low, high);
    quickSort(arr, low, pI - 1);
    quickSort(arr, pI + 1, high);

   
    for (int i = 0; i <= high; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Массив: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;;
    quickSort(arr, 0, size - 1);
    cout << endl;
    cout << "Отсортированный: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
