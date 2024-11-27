#include <iostream>

using namespace std;
int main()
{
	int a, b, sum = 0;
	cout << "Input N, then S "; cin >> a >> b;

	if (a <= 0) { cout << "Error. N not natural number!"; return 0; }

	while (a != 0)
	{
		if (a % 10 == b)
		{
			cout << "S is in N!"; return 0;
		}
		sum += a % 10;
		a /= 10;
	}
	cout << "S is not in N!";
	return 0;
}