#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
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
    }

public:
    Money(long r = 0, int k = 0) : rubles(r), kopecks(k) {
        normalize();
    }

    bool operator<(const Money& other) const {
        return (rubles < other.rubles) ||
            (rubles == other.rubles && kopecks < other.kopecks);
    }

    bool operator==(const Money& other) const {
        return rubles == other.rubles && kopecks == other.kopecks;
    }

    Money operator+(const Money& other) const {
        return Money(rubles + other.rubles, kopecks + other.kopecks);
    }

    Money operator/(int divisor) const {
        int total = rubles * 100 + kopecks;
        total /= divisor;
        return Money(total / 100, total % 100);
    }

    friend ostream& operator<<(ostream& os, const Money& money) {
        os << money.rubles << "," << setw(2) << setfill('0') << money.kopecks;
        return os;
    }

    friend istream& operator>>(istream& is, Money& money) {
        char comma;
        is >> money.rubles >> comma >> money.kopecks;
        money.normalize();
        return is;
    }
};


void task1() {
    cout << "\n=== Task 1 ===" << endl;
    set<int> si = { 5, 2, 8, 3, 1 };
    
    cout << "Original : ";
    for (int n : si) cout << n << " ";
    cout << endl;

    if (!si.empty()) {
        int max_val = *si.rbegin();
        si.insert(max_val);
    }

    cout << "Result : ";
    for (int n : si) cout << n << " ";
    cout << endl;
}


void task2() {
    cout << "\n=== Task 2 ===" << endl;
    set<Money> sm = { Money(10,50), Money(5,75), Money(15,25) };

    for (const Money& m : sm) cout << m << " ";
    cout << endl;

    Money key(5, 75);
    sm.erase(key);

    cout << "Result: ";
    for (const Money& m : sm) cout << m << " ";
    cout << endl;
}


template <typename T>
class MyAssocContainer {
    set<T> data;
public:
    void add(const T& item) { data.insert(item); }

    void addAverageToEach() {
        if (data.empty()) return;

        T sum = accumulate(data.begin(), data.end(), T());
        T avg = sum / static_cast<int>(data.size());

        set<T> new_data;
        for (const auto& item : data) {
            new_data.insert(item + avg);
        }
        data = new_data;
    }

    void print() const {
        for (const auto& item : data) cout << item << " ";
        cout << endl;
    }
};

void task3() {
    cout << "\n=== Task 3 ===" << endl;

    MyAssocContainer<int> maci;
    maci.add(10); maci.add(20); maci.add(30);

    cout << "Before for int: ";
    maci.print();

    maci.addAverageToEach();
    cout << "After for int: ";
    maci.print();

    MyAssocContainer<Money> macm;
    macm.add(Money(10, 50)); macm.add(Money(20, 75));

    cout << "Before for money: ";
    macm.print();

    macm.addAverageToEach();
    cout << "After for money: ";
    macm.print();
}

int main() {
    task1();
    task2();
    task3();
    return 0;
}