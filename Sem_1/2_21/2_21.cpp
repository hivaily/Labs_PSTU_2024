#include <iostream>

using namespace std;
int main()
{
	int b , c;
	bool F = false;

	for (int i = 1; i <= 3; i)
	{
		cout << "Input member of the sequence, input 0 to exit "; cin >> c;
		if (i == 1) { b = c; i++; continue; }
		if (c == 0) { break; }
		if (c <= b) { F = true; }
		b = c;

	}

	if (F == true) { cout << "Not increasing"; }
	else { cout << "Increasing"; }

	return 0;

}
