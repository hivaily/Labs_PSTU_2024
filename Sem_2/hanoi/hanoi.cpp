#include <iostream>
using namespace std;

void hanoi(int n, int start, int tmp, int point)
{
	if (n == 1)
	{
		cout << "Place ring 1 from rod " << start << " on rod " << point << endl;
		return;
	}

	hanoi(n - 1, start, point, tmp);
	cout << "Place ring " << n << " from rod " << start << " on rod " << point << endl;
	hanoi(n - 1, tmp, start, point);

}

void visual(int n, int rod1, int rod2, int rod3)
{

}


int main()
{
	int n;
	cout << "Input number of rings "; cin >> n;
	hanoi(n, 1, 2, 3);
	return 0;
}
