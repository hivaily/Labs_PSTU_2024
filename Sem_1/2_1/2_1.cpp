#include <iostream>

using namespace std;
int main()
{
	int x, y = 0;
	cout << "Input N "; cin >> x;
	if (x <= 0) { cout << "Not natural number!"; return 0; }
	else
	{
		for (int i = 1; i <= x; i++)
		{
			y += i;
		}
	}

	cout << "Sum =  " << y;

	return 0;
}
