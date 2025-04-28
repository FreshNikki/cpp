#include "Object.h"
#include "PAIR.h"
#include "RECTANGLE.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main ()
{
    Rectangle r1;
    cin >> r1;
    cout << "\nИнформация о прямоугольнике: " << r1 << endl;
    cout << "Площадь: " << r1.area() << endl;
    cout << "Периметр: " << r1.perimeter() << endl;
    
    cout << "\n| Работа с вектором объектов |\n";
    Vector v(2);
    Pair* p1 = new Pair(3, 4);
    Rectangle* r2 = new Rectangle(5, 6);
    v.Add(p1);
    v.Add(r2);
    cout << "\nСодержимое вектора:\n";
    v.Show();
    return 0;
}
