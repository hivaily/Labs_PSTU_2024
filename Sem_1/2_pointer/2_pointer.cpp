#include <iostream>

using namespace std;

int main()
{
	int x, y, * a, * b;

	x = 9;

	y = 10;

	cout << x << " " <<	 y << endl;
		
	a = &x;

	b = &y;

	cout << *a + *b;

	return 0;
}
