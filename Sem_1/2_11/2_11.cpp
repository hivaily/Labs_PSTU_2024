#include <iostream>

using namespace std;
int main()
{
	int x, tmp;
	bool F1 = false, F2 = false;
	cout << "Input number of numbres in the sequence "; cin >> x;
	if (x <= 0) { cout << "Error. Number cant be <= 0"; return 0; }
	for (int i = 1; i <= x; i++)
	{
		cout << "Input member of the sequence "; cin >> tmp;
		if (!F1 and !F2)
		{
			if (tmp > 0) { F1 = true; }
			else if (tmp < 0) { F2 = true; }
		}

	}
	if (F1) { cout << "First comes positive number"; }
	else if (F2) { cout << "First comes negative number"; }
	else { cout << "Everything was 0"; }
	
	return 0;

}