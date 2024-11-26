#include <iostream>
using namespace std;
int main()
{
	float a, b, c, D, x;
	int M;

	cout << "Input coefficients a, b, c "; cin >> a >> b >> c;

	D = pow(b,2) - 4 * a * c;

	if (D < 0) { M = 1; }
	else if (D > 0) { M = 2; }
	else { M = 3; }

	switch (M)
	{
	case 1: cout << "No solution"; break;
	case 2: cout << "Two solutions : " << (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) << " and " << (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a); break;
	case 3: cout << "One solution : " << -b / (2 * a); break;
	}

	return 0;
}