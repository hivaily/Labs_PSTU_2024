#include <iostream>
using namespace std;
int main()
{
	int n, tmp, max, min;

	cout << "Input number of nubmers in the sequence "; cin >> n;
	if (n <= 0) { cout << "Error. Number cant be <= 0"; return 0; }
	
	for (int i = 1; i <= n; i++)
	{
		cout << "Input positive member of sequence "; cin >> tmp;
		if (tmp <= 0) { cout << "Not positive number!" << endl; i -= 1; continue; }
		else if (i == 1) { max = tmp; min = tmp; }
		else if (tmp > max) { max = tmp; }
		else if (tmp < min) { min = tmp; }
	}
	cout << "Sum of max and min = " << max + min;

	return 0;
}
