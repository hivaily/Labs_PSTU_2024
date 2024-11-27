#include <iostream>

using namespace std;
int main()
{
	int a, sum = 0;
	cout << "Input N "; cin >> a;
	if (a <= 0) { cout << "Error. N cant be <= than 0"; return 0; }

	for (int i = 1; i <= a ; i++)
	{
		if (i % 2 == 0) { sum += i; }
		else { sum += -i; }
	}

	cout << "Sum = " << sum;
	return 0;

}