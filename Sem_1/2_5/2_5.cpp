#include <iostream>

using namespace std;
int main()
{
	system("chcp 1251>NULL");
	int x, y, n;


	cout << "¬ведите число N "; cin >> x;

	if (x <= 2) { cout << "¬ведено неверное значение N"; return 0; }
	y = x - 1;
	n = x;
	x = 1;
	for (int i = 1; i < n+1; i++)
	{
		cout << string(y, ' ') << string(x, '*') << endl;
		y -= 1;
		x += 1;


	}

	return 0;



}