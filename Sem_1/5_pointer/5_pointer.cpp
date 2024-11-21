
#include <iostream>

using namespace std;

int main()
{
	int n, fact = 1, * f = &fact;

	cout << ("Input N "); cin >> n;

	for (int i = 1; i <= n; i++) { *f *= i; }

	cout << ("Fact of  ") << n << " = " << *f;

	return 0;
}
