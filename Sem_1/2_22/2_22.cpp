#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	float n, s, a;
	int i = 1;
	bool flag = false;
	cin >> n >> s;
	while (i <= n && !flag)
	{
		a = sin(n + i / n);
		if (a == s) { flag = true; }
		else { i++; }
	}
	if (flag)
	{
		cout << "N Found!" << endl;
	}
	else
	{
		cout << "N Not found!" << endl;
	}
		return 0;
}