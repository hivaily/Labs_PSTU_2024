#include <iostream>

using namespace std;
int main()
{
	int x, y, z = 0, g = 0;

	cout << "Input N "; cin >> x;
	if ((x % 2 == 0) or (x <= 3)) { cout << "Cant build triangle with that N"; return 0; }

	y = x / 2 + 1;

	for (int i = 1; i <= x; i++)
	{
		cout << string(y, ' ') << '*' << string(z, ' ');

		if (g >= 1)
		{
			cout << '*' << endl;
			z += 1;
		}

		else
		{
			cout << endl;
		}

		g += 1;
		y -= 1;
		z += 1;

		if (y == 1)
		{
			cout << string(y, ' ') << string(x, '*');
			return 0;
		}

	}
	return 0;
}
