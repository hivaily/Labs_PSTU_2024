#include <iostream>
#include <string>
#include <fstream>

using namespace std;
/*  24.
 1) Скопировать из файла F1 в файл F2 все строки, в которых
 содержится два одинаковых слова.
 2) Определить номер слова, в котором больше всего  букв 
«А». */


int main()
{
	int fn = 10, sn = 0, len, tmp1 = 0, tmp2 = 0, maxA = 0 , maxSTR = 0, maxSTL = 0, count = 0;
	string stmp;
	string flines[10][10];
	string slines[10][10];
	ifstream file1("F1.txt");
	ofstream file2("F2.txt");
	string line;

	if (file1.is_open())
	{
		while (getline(file1, line))
		{
			len = line.length();
			for (size_t i = 0; i < len; i++)
			{
				if (line[i] == ',')
				{ 
					flines[tmp1][tmp2] = stmp;
					tmp2++;
					stmp = "";
					continue; 
				}

				stmp += line[i];
			}
			flines[tmp1][tmp2] = stmp;
			stmp = "";
			tmp2 = 0;
			tmp1++;
		}
		file1.close();
	}

	tmp1 = 0;
	tmp2 = 0;

	for (size_t stl = 0; stl < fn; stl++)
	{
		for (size_t word = 0; word < fn; word++)
		{
			stmp = flines[stl][word];
			for (size_t i = 0; i < fn; i++)
			{
				if (flines[stl][i] == stmp) { tmp1++; }
			}
		}

		if (tmp1 > 10)
		{
			for (size_t i = 0; i < fn; i++)
			{
				slines[sn][i] = flines[stl][i];
				stmp = slines[sn][i];
				while (stmp.find('a') != -1)
				{
					tmp1 = stmp.find('a');
					tmp2++;
					stmp.erase(stmp.begin() + tmp1);
				}
				if (maxA < tmp2) { maxA = tmp2; maxSTL = sn; maxSTR = i; }
				tmp2 = 0;
			}
			sn++;
		}
		tmp1 = 0;
	}

	for (size_t stl = 0; stl < sn; stl++)
	{
		for (size_t word = 0; word < fn; word++)
		{
			file2 << slines[stl][word] << ' ';
		}
		file2 << "\n";
	}
	file2 << "\n" << "Номер слова в котором больше всего букв A : строка - " << maxSTL+1 << " слово - " << maxSTR+1;
	file2.close();


	return 0;
}
