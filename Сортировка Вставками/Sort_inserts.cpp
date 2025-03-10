#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int range_min, range_max;
	int tmp;
	range_min = 2;
	range_max = 28000;
	int m;
	cin >> m;
	const int n = 10;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
		cout << a[i] << " ";
	}
	cout << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] < a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    cout << "sorted" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
