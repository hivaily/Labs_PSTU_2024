#include <iostream>

using namespace std;
int main()
{
	int x, y, n;


	cout << "Input N "; cin >> x;

	if (x <= 2) { cout << "Cant build triangle with that N"; return 0; }
	y = 0;
	n = x;
	for (int i = 1; i < n + 1; i++)
	{
		cout << string(y, ' ') << string(x, '*') << endl;
		y += 1;
		x -= 1;


	}

	return 0;



}
