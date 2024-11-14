
#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251>NULL");

	int n, fact = 1, * f = &fact;

	cout << ("Введите нужное число "); cin >> n;

	for (int i = 1; i <= n; i++) {*f *= i;}
	
	cout << ("Факториал ") << n << " равен " << *f;

	return 0;
}