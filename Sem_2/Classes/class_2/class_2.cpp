#include <iostream>
using namespace std;

/* var 9
Пользовательский класс СОТРУДНИК ФИО – string Должность – string Зарплата – double*/

class employee
{	
	public :
		string fullname, position;
		double salary;
		employee() : fullname(""), position(""), salary(0) {}
		employee(string fullname, string position, double salary ) : fullname(fullname) , position(position) , salary(salary) {}
		employee(employee& A) : fullname(A.fullname), position(A.position), salary(A.salary) {}
		~employee()
		{
			cout << "Memory cleared." << '\n';
		}

		void show()
		{
			cout << "Full name : " << fullname << '\n' << "Position : " << position << '\n' << "Salary : " << salary << '\n' << '\n';
		}


};

int main()
{
	employee A;
	A.show();
	employee B("Benjamin Beard", "CEO", 400000);
	B.show();
	employee C(B);
	C.show();
	return 0;
}

