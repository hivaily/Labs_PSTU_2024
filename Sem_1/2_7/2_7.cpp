#include <iostream>

using namespace std;
int main()
{
	system("chcp 1251>NULL");
	int x, y, n,b,g;

	cout << "¬ведите число N "; cin >> x;
	cout << "¬ведите номер метода построени€ квадрата "; cin >> y;

	switch (y)
	{
		case 1:
		{
			n = sqrt(x);
			if (x != pow(n, 2)) { cout << "»з стольки звЄздочек невозможно составить квадрат с помощью данного метода"; break; }
			for (int i = 1; i < n + 1; i++)
			{
			cout << string(n, '*') << endl;
			}
			break;
		}

		case 2:
		{
			if (x < 1) { cout << "»з стольки звЄздочек невозможно составить квадрат с помощью данного метода"; break; }
			for (int i = 1; i < x + 1; i++)
			{
				cout << string(x, '*') << endl;
			}
			break;
		}

		case 3:
		{
			if (x < 1) { cout << "»з стольки звЄздочек невозможно составить квадрат с помощью данного метода"; break; }
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
		default: cout << "¬веден несуществующий метод построени€";

	}


	return 0;



	
}
