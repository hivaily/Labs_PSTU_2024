#include <iostream>

using namespace std;
int main()
{
	system("chcp 1251>NULL");
	int x, y, z;
	y = 1;
	cout << "Input N"; cin >> x;
	if (x <= 0) { cout << "Not natural number!"; return 0; }
	z = x;
	for (int i = 1; i < z+1; i++)
	{
		y *= x;
		x -= 1;
	}

	cout << "Mult = " << y;
	return 0;



}
