#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1; 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    { 
        int pI = partition(arr, low, high);
        quickSort(arr, low, pI - 1);
        quickSort(arr, pI + 1, high); 
    }
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


