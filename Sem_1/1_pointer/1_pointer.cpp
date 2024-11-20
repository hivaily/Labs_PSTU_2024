#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251>NULL");
	int x, y, z, * px, * py;

	cout << "Введите значения двух переменных "; cin >> x >> y;

	px = &x;

	py = &y;

	z = *py;

	y = *px;

	x = z;


	cout << "Обратные = " << x << " " << y;
	return 0;
}
