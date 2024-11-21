#include <iostream>

using namespace std;
int main()
{
	int x, y, n, b;

	cout << "Input  N "; cin >> x;
	y = x;
	n = (x - 2)*2+1;
	b = 0;

	cout << string(y, ' ');

	for (int i = 0; i < x; i++)
	{
		cout << '*' << ' ';
	}

	cout << endl;
	y--;

	for (int i = 1; i < x-1; i++)
	{
		cout << string(y, ' ') << '*' << string(n,' ') << '*' << string(b,' ') << '*' << endl;
		y -= 1;
		b += 1;
	}


	cout << string(y, ' ');

	for (int i = 0; i < x; i++)
	{
		cout << '*' << ' ';
	}

	b-= 1;
	cout << string(b, ' ') << '*' << endl;

	


	for (int i = 1; i < x - 1; i++)
	{
		cout << string(y, ' ') << '*' << string(n, ' ') << '*' << string(b,' ') << '*' <<  endl;
		b -= 1;
	}

	cout << string(y, ' ');

	for (int i = 0; i < x; i++)
	{
		cout << '*' << ' ';
	}

	cout << endl;
}