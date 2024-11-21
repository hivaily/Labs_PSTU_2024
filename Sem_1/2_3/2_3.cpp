#include <iostream>

using namespace std;

long fact(const int n)
{
	long f = 1;
	for (int i = 1; i <= n; ++i)
		f *= i;
	return f;
}

int main()
{
	int x, a, b, sum;
	a = 1;
	b = 2;
	sum = 0;

	cout << "Input N "; cin >> x;
	if (x < 1) {
		cout << "Wrong N!"; return 0;
	}

	for (int i = 0; i < x; i++)
	{
		sum += (fact(b) / fact(a - 1));
		a += 1;
		b += 2;
	}

	cout << "Sum = " << sum;

	return 0;
}
