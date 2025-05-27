#include <iostream>
#include <deque>
#include <vector>
#include <set>
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

    bool operator>(const Money& other) const {
        return other < *this;
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
    deque<Money> dm = { Money(10,50), Money(5,75), Money(15,25), Money(10,50) };
    cout << "Original: ";

    for_each(dm.begin(), dm.end(), [](const Money& m) { cout << m << " "; });
    cout << endl;

    replace(dm.begin(), dm.end(), Money(10, 50), Money(20, 00));
    cout << "Replace 10,50 with 20,00: \n";
    for_each(dm.begin(), dm.end(), [](const Money& m) { cout << m << " "; });
    cout << endl;

    dm.erase(remove(dm.begin(), dm.end(), Money(5, 75)), dm.end());
    cout << "Delete 5,75: \n";
    for_each(dm.begin(), dm.end(), [](const Money& m) { cout << m << " "; });
    cout << endl;

    sort(dm.begin(), dm.end());
    cout << "Sorted ascending : \n";
    for_each(dm.begin(), dm.end(), [](const Money& m) { cout << m << " "; });
    cout << endl;


    sort(dm.begin(), dm.end(), greater<Money>());
    cout << "Sorted deascending:\n";
    for_each(dm.begin(), dm.end(), [](const Money& m) { cout << m << " "; });
    cout << endl;

    auto it = find(dm.begin(), dm.end(), Money(15, 25));
    if (it != dm.end()) {
        cout << "Element found: " << *it << endl;
    }

    if (!dm.empty()) {
        Money max_val = *max_element(dm.begin(), dm.end());
        dm.push_back(max_val);
        cout << "After adding max:\n";
        for_each(dm.begin(), dm.end(), [](const Money& m) { cout << m << " "; });
        cout << endl;
    }
}


template<typename T>
class MyVector {
    vector<T> data;
public:
    void add(const T& item) { data.push_back(item); }

    void replaceAll(const T& old_val, const T& new_val) {
        replace(data.begin(), data.end(), old_val, new_val);
    }

    void removeAll(const T& val) {
        data.erase(remove(data.begin(), data.end(), val), data.end());
    }

    void sortAscending() {
        sort(data.begin(), data.end());
    }

    void sortDescending() {
        sort(data.begin(), data.end(), greater<T>());
    }

    void addAverageToEach() {
        if (data.empty()) return;
        T sum = accumulate(data.begin(), data.end(), T());
        T avg = sum / static_cast<int>(data.size());
        for_each(data.begin(), data.end(), [avg](T& item) { item = item + avg; });
    }

    void print() const {
        for_each(data.begin(), data.end(), [](const T& item) { cout << item << " "; });
        cout << endl;
    }
};

void task2() {
    cout << "\n=== Task 2 ===" << endl;
    MyVector<Money> mv;
    mv.add(Money(10, 50)); mv.add(Money(5, 75)); mv.add(Money(15, 25));

    cout << "Original:\n";
    mv.print();

    mv.addAverageToEach();
    cout << "After adding mean:\n";
    mv.print();
    cout << "Sorted ascending:\n";
    mv.sortAscending();
    mv.print();
    cout << "Sorted descending:\n";
    mv.sortDescending();
    mv.print();

}


void task3() {
    cout << "\n=== Task 3 ===" << endl;
    set<Money> sm = { Money(10,50), Money(5,75), Money(15,25) };
    cout << "Original: ";
    for_each(sm.begin(), sm.end(), [](const Money& m) { cout << m << " "; });
    cout << endl;

    sm.erase(Money(5, 75));
    cout << "After deleting 5,75:\n";
    for_each(sm.begin(), sm.end(), [](const Money& m) { cout << m << " "; });
    cout << endl;


    auto it = sm.find(Money(10, 50));
    if (it != sm.end()) {
        cout << "Element found: " << *it << endl;
    }

    if (!sm.empty()) {
        Money max_val = *sm.rbegin();
        sm.insert(max_val);
        cout << "After adding max:\n";
        for_each(sm.begin(), sm.end(), [](const Money& m) { cout << m << " "; });
        cout << endl;
    }

}

int main() {
    task1();
    task2();
    task3();
    return 0;
}