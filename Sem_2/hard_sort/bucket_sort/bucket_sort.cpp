#include <iostream>
using namespace std;

int* bucketSort(int arr[], int n)
{
	const int BUCKET_NUM = 10;
	const int BUCKET_SIZE = 10;
	int buckets[BUCKET_NUM][BUCKET_SIZE];
	int bucketSizes[BUCKET_NUM] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int bucketIndex = i / BUCKET_NUM;
		buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
		bucketSizes[bucketIndex]++;
	}
	for (int i = 0; i < BUCKET_NUM; i++)
	{
		for (int j = 0; j < bucketSizes[i]; j++)
		{
			int tmp = buckets[i][j];
			int k = j - 1;
			while (k >= 0 && buckets[i][k] > tmp)
			{
				buckets[i][k + 1] = buckets[i][k];
				k--;
			}
			buckets[i][k + 1] = tmp;
		}
	}
	int idx = 0;
	for (int i = 0; i < BUCKET_NUM; i++)
	{
		for (int j = 0; j < bucketSizes[i]; j++)
		{
			arr[idx++] = buckets[i][j];
		}
	}
	return arr;
}

int main()
{
	int a[] = { 10,2,5,84,20,124,0,-12,2000,50 };
	int n = 10;
	cout << "Unsorted array : ";
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
	bucketSort(a, n);

	cout << "Sorted array : ";
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}
