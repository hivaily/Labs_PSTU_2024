#include <iostream>
using namespace std;
/* var 24.
 а) для массива целых чисел удаляет все четные элементы из
 массива;
 б) для строки удаляет все четные слова
 */

int* sol(int n, int mas[])
{
	int* nmas = new int[n];
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		if (mas[i] % 2 != 0) { nmas[tmp] = mas[i]; tmp++; }
	}
	for (int i = 0; i < tmp; i++)
	{
		cout << nmas[i] << ' ';

	}

	return 0;


}


string sol(int n, string str)
{
	int len = str.length();
	string* nmas = new string[n];
	string tmpword = "";
	int tmp = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != ' ') { tmpword = tmpword + str[i]; }
		else { nmas[tmp] = tmpword; tmpword = ""; tmp++; }
	}
	nmas[tmp] = tmpword;
	tmp = 0;
	string* rmas = new string[n];

	for (int i = 0; i < n; i++)
	{
		if ((i + 1) % 2 != 0) { rmas[tmp] = nmas[i]; tmp++; }
	}

	for (int i = 0; i < n; i++)
	{
		cout << rmas[i] << ' ';
	}

	return "0";
}




int main()
{
	int mas[8] = { 5,8,1,2,10,25,3,9 };
	string str = "cha maganera mattagan pooreh ganchan round and round";
	int n = 8;

	cout << "Original int array : ";

	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << ' ';
	}

	cout << "\nOriginal string : " << str << "\n\n";
	cout << "Changed int array : ";
	sol(n, mas);
	cout << "\nChanged string : ";
	sol(n, str);
	cout << "\n";

	return 0;
}