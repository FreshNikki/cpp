#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 5;
const int COLS = 4;

void Rows(int arr[ROWS][COLS], int row1, int row2)
{
    for (int i = 0; i < COLS; i++)
    {
        int temp = arr[row1][i];
        arr[row1][i] = arr[row2][i];
        arr[row2][i] = temp;
    }
}

void Sort(int arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS - 1; i++)
    {
        for (int j = 0; j < ROWS - i - 1; j++)
        {
            if (arr[j][2] > arr[j + 1][2])
            {
                Rows(arr, j, j + 1);
            }
        }
    }
}

void ArrayRandom(int arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            arr[i][j] = rand() % 99 + 1;
        }
    }
}

void PrintArray(int arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int arr[ROWS][COLS];
    ArrayRandom(arr);
    cout << "Исходный массив:\n";
    PrintArray(arr);
    Sort(arr);
    cout << "\nОтсортированный массив:\n";
    PrintArray(arr);

    return 0;
}
