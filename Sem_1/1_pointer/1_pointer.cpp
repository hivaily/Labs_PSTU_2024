#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251>NULL");
	int x, y, z, * a, * b;

	cout << "Введите значения двух переменных "; cin >> x >> y;

	a = &x;

	b = &y;

	z = *b;

	y = *a;

	x = z;


	cout << "Обратные = " << x << " " << y;
	return 0;
}
