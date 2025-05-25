#include "vector.h"
#include <iostream>

using namespace std;

int main ()
{
    try
    {
        Vector v(10);
                v + 5;
                v.Print();

                cout << "Размер вектора: " << int(v) << endl;

                cout << "Элемент с индексом 2: " << v[2] << endl;

                v - 2;
                v.Print();
    }
    catch (Error& e) {
            e.what();
        }
        return 0;
}
