#include <iostream>

using namespace std;
int main()
{
	system("chcp 1251>NULL");
	int x, y, n, z, g;

	cout << "¬ведите число N "; cin >> x;
	if ((x % 2 == 0) or (x <= 3)) { cout << "¬ведено неподход€щее значение N"; return 0; }

	n = x;
	y = x / 2 + 1;
	x = 1;
	z = 0;
	g = 0;
	for (int i = 1; i < n + 1; i++)
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
			cout << string(y, ' ') << string(n, '*');
			return 0;
		}

	}
	return 0;
}