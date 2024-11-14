#include <iostream>

using namespace std;

int main()
{
	int x, y, z, * a, * b;

	cin >> x >> y;

	a = &x;

	b = &y;

	z = *b;

	y = *a;

	x = z;


	cout << x << " " << y;
	return 0;
}