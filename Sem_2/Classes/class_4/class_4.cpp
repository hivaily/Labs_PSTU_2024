#include <iostream>
using namespace std;

/* var 9 Базовый класс triad - три int поля first, second, third. Определить методы изменения и сравнения. Создать производный класс TIME с полями часы, минуты, секунды. Определить полный набор операций сравнения.
*/

class triad
{
	public:
		int first, second, third;
		triad() : first(0) , second(0), third(0) {}
		triad(int first, int second, int third) : first(first), second(second), third(third) {}
		triad(triad& A) : first(A.first), second(A.second), third(A.third) {}
		triad(const triad& obj) {}

		~triad()
		{
			cout << "Memory cleared." << '\n';
		}

		void show()
		{
			cout << first << second << third;
		}

		triad& operator = (const triad& original)
		{
			if (this == &original) return *this;
			first = original.first;
			second = original.second;
			third = original.third;
		}


		void set_first(int tmp)
		{
			first = tmp;
		}

		void set_second(int tmp)
		{
			second = tmp;
		}

		void set_third(int tmp)
		{
			third = tmp;
		}

		bool operator == (const triad& original)
		{
			return (first == original.first) && (second == original.second) && (third == original.third);
		}

		bool operator != (const triad& original)
		{
			return !(*this == original);
		}

		friend ostream& operator << (ostream& out, const triad& original) 
		{
			return out << original.first << ':' << original.second << ':' << original.third << '\n';
		}

		friend istream& operator >> (istream& is, triad& original)
		{
			cout << "Input first number ";
			is >> original.first;
			cout << "Input second number ";
			is >> original.second;
			cout << "Input third number ";
			is >> original.third;
			return is;
		}

};

class TIME : public triad
{
	public:
		TIME() : triad(0,0,0) {}
		TIME(int hours, int minutes, int seconds) : triad(hours, minutes, seconds) {}

		int total()
		{
			return first * 3600 + second * 60 + third;
		}


		bool operator == (TIME& original)
		{
			return total() == original.total();
		}

		bool operator != (TIME& original)
		{
			return !(*this == original);
		}

		bool operator > (TIME& original)
		{
			return original < *this;
		}

		bool operator < (TIME& original)
		{
			return total() < original.total();
		}

		bool operator >= (TIME& original)
		{
			return !(*this < original);
		}

		bool operator <= (TIME& original)
		{
			return !(*this > original);
		}
};

int main()
{
	TIME A(10, 25, 50);
	TIME B(24, 10, 18);
	TIME C(10, 25, 50);
	cout << "Time A = " << A;
	cout << "Time B = " << B;
	cout << "Time C = " << C;
	cout << "Time A == Time B? " << (A == B) << '\n';
	cout << "Time A == Time C? " << (A == C) << '\n';
	cout << "Time A > Time C? " << (A > C) << '\n';
	cout << "Time B < Time C? " << (B < C) << '\n';
	cout << "Time A >= Time C? " << (A >= C) << '\n';
	cout << "Time B <= Time C? " << (B <= C) << '\n';

	return 0;
}
