#include <iostream>

using namespace std;
int main()
{
	int x, y, n, b, g;

	cout << "Input  N "; cin >> x;
	cout << "Input operation code "; cin >> y;

	switch (y)
	{
	case 1:
	{
		n = sqrt(x);
		if (x == pow(n, 2)) 
		{
			for (int i = 1; i < n + 1; i++)
			{
				cout << string(n, '*') << endl;
			}
			break;
		}

		else if ((x % 4 == 0) and (x > 2))
		{
			x = x / 4 + 1;
			b = x - 2;

			for (int i = 1; i < x; i++)
			{

				if (i == 1)
				{
					cout << string(x, '*') << endl;
				}

				cout << '*' << string(b, ' ') << '*' << endl;

				if (i == x - 2)
				{
					cout << string(x, '*') << endl;
					break;
				}

		}
			break;

	

		}
		else { cout << "Cant draw square with those amount of stars"; break; }


		

		
	}

	case 2:
	{
		if (x < 1) { cout << "Cant draw square with those amount of stars"; break; }
		for (int i = 1; i < x + 1; i++)
		{
			cout << string(x, '*') << endl;
		}
		break;
	}

	case 3:
	{
		if (x < 1) { cout << "Cant draw square with those amount of stars"; break; }
		b = x - 2;

		for (int i = 1; i < x; i++)
		{
			if (i == 1)
			{
				cout << string(x, '*') << endl;
			}

			cout << '*' << string(b, ' ') << '*' << endl;

			if (i == x - 2)
			{
				cout << string(x, '*') << endl;
				break;
			}

		}
		break;

	}
	default: cout << "Wrong operation code";

	}


	return 0;

}
