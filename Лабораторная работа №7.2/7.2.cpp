#include <iostream>
#include <cstdarg>
using namespace std;

float mult (float count, ...)
{
    va_list args;
    va_start(args, count);
    float result = 1.0;
    for (int i = 0; i < count; i++)
    {
        float num = (float)va_arg(args, double);
        result *= num;
    }
    va_end(args);
    return result;
}
int main ()
{
    cout << mult(3, 1.0, 2.0, 3.0) << endl;
    cout << mult(7, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0) << endl;
    cout << mult(11, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0) << endl;
    return 0;
}
