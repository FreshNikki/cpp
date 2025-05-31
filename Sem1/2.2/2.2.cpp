#include <iostream>
using namespace std;
int main()

{
    int N;
    int comp = 1;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        comp *= i;
    }
    cout << comp << endl;
    return 0;
}
