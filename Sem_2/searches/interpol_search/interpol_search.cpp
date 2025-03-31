#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int low, int high, int x)
{
	while (low <= high && x >= arr[low] && x <= arr[high])
	{
		if (low == high)
		{
			if (arr[low] == x) return low;
			return -1;
		}
		int pos = low + (((x - arr[low]) * (high - low)) / (arr[high] - arr[low]));
		if (arr[pos] == x) return pos;
		if (arr[pos] < x) low = pos + 1;
		else high = pos - 1;
	}
	return -1;
}

int interpolationSearchRec(int arr[], int low, int high, int x)
{
	if (high >= low && x >= arr[low] && x <= arr[high])
	{
		int pos = low + (((x - arr[low]) * (high - low)) / (arr[high] - arr[low]));
		if (arr[pos] == x) return pos;
		if (arr[pos] > x) return interpolationSearchRec(arr, low, pos - 1, x);
		if (arr[pos] < x) return interpolationSearchRec(arr, pos + 1, high, x);
	}
	return -1;
}

int main()
{
	int arr[] = { 0,2,5,10,20,50,84,121,124,2000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	int res = interpolationSearch(arr, 0, n - 1, x);
	if (res == -1) cout << "Element " << x << " not found" << "\n";
	else cout << "Element " << x << " found with index " << res << "\n";

	int resRec = interpolationSearchRec(arr, 0, n - 1, x);
	if (resRec == -1) cout << "Element " << x << " not found" << "\n";
	else cout << "Element " << x << " found with index " << resRec << "\n";
	return 0;
}


