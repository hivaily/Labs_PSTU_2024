#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251>NULL");

	float a, b;

	cin >> a >> b;

	if (b == 0)
	{cout << "�� ���� ������ ������!" << endl;
	}

	else
	{cout << a / b << endl;
	}
	
	return 0;
}