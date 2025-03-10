#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int tmp;
	int m;
	cin >> m;
	int min;
	const int n = 10;
	int arr[n];
	int range_min, range_max;
	range_min = 2;
	range_max = 28000;
	for (int i = 0; i < n; i++)
	{
		arr[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
		cout << arr[i] << " ";
	}
	cout << endl;
	min = arr[0];
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n ; j++)
		{
			if (arr[i] > arr[min])
			{
				min = i;
			}
		}
		tmp = arr[min];
		arr[min] = arr[i];
		arr[i] = tmp;
	}
	cout << "sorted" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}