#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251>NULL");

	int x, y, * a, * b;

	cout << "Введите значения двух переменных "; cin >> x >> y;

	a = &x;

	b = &y;

	cout << "Сумма = " << *a + *b;

	return 0;
}
