#include <iostream>

using namespace std;
int main()
{
	int x, y = 1;
	cout << "Input N "; cin >> x;
	if (x <= 0) { cout << "Not natural number!"; return 0; }
	else
	{
		for (int i = 1; i <= x; i++)
		{
			y *= i;
		}
	}

	cout << "Mult = " << y;

	return 0;
}

