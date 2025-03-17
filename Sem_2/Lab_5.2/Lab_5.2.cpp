#include <iostream>
#include <cstdarg>
using namespace std;
/*Написать функцию (или макроопределение), которая
находит длину стороны по координатам его точек..
Написать функцию square, которая вычисляет площадь
треугольника, заданного координатами вершин. Написать
функцию  squaren c переменным числом параметров,
которая определяет площадь выпуклого многоугольника,
заданного координатами своих вершин.
 */



long double len(int x1, int y1, int x2, int y2)
{
	long double side = 0;
	side = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return side;
}

long double square(int x1, int y1, int x2, int y2, int x3, int y3)
{
	long double area = 0;
	area = 0.5 * ((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3));
	return abs(area);
}

double squaren(int k, ...)
{
	double area = 0;
	double x1, y1, fx1, fy1;
	va_list poly;
	va_start(poly, k);
	int n = k / 2;
	x1 = va_arg(poly, int);
	y1 = va_arg(poly, int);
	fx1 = x1;
	fy1 = y1;

	for (int i = 0; i < n - 1; i++)
	{
		int x2 = va_arg(poly, int);
		int y2 = va_arg(poly, int);
		area += (x1 * y2 - x2 * y1);
		x1 = x2;
		y1 = y2;


	}

	area += (x1 * fy1 - fx1 * y1);
	area /= 2;

	return abs(area);
}



void main()
{
	cout << "\nLength of side with coordinates (2,5) , (3,2) = " << len(2, 5, 3, 2);
	cout << "\nArea of a triangle with coordinates (5,7) , (0,2) , (-3,4) = " << square(5, 7, 0, 2, -3, 4);
	cout << "\nArea of a polygon with coordinates (-10,3) , (3,-2) , (6,2) , (6,3) , (4,5) = " << squaren(10, -10, 3, 3, -2, 6, 2, 6, 3, 4, 5);
}



