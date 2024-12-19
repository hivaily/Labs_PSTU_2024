#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	// e**x - e**(-x) - 2 = 0
	// [0;1]

	float a, b, c;
	float fA, fB, fC;
	double eps = 0.000001;

	a = 0;
	b = 1;

	while (b - a > eps)
	{
		c = (a + b) / 2;
		fA = (exp(a) - exp(-a) - 2);
		fB = (exp(b) - exp(-b) - 2);
		fC = (exp(c) - exp(-c) - 2);

		if (fA * fC < 0) { b = c; }
		else if (fC * fB < 0) { a = c; }
		else { cout << "Someothing went wrong!" << endl; }
	}
	cout << "Solutions: " << a << "; " << b << endl;
	return 0;
}