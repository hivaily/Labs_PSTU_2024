
#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251>NULL");
	int n, tmp, * ptr = &tmp, max, min;

	cout << "Введите длину последовательности и первый её член "; cin >> n >> *ptr;
	max = *ptr;
	min = *ptr;

	for (int i = 1; i < n; i++)
	{
		cout << "Введите член последовательности "; cin >> *ptr;
		if (*ptr > max) { max = *ptr; }
		else if (*ptr < min) { min = *ptr; }
	}
	cout << "Максимум = " << max << endl << "Минимум = " << min;




	return 0;
}