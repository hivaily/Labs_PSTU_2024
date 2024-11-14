
#include <iostream>

using namespace std;

int main()
{
	float x, y, * a, * b;

	x = 8.4;

	y = 2.5;

	cout << x << " " << y << endl;

	a = &x;

	b = &y;

	cout << *a + *b;

	return 0;
}
