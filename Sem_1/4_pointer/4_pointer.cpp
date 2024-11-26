
#include <iostream>

using namespace std;

int main()
{
	int n, tmp, * ptr = &tmp, max, min;

	cout << "Input number of nubmers in the sequence and its first member "; cin >> n >> *ptr;
	max = *ptr;
	min = *ptr;

	for (int i = 1; i < n; i++)
	{
		cout << "Input member of sequence "; cin >> *ptr;
		if (*ptr > max) { max = *ptr; }
		else if (*ptr < min) { min = *ptr; }
	}
	cout << "Max = " << max << endl << "Min = " << min;




	return 0;
}
