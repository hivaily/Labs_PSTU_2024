#include <iostream>

using namespace std;
int main()
{
	system("chcp 1251>NULL");
	int x, y, z;
	y = 1;
	cout << "������� ���������� ����������� ����� "; cin >> x;
	z = x;
	for (int i = 1; i < z+1; i++)
	{
		y *= x;
		x -= 1;
	}

	cout << "������������ ����� ���������� ������ ����������� ����� ����� " << y;
	return 0;



}