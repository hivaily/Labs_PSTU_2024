
#include <iostream>

using namespace std;

int main()
{
	float x, y, * a, * b;

	cin >> x >> y;

	a = &x;

	b = &y;

	cout << *a + *b;
}
