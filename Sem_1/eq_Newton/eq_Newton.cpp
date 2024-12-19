#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	// e**x - e**(-x) - 2 
	// (1') e**x + e**(-x)
	// (2") e**x - e**(-x)
	// [0;1]
	// x0 = b , e - (1/e) - 2 = 0,35 > 0

	float x, xPrev;
	x = 1;
	xPrev = 0;
	double eps = 0.000001;

	while (abs(x - xPrev) > eps)
	{
		xPrev = x;
		x = xPrev - (exp(xPrev) - exp(-xPrev) - 2) / (exp(xPrev) + exp(-xPrev));
	}
	cout << "Solution: " << x << endl;
	return 0;
}