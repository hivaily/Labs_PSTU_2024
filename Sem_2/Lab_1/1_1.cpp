#include <iostream>

using namespace std;
int main()
{
	int tmp = 10, tmp1, k, l, a[100];               
	cout << "Input array length "; cin >> l;
	tmp1 = l;

	cout << "Array : ";

	for (int i = 0; i < l; i++)
	{
		a[i] = tmp;
		tmp--;
	}


	for (int i = 0; i < l; i++)
	{
		cout << a[i] << ' ';
	}

	cout << endl << endl << "Input K " ; cin >> k;

	tmp = 0;

	cout << endl << "Loop starting from K : ";

	while (tmp < l)
	{
		if (k == l) { k = 0; };
		cout << a[k] << ' ';
		k++;
		tmp++;
	}

	cout << endl;

	for (int i = 1; i < tmp1; i++)
	{
		for (int i = 1; i < tmp1; i++)
			if (a[i] < a[i - 1])
			{
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
			}

	}

	tmp = 0;
	
	cout << "Changed loop starting from K : ";

	while (tmp < l)
	{
		if (k == l) { k = 0; };
		if (k % 2 == 0) { k++; tmp++; continue; }
		cout << a[k] << ' ';
		k++;
		tmp++;
	}
	
	cout << endl;
	return 0;
}