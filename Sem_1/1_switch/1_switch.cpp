#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251>NULL");
	float x, y;
	int z;
	cin >> x >> y >> z;


	if (y == 0 and z == 4)
	{
		cout << "ƒелить на ноль нельз€!"; return 0;
	}

	switch (z)
	{
	case 1: cout << x + y; break;
	case 2: cout << x - y; break;
	case 3: cout << x * y; break;
	case 4: cout << x / y; break;
	default: cout << "¬веден неправильный код операции";
	}

	return 0;
}