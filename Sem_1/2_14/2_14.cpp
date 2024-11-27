#include <iostream>

using namespace std;
int main()
{
	int a, sum = 0;
	cout << "Input N "; cin >> a;
	if (a <= 0) { cout << "Error. N not natural number!"; return 0; }
	while (a != 0)
	{
		sum += a % 10;
		a /= 10;
	}
	cout << "Sum = " << sum;
	return 0;
}