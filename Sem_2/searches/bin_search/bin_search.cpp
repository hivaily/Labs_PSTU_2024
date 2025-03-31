#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int x)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == x) return mid;
		if (arr[mid] < x) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}
int binarySearchRec(int arr[], int low, int high, int x)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == x) return mid;
		if (arr[mid] > x) return binarySearchRec(arr, low, mid - 1, x);
		return binarySearchRec(arr, mid + 1, high, x);
	}
	return -1;
}

int main()
{
	int arr[] = { 0,2,5,10,20,50,84,121,124,2000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 2000;

	int res = binarySearch(arr, 0, n - 1, x);
	if (res == -1) cout << "Element " << x << " not found" << "\n";
	else cout << "Element " << x << " found with index " << res << "\n";

	int resRec = binarySearchRec(arr, 0, n - 1, x);
	if (resRec == -1) cout << "Element " << x << " not found" << "\n";
	else cout << "Element " << x << " found with index " << resRec << "\n";
	return 0;
}

