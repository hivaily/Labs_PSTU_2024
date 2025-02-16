#include <iostream>
using namespace std;
/* var 24
»з двух заданных с клавиатуры слов состваить различные виды кроссвордов. ѕри невозможности составить кроссворд напечатать сообщение о ошибке*/


int main()
{
	string word1, word2;
	int lenw1, lenw2;
	bool flag = false;
	cout << "Input two words "; cin >> word1 >> word2;
	lenw1 = word1.length();
	lenw2 = word2.length();
	
	for (int i = 0; i < lenw1; i++)
	{
		for (int j = 0; j < lenw2; j++)
		{
			if (word1[i] == word2[j])
			{
				flag = true;
				for (int w1 = 0; w1 < lenw1; w1++)
				{
					if (w1 == i)
					{
						cout << string(lenw2 - j, ' ') << word2 << endl;
						continue;
					}
					cout << string(lenw2,' ') << word1[w1] << endl;
				}
				cout << endl;
				

			}
		}
	}
	
	if (!flag) { cout << "No crosswords";}
	return 0;
}
