#include <iostream>
#include "Banknote.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    Banknote b1(500, 3);
    Banknote b2(1000, 5);
    Banknote b3(3, 7);
    
    cout << "\nИнформация о купюрах:\n";
    b1.printInfo();
    b2.printInfo();
    b3.printInfo();
    return 0;
}
