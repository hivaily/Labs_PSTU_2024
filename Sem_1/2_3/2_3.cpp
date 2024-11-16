#include <iostream>

using namespace std;

long fact(const int n)
{
	long f = 1;
	for (int i = 1; i <= n; ++i)
		f *= i;
	return f;
}

int main()
{
	system("chcp 1251>NULL");
	int x,a,b,sum;
	a = 1;
	b = 2;
	sum = 0;

	cout << "Введите число N "; cin >> x;
	if (x < 1) {
		cout << "Неправильно введённое значение"; return 0;}

	while (b <= x)
	{
		sum += (fact(b) / fact(a - 1));
		a += 1;
		b += 2;
	}

	if (x > b-2)
	{
		sum += fact(x) / fact(a - 1);
	}


	cout << "Сумма равна " << sum;

	return 0;
}