#include <iostream>
using namespace std;
int main()
{
	int tmp;
	const int n = 7;
	int range_min, range_max;
	range_min = 2;
	range_max = 412;
	int arr[7] = {};

	for (int i = 0; i < n; i++)
	{
		arr[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
		cout << arr[i] << " ";
	}

	cout << endl;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp = arr[j];
			if (arr[j] < arr[j - 1])
			{
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}



	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
