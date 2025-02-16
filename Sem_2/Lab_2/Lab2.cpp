#include <iostream>
using namespace std;
/* var 24
Определить сколько элементов двумерного массива
больше любого элемента на главной диагонали.*/



int solution(int a[][3])
{
	int n = 3;
	int tmp, max, s = 0;
	max = a[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp = a[i][j];
			if (max < tmp) { max = tmp; }
			i++;
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp = a[i][j];
			if (tmp > max) { s++; };
		}
	}

	return s;

}

void main()
{
	int a[3][3] = { {8,2,3},
				    {4,10,28},
				    {13,8,12}, };

	int s = solution(a);
	cout << "Solution : " << s;

}
