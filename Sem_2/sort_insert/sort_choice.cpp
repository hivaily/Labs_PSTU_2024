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


	int key; 
	for (int i = 0; i < n; i++)
	{
		key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	


	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
