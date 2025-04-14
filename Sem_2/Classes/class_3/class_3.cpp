#include <iostream>
using namespace std;

/* var 9
Создать класс Money. Два поля - long для рублей, int для копеек. Дробная часть при выводе на экран должна быть отделена от целой части запятой. Реализовать вычитание дробного числа из суммы денег, операции сравнения == и !=
*/

class money
{
	public:
		long rub;
		int kop;
		money() : rub(0) , kop(0) {}
		money(long rub, int kop) : rub(rub), kop(kop) {}
		money(money& A) :rub(A.rub), kop(A.kop) {}
		money(const money& obj) {}

		~money()
		{
			cout << "Memory cleared." << '\n';
		}

		void show()
		{
			cout << rub << ',' << kop << '\n';
		}

		money& operator = (const money& original)
		{
			if (this == &original) return *this;
			rub = original.rub;
			kop = original.kop;
		}

		money operator - (double val)
		{
			long total = rub * 100 + kop;
			long subtotal = val * 100;
			long res = total - subtotal;
			return money(res / 100, res % 100);
		}

		bool operator == (const money& original)
		{
			return (rub == original.rub) && (kop == original.kop);
		}

		bool operator != (const money& original)
		{
			return !(*this == original);
		}

		friend ostream& operator << (ostream& out, const money& original) 
		{
			return out << original.rub << ',' << original.kop << '\n';
		}

		friend istream& operator >> (istream& is, money& original)
		{
			cout << "Input rubles ";
			is >> original.rub;
			cout << "Input kopecks ";
			is >> original.kop;
			return is;
		}

};

int main()
{
	money A(125, 50);
	money B(50, 75);
	money C(0, 25);
	money res = A - 0.75;
	cout << "A = 125,50" << '\n' << "A - 0.75 = ";
	res.show();
	cout << "B = " << B;
	cin >> A;
	cout << "A = " << A;
	cout << "A == B? " << (A == B) << '\n';
	cout << "A != B? " << (A != B) << '\n';
	return 0; 
}
