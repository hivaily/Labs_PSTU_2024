#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

struct Node
{
	string fullName;
	string birthDate;
	string passportNum;

	Node* nextptr = nullptr;

};

struct List
{
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;

	void append(string mass[3])
	{
		Node* newNode = new Node;
		newNode->fullName = mass[0];
		newNode->birthDate = mass[1];
		newNode->passportNum = mass[2];

		if (!head)
		{
			head = tail = newNode;
		}
		else
		{
			tail->nextptr = newNode;
			tail = newNode;
		}
		size++;
	}
	bool pop(string*& mass)
	{
		if (!head) return false;

		Node* prev = nullptr;
		Node* current = head;

		while (current && current->birthDate != mass[1] && current->fullName != mass[0] && current->passportNum != mass[2])
		{
			prev = current;
			current = current->nextptr;
		}

		if (!current) return false;

		if (prev)
		{
			prev->nextptr = current->nextptr;
		}
		else
		{
			head = current->nextptr;
		}

		if (current == tail)
		{
			tail = prev;
		}

		delete current;
		size--;
		return true;
	}
	void output()
	{
		Node* temp = head;
		while (temp)
		{
			cout << "ФИО: " << temp->fullName << endl
				<< "Дата рождения: " << temp->birthDate << endl
				<< "Номер паспорта: " << temp->passportNum << endl << endl;
			temp = temp->nextptr;
		}
	}
};

int hashFunc(string BD)
{
	string digits;
	int i = 0;
	char s = BD[i];
	while (s != '\0')
	{
		if (s != '.')
			digits += s;
		i++;
		s = BD[i];
	}
	long long k;
	k = stoll(digits);
	double fractionalPart = fmod(k * 0.6180339887, 1.0);

	int hashValue = static_cast<int>(100 * fractionalPart);

	return hashValue;
}

void inputData(string*& mass)
{
	cout << "Введите ФИО: ";
	cin.ignore();
	getline(cin, mass[0]);

	cout << "Введите дату рождения: ";
	getline(cin, mass[1]);

	cout << "Введите номер паспорта: ";
	getline(cin, mass[2]);
}

void saveToFile(List* hashTable[], const char* filename) {
	FILE* file = fopen(filename, "w");
	if (!file) {
		perror("Ошибка открытия файла для записи");
		return;
	}

	for (int i = 0; i < 100; i++) {
		Node* current = hashTable[i]->head;
		while (current) {
			string line = current->fullName + "|" +
				current->birthDate + "|" +
				current->passportNum + "\n";
			fputs(line.c_str(), file);
			current = current->nextptr;
		}
	}
	fclose(file);
}

void loadFromFile(List* hashTable[], const char* filename)
{
	FILE* file = fopen(filename, "r");
	if (!file) {
		perror("Ошибка открытия файла для чтения");
		return;
	}

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file))
	{
		string line(buffer);
		line.erase(line.find_last_not_of("\n\r") + 1);

		string* mass = new string[3];
		size_t pos1 = line.find('|');
		size_t pos2 = line.find('|', pos1 + 1);

		if (pos1 != string::npos && pos2 != string::npos)
		{
			mass[0] = line.substr(0, pos1);
			mass[1] = line.substr(pos1 + 1, pos2 - pos1 - 1);
			mass[2] = line.substr(pos2 + 1);

			int number = hashFunc(mass[1]);
			hashTable[number]->append(mass);
		}
		delete[] mass;
	}
	fclose(file);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");

	int counterCAl = 0;
	List* hashTable[100];
	for (int i = 0; i < 100; i++)
	{
		hashTable[i] = new List;
	}
	loadFromFile(hashTable, "data.txt");

	bool flag = true;
	while (flag)
	{
		cout << "Желаете-ли вы добавать данные в хеш таблицу?(да/нет): ";
		string answer;
		cin >> answer;
		if (answer == "да")
		{
			string* mass = new string[3];
			inputData(mass);
			int number = hashFunc(mass[1]);
			hashTable[number]->append(mass);
		}
		else flag = false;
	}

	flag = true;
	while (flag)
	{
		cout << "Желаете-ли проверить наличие человека в таблице?(да/нет): ";
		string answer;
		cin >> answer;
		if (answer == "да")
		{
			string* mass = new string[3];
			inputData(mass);
			int number = hashFunc(mass[1]);
			bool findFlag = false;
			for (Node* temp = hashTable[number]->head; (temp != nullptr) && !findFlag; temp->nextptr)
			{
				if ((mass[0] == temp->fullName) && (mass[2] == temp->passportNum))
				{
					cout << "Человек найден!" << endl;
					findFlag = true;
				}
			}
			if (!findFlag)
				cout << "Человек не найден!" << endl;
		}
		else flag = false;
	}

	flag = true;
	while (flag)
	{
		cout << "Желаете-ли удалить человека из таблицы?(да/нет): ";
		string answer;
		cin >> answer;
		if (answer == "да")
		{
			string* mass = new string[3];
			inputData(mass);
			int number = hashFunc(mass[1]);
			if (hashTable[number]->pop(mass))
				cout << "Человек успешно удален!" << endl;
			else cout << "Человек не найден!" << endl;
		}
		else flag = false;
	}

	flag = true;
	while (flag)
	{
		cout << "Желаете-ли просмотреть таблицу?(да/нет): ";
		string answer;
		cin >> answer;
		if (answer == "да")
		{
			for (int i = 0; i < 100; i++)
			{
				cout << i << ":" << endl;
				if (hashTable[i]->size > 0)
					counterCAl += hashTable[i]->size - 1;
				Node* temp = hashTable[i]->head;
				if (temp)
				{
					for (temp; temp != nullptr; temp = temp->nextptr)
					{
						cout << "Полное имя: " << temp->fullName << endl;
						cout << "Дата рождения: " << temp->birthDate << endl;
						cout << "Номер паспорта: " << temp->passportNum << endl;
					}
				}
				else { cout << "Строка Пуста"; }
				cout << endl;
			}
			flag = false;
		}
		else flag = false;
	}

	cout << endl << "Таблица содержит " << counterCAl << " колизий!";

	saveToFile(hashTable, "data.txt");

	for (int i = 0; i < 100; i++) {
		delete hashTable[i];
	}


	return 0;
}

