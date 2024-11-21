#include <iostream>

using namespace std;

int main()
{
	float x, y;
	int z;
	cin >> x >> y >> z;


	if (y == 0 and z == 4)
	{
		cout << "Cant divide by 0!"; return 0;
	}

	else
	{
		switch (z)
		{

		case 1: cout << x + y; break;
		case 2: cout << x - y; break;
		case 3: cout << x * y; break;
		case 4: cout << x / y; break;
		default: cout << "Wrong operation code";
		}

		return 0;
	}
}
