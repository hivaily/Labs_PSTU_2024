#include <iostream>

using namespace std;

int main()
{

	int x, y, * a, * b;

	cout << "Input two variables  "; cin >> x >> y;

	a = &x;

	b = &y;

	cout << "Sum = " << *a + *b;

	return 0;
}
