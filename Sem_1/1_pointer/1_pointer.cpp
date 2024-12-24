#include <iostream>

using namespace std;

int main()
{
	int x, y, z, * px, * py;

	cout << "Input two variables "; cin >> x >> y;

	px = &x;

	py = &y;

	z = *py;

	y = *px;

	x = z;


	cout << "Reversed variables = " << x << " " << y;
	return 0;
}
