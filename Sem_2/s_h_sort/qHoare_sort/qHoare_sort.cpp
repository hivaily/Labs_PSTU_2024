#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int num = 0;
    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] < pivot) { num++; }
    }
    int pos = low + num;
    swap(arr[pos], arr[low]);
    int i = low, j = high;
    while (i < pos && j > pos)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < pos && j > pos) swap(arr[i++], arr[j--]);
    }
    return pos;
}


void quickSort(int arr[], int low, int high)
{
    if (low >= high) return;
    int pI = partition(arr, low, high);
    quickSort(arr, low, pI - 1);
    quickSort(arr, pI + 1, high);
}

int main()
{
    int a[] = { 10, 2, 5, 84, 20, 124, 0, 121, 2000, 50 };
    int n = 10;

    cout << "Unsorted array: ";
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";

    quickSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

