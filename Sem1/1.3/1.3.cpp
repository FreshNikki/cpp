#include <iostream>
using namespace std;
float a;
int main()
{
    cin >>a;
    if (a<5)
    {
        cout << a*3 << endl;
    }
    if (a>7)
    {
        cout << a+3 << endl;
    }
    else
    {
        cout << a/10 <<endl;
    }
    return 0;
}
