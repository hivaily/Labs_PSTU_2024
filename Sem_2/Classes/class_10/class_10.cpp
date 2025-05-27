#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class Money {
private:
    long rubles;
    int kopecks;

    void normalize() {
        rubles += kopecks / 100;
        kopecks %= 100;
        if (kopecks < 0) {
            rubles--;
            kopecks += 100;
        }
        if (rubles < 0) {
            rubles = 0;
            kopecks = 0;
        }
    }

public:
    Money(long r = 0, int k = 0) : rubles(r), kopecks(k) {
        normalize();
    }

    bool operator==(const Money& other) const {
        return rubles == other.rubles && kopecks == other.kopecks;
    }

    bool operator!=(const Money& other) const {
        return !(*this == other);
    }

    Money operator-(double value) const {
        int totalKopecks = rubles * 100 + kopecks;
        int subtractKopecks = static_cast<int>(value * 100 + 0.5);
        totalKopecks -= subtractKopecks;
        return Money(totalKopecks / 100, totalKopecks % 100);
    }

    friend ostream& operator<<(ostream& os, const Money& money) {
        os << money.rubles << "," << setw(2) << setfill('0') << money.kopecks;
        return os;
    }

    friend istream& operator>>(istream& is, Money& money) {
        char comma;
        is >> money.rubles >> comma >> money.kopecks;
        if (comma != ',') {
            is.setstate(ios::failbit);
        }
        money.normalize();
        return is;
    }
    void decrease() {
        *this = *this - 1.5;
    }
};

void saveToFile(const vector<Money>& data, const string& filename) {
    ofstream out(filename, ios::binary);
    if (!out) {
        cerr << "Error" << endl;
        return;
    }
    for (const auto& money : data) {
        out.write(reinterpret_cast<const char*>(&money), sizeof(Money));
    }
    out.close();
}

vector<Money> readFromFile(const string& filename) {
    vector<Money> data;
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "Error" << endl;
        return data;
    }
    Money money;
    while (in.read(reinterpret_cast<char*>(&money), sizeof(Money))) {
        data.push_back(money);
    }
    in.close();
    return data;
}

void printAll(const vector<Money>& data) {
    cout << "Data:" << endl;
    for (size_t i = 0; i < data.size(); ++i) {
        cout << i + 1 << ": " << data[i] << endl;
    }
}

void deleteByValue(vector<Money>& data, const Money& value) {
    data.erase(remove(data.begin(), data.end(), value), data.end());
}

void decreaseByValue(vector<Money>& data, const Money& value) {
    for (auto& money : data) {
        if (money == value) {
            money.decrease();
        }
    }
}

void insertAfterValue(vector<Money>& data, const Money& value, int k) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (*it == value) {
            data.insert(it + 1, k, Money(0, 0));
            break;
        }
    }
}

Money inputMoney() {
    Money money;
    cout << "Input money (rub,kop): ";
    cin >> money;
    cin.ignore();
    return money;
}

int main() {
    vector<Money> data;
    string filename = "money.dat";
    int choice;

    while (true) {
        cout << "\nМеню:\n"
            << "1. Add data\n"
            << "2. Show data\n"
            << "3. Save\n"
            << "4. Load\n"
            << "5. Delete data by key\n"
            << "6. Decrease all data by 1.50\n"
            << "7. Add K elements after key\n"
            << "8. Exit\n"
            << "Choose: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            Money money = inputMoney();
            data.push_back(money);
            break;
        }
        case 2:
            printAll(data);
            break;
        case 3:
            saveToFile(data, filename);
            cout << "Saved" << endl;
            break;
        case 4:
            data = readFromFile(filename);
            cout << "Loaded" << endl;
            break;
        case 5: {
            Money value = inputMoney();
            deleteByValue(data, value);
            cout << "Deleted" << endl;
            break;
        }
        case 6: {
            Money value = inputMoney();
            decreaseByValue(data, value);
            cout << "Decreased 1.50" << endl;
            break;
        }
        case 7: {
            Money value = inputMoney();
            int k;
            cout << "Input K: ";
            cin >> k;
            cin.ignore();
            insertAfterValue(data, value, k);
            cout << "Added " << k << " data" << endl;
            break;
        }
        case 8:
            return 0;
        default:
            cout << "Error" << endl;
        }
    }
}