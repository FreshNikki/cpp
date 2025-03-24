#include <iostream>
using namespace std;

float mult (int n, float a[])
{
    float result = 1;
    for (int i = 0; i < n; i++)
    {
        result = result * a[i];
    }
    return result;
}


int main ()
{
    setlocale(LC_ALL, "Rus");
    float arr1[] = {3, 2, 4};
    float arr2[] = {7, 1.5, 2.0, 5.0, 0.5};
    float arr3[] = {11.0, 2.0, 3.0};
    cout << "Произведение (3, 2, 4) = " << mult(3, arr1) << endl;
    cout << "Произведение (7, 1.5, 2, 5, 0.5) = " << mult(5, arr2) << endl;
    cout << "Произведение (11, 2, 3) = " << mult(3, arr3) << endl;
    return 0;
}
