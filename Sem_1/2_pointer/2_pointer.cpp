#include <iostream>

using namespace std;

int main()
{
	int x, y, * a, * b;

	cin >> x >> y;

	a = &x;

	b = &y;

	cout << *a + *b;

	return 0;
}
