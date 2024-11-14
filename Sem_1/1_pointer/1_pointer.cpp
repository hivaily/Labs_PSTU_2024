#include <iostream>

using namespace std;

int main()
{
	int x, y, z, * a, * b;

	x = 9;

	y = 21;

	cout << x << " " << y << endl;

	a = &x;

	b = &y;

	z = *b;

	y = *a;

	x = z;


	cout << x << " " << y;
	return 0;
}
