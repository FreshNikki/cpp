#include <iostream>
using namespace std;
int n;

void print(int * A,int * B,int * C)
{
    for(int i = 0; i < n; ++i)
    {
        cout << A[i] << "   " << B[i] << "   " << C[i] << endl;
    }
    cout << endl;
}

void move(int count, int * B, int * C, int * A)
{
    if (count == 0)
    {
        return;
    }
    move(count-1, B, A, C);
    //F -> T
    int t = n-1;
    while(C[t]==0 && t >= 0)
    {
        t--;
    }
    int f = n-1;
    while(B[f]==0)
    {
        f--;
    }
    C[t+1] = B[f];
    B[f] = 0;
    
    print(B,A,C);
    move(count-1, A, C, B);
}

int main()
{
    cin >> n;
    int A[n], B[n], C[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = i+1;
        B[i] = C[i] = 0;
    }
    print(A,B,C);
    move(n,A,C,B);
    print(A,B,C);
    return 0;
}
