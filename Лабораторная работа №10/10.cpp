#include <iostream>
using namespace std;

int main ()
{
    setlocale(LC_ALL, "ru");
    int range_min, range_max;
    int n;
    cout << "Количество чисел в массиве: " << endl;
    cin >> n;
    int* arr = new int[n];
    range_min = 0;
    range_max = 100;
    
    for (int i = 0; i < 100; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
    
    int key;
    cout << "Ведите значение ключа для удаления и добавления: ";
    cin >> key;
    int newSize = 0;
    for (int i =0; i < n; i++)
        if (arr[i] != key)
            newSize++;
    
    int* tmp = new int[newSize];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] != key)
            tmp[j++] = arr[i];
    
    int* app = new int[newSize + 1];
    for (int i = 0; i < newSize; i++)
        app[i] = tmp[i];
    app[newSize] = key;
    newSize++;
    cout << "\nМассив после удаления и добавления ключа: \n";
    for (int i = 0; i < newSize; i++)
        cout << app[i] << " ";
    cout << endl;
    
    delete[] arr;
    delete [] tmp;
    delete [] app;
    return 0;
}
