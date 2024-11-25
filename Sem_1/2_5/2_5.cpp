#include <iostream>

using namespace std;
int main()
{
	int x, y, n = 1;

	cout << "Input N "; cin >> x;

	if (x <= 2) { cout << "Cant build triangle with that N"; return 0; }
	y = x - 1;
	for (int i = 1; i <= x; i++)
	{
		cout << string(y, ' ') << string(n, '*') << endl;
		y -= 1;
		n += 1;


	}

	return 0;
}
