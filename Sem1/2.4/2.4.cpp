#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N < 4)
    {
        cout << "number > 3 \n";
    }
    else if (N%2==0)
    {
        cout << "odd number only \n";
    }
    else
    {
        int spaces = N/2;
        int stars = 1;
        for (int i=0;i<(N+1)/2;i++)
        {
            for (int j=0; j<=spaces; j++)
            {
                cout << " ";
            }
            spaces--;
            for (int j = 0; j < stars; j++)
            {
                cout << "*";
            }
            stars += 2;
            cout << endl;
        }
    }
    return 0;
}
