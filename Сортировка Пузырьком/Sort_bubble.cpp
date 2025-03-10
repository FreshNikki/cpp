#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int tmp;
	const int m = 100;
	int n;
	cin >> n;
	int arr[m];
	int range_min, range_max;
	range_min = 2;
	range_max = 28000;
	for (int i = 0; i < n; i++)
	{
		arr[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = n; i > 0; i--)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	cout << "sorted" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}