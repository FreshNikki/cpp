#include "PAIR.h"
#include "RECTANGLE.h"
#include <iostream>
using namespace std;

int main ()
{
    Rectangle r1;
    cin >> r1;
    cout << "\nИнформация о прямоугольнике: " << r1 << endl;
    cout << "Площадь: " << r1.area() << endl;
    cout << "Периметр: " << r1.perimeter() << endl;
    return 0;
}
