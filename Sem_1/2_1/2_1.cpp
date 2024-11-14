#include <iostream>

using namespace std;
int main()
{
	system("chcp 1251>NULL");
	int x, y, z;
	y = 0;
	cout << "¬ведите количество натуральных чисел "; cin >> x;
	z = x;
	for (int i = 1; i < z+1; i++)
	{
		y += x;
		x -= 1;
	}

	cout << "—умма этого количества первых натуральных чисел равна " << y;
	return 0;



}