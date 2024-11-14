#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251>NULL");

	float a;

	cin >> a;

	if (a < 5)
	{cout << a * 3 << endl;
	}

	else if (a > 7)
	{cout << a + 3 << endl;
	}

	else
	{cout << a / 10 << endl;
	}
	
}