#include <iostream>

using namespace std;
int main()
{
	int x, y, z;
	y = 0;
	cout << "Input N "; cin >> x;
	if (x <= 0) { cout << "Not natural number!"; return 0; }

	z = x;
	for (int i = 1; i < z + 1; i++)
	{
		y += x;
		x -= 1;
	}

	cout << "Sum =  " << y;
	return 0;




}
