#include <iostream>

using namespace std;
int main()
{
	int x, tmp, max;

	cout << "Input number of numbers in the sequence "; cin >> x;
	if (x <= 0) { cout << "Error. Number cant be <= 0 "; return 0; }

	for (int i = 1; i <= x; i++)
	{
		cout << "Input member of the sequence "; cin >> tmp;
		if (i == 1) { max = tmp; }
		if (tmp > max) { max = tmp; }
	}
	cout << "Max: " << max << endl;
	return 0;

}