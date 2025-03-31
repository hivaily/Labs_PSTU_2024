#include <iostream>
using namespace std;
int* countingSort(int arr[], int size)
{
    int* output = new int[size];
    int max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max) { max = arr[i]; }
    }

    int* count = new int[max + 1]();

    for (int i = 0; i < size; i++) { count[arr[i]]++; }
    for (int i = 1; i <= max; i++) { count[i] += count[i - 1]; }

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < size; i++) { arr[i] = output[i]; }
    delete[] count;
    delete[] output;
    return arr;
}
int main()
{
    int a[] = { 10,2,5,84,20,124,0,121,2000,50 };
    int n = 10;
    cout << "Unsorted array : ";
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";

    countingSort(a, n);

    cout << "Sorted array : ";
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}