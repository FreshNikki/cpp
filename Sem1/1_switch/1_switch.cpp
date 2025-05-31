#include <iostream>
using namespace std;
int main ()
{
    float f,s;
    int v;
    cin >> f >> s;
    cin >> v;
    switch(v)
    {
        case 1:
        {
            cout << f+s << endl;
            break;
        }
        case 2:
        {
            cout << f-s << endl;
            break;
        }
        case 3:
        {
            cout << f+s << endl;
            break;
        }
        case 4:
        {
            cout << f/s << endl;
            break;
        }
        default: cout << "error \n";
    }
    return 0;
}

