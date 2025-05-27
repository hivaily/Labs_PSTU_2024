#include <iostream>
#include <deque>
#include <vector>
#include <stack>
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

    bool operator<(const Money& other) const {
        return (rubles < other.rubles) ||
            (rubles == other.rubles && kopecks < other.kopecks);
    }

    Money(long r = 0, int k = 0) : rubles(r), kopecks(k) {
        normalize();
    }

    bool operator==(const Money& other) const {
        return rubles == other.rubles && kopecks == other.kopecks;
    }

    bool operator!=(const Money& other) const {
        return !(*this == other);
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
    deque<int> dq = { 5, 2, 8, 3, 1 };
    cout << "Original :";
    for (int n : dq) cout << n << " ";
    cout << endl;
    auto max_it = max_element(dq.begin(), dq.end());
    if (max_it != dq.end()) {
        dq.push_back(*max_it);
    }

    cout << "Result 1: ";
    for (int n : dq) cout << n << " ";
    cout << endl;
}

void task2() {
    cout << "\n=== Task 2 ===" << endl;
    vector<Money> vm = { Money(10,50), Money(5,75), Money(15,25) };
    cout << "Original: ";
    for (const Money& m : vm) cout << m << " ";
    cout << endl;
    Money key(5, 75);
    vm.erase(remove(vm.begin(), vm.end(), key), vm.end());

    cout << "Result 2: ";
    for (const Money& m : vm) cout << m << " ";
    cout << endl;
}

template <typename T>
class MyVector {
    vector<T> data;
public:
    void add(const T& item) { data.push_back(item); }

    void addAverageToEach() {
        if (data.empty()) return;

        T sum = accumulate(data.begin(), data.end(), T());
        T avg = sum / data.size();

        for (auto& item : data) {
            item = item + avg;
        }
    }

    void print() const {
        for (const auto& item : data) cout << item << " ";
        cout << endl;
    }
};

void task3() {
    cout << "\n=== Task 3 ===" << endl;
    MyVector<int> mv;
    mv.add(10); mv.add(20); mv.add(30);
    cout << "Original for int: ";
    mv.print();
    mv.addAverageToEach();
    cout << "Result 3 (int): ";
    mv.print();

    MyVector<Money> moneyVec;
    moneyVec.add(Money(10, 50)); moneyVec.add(Money(20, 75));

    cout << "Original for money: ";
    moneyVec.print();

    moneyVec.addAverageToEach();
    cout << "Result 3 (Money): ";
    moneyVec.print();
}

void task4() {
    cout << "\n=== Task 4 ===" << endl;
    stack<Money> sm;
    sm.push(Money(10, 50));
    sm.push(Money(5, 75));
    sm.push(Money(15, 25));

    
    vector<Money> temp;
    while (!sm.empty()) {
        temp.push_back(sm.top());
        sm.pop();
    }
    cout << "Original: ";
    for (const Money& m : temp) cout << m << " ";
    cout << endl;



    auto max_it = max_element(temp.begin(), temp.end());
    if (max_it != temp.end()) {
        temp.push_back(*max_it);
    }

    for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
        sm.push(*it);
    }

    cout << "Result : ";
    vector<Money> temp2;
    while (!sm.empty()) {
        temp2.push_back(sm.top());
        sm.pop();
    }
    for (const Money& m : temp2) cout << m << " ";
    cout << endl;
}

template <typename T>
class StackContainer {
    stack<T> data;
public:
    void push(const T& item) { data.push(item); }

    void addAverageToEach() {
        if (data.empty()) return;

        vector<T> temp;
        while (!data.empty()) {
            temp.push_back(data.top());
            data.pop();
        }

        T sum = accumulate(temp.begin(), temp.end(), T());
        T avg = sum / temp.size();

        for (auto& item : temp) {
            item = item + avg;
            data.push(item);
        }
    }

    void print() {
        stack<T> temp = data;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

void task5() {
    cout << "\n=== Task 5 ===" << endl;
    StackContainer<Money> sc;
    sc.push(Money(10, 50));
    sc.push(Money(20, 75));
    cout << "Original: ";
    sc.print();
    sc.addAverageToEach();
    cout << "Result : ";
    sc.print();
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    return 0;
}