#include <iostream>
using namespace std;

class dot
{
public:
	double first, second;
	dot(double x, double y) : first(x), second(y) {}
	void distance(double x1, double y1)
	{
		double res = sqrt(pow((x1 - first), 2) + pow((y1 - second), 2));
		cout << res;
	}
};

int main()
{
	dot A(1.0, 6.0);
	A.distance(10.0, 5.0);

	return 0;
}

