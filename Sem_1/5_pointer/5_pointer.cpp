
#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251>NULL");

	int n, fact = 1, * f = &fact;

	cout << ("������� ������ ����� "); cin >> n;

	for (int i = 1; i <= n; i++) {*f *= i;}
	
	cout << ("��������� ") << n << " ����� " << *f;

	return 0;
}