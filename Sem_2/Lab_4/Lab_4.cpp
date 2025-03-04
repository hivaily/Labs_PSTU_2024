#include <iostream>
using namespace std;

int main()
{
	int n, nmin = 1, nmax = 10, smin = 97, smax = 121, tmp, k;
	string stmp;
	cout << "Input array length" << endl; cin >> n;
	string* mas = new string[n];

	for (int i = 0; i < n; i++)
	{
		tmp = (rand() % (nmax - nmin + 1)) + nmin;
		for (int j = 0; j < tmp; j++)
		{
			stmp = (rand() % (smax - smin + 1)) + smin;
			mas[i] = mas[i] + stmp;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << ' ';
	}

	cout << endl << "Input K" << endl; cin >> k;
	string* nmas = new string[n - k];
	tmp = 0;
	for (int i = k; i < n; i++)
	{
		nmas[tmp] = mas[i];
		tmp++;
	}

	delete[] mas;
	mas = nmas;



	for (int i = 0; i < n - k; i++)
	{
		cout << mas[i] << ' ';
	}

	delete[] nmas;

	return 0;
}
