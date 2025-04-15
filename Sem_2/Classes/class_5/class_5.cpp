#include <iostream>
using namespace std;

/* var 9
*/


class object
{
	public:
		virtual void show() = 0;
};


class triad : public object
{
	public:
		int first, second, third;
		triad() : first(0) , second(0), third(0) {}
		triad(int first, int second, int third) : first(first), second(second), third(third) {}
		triad(triad& A) : first(A.first), second(A.second), third(A.third) {}
		triad(const triad& obj) {}


		void show() override
		{
			cout << first << second << third << '\n';
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
			return out << original.first << original.second <<  original.third << '\n';
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

		void show() override
		{
			cout << first << ':' << second << ':' << third << '\n';
		}

		friend ostream& operator << (ostream& out, const TIME& original)
		{
			return out << original.first << ':' << original.second << ':' << original.third << '\n';
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


class Vector
{
	public:
		Vector() : beg(0), size(0), cur(0) {}
		Vector(int n) : beg(new object* [n]), cur(0), size(n) {}
		~Vector(void)
		{
			if (beg != 0) delete[] beg;
			beg = 0;
		}
		void Add(object* n)
		{
			if (cur < size)
			{
				beg[cur] = n;
				cur++;
			}
		}

		friend ostream& operator<<(ostream& out, const Vector& v)
		{
			if (v.size == 0) out << "Empty" << '\n';
			object** p = v.beg;
			for (int i = 0; i < v.cur; i++)
			{
				(*p)->show();
				p++;
			}
			return out;
		}


	private: 
		object** beg;
		int size;
		int cur; 
};



int main()
{
	triad A(10, 15, 20);
	TIME B(20, 24, 50);
	cout << "Triad A = "; A.show();
	cout << "Time B = "; B.show();
	Vector v(5);
	object* p = &A;
	v.Add(p);
	p = &B;
	v.Add(p);
	cout << v;

	return 0;
}