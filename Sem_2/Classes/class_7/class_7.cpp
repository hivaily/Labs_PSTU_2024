#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

template <typename T>
class Set {
private:
    vector<T> elements;

public:
    Set() = default;
    Set(const initializer_list<T>& init) {
        for (const auto& item : init) {
            add(item);
        }
    }

    void add(const T& value) {
        if (!contains(value)) {
            elements.push_back(value);
            sort(elements.begin(), elements.end());
        }
    }

    bool contains(const T& value) const {
        return binary_search(elements.begin(), elements.end(), value);
    }

    T operator[](size_t index) const {
        if (index >= elements.size()) {
            throw out_of_range("Index out of range");
        }
        return elements[index];
    }

    bool operator!=(const Set<T>& other) const {
        return elements != other.elements;
    }

    // Оператор < для проверки принадлежности числа
    bool operator<(const T& value) const {
        return contains(value);
    }

    friend istream& operator>>(istream& is, Set<T>& set) {
        T value;
        is >> value;
        set.add(value);
        return is;
    }

    friend ostream& operator<<(ostream& os, const Set<T>& set) {
        os << "{ ";
        for (const auto& elem : set.elements) {
            os << elem << " ";
        }
        os << "}";
        return os;
    }

    Set<T>& operator=(const Set<T>& other) {
        if (this != &other) {
            elements = other.elements;
        }
        return *this;
    }

    ~Set() = default;
};

class Money {
private:
    long rubles;
    int kopecks;

public:
    Money() : rubles(0), kopecks(0) {}
    Money(long r, int k) : rubles(r), kopecks(k) {
        normalize();
    }

    void normalize() {
        rubles += kopecks / 100;
        kopecks %= 100;
        if (kopecks < 0) {
            rubles--;
            kopecks += 100;
        }
    }

    bool operator==(const Money& other) const {
        return rubles == other.rubles && kopecks == other.kopecks;
    }

    bool operator!=(const Money& other) const {
        return !(*this == other);
    }

    bool operator<(const Money& other) const {
        if (rubles != other.rubles) {
            return rubles < other.rubles;
        }
        return kopecks < other.kopecks;
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

    friend ostream& operator<<(ostream& os, const Money& money) {
        os << money.rubles << "," << (money.kopecks < 10 ? "0" : "") << money.kopecks;
        return os;
    }
};

int main() {

    Set<int> intSet = { 5, 3, 7, 2 };
    cout << "Set: " << intSet << endl;

    cout << "intSet[1] = " << intSet[1] << endl;
    cout << "3 in set: " << (intSet < 3) << endl;
    cout << "4 in set: " << (intSet < 4) << endl;

    Set<int> intSet2 = { 2, 3, 5, 7 };
    cout << "intSet != intSet2: " << (intSet != intSet2) << endl;

    Set<float> floatSet = { 3.14f, 2.71f, 1.41f };
    cout << "Set: " << floatSet << endl;
    cout << "2.71 in set: " << (floatSet < 2.71f) << endl;
    Set<double> doubleSet = { 1.618, 3.14159 };
    cout << "Set: " << doubleSet << endl;
    cout << "3.14159 in set: " << (doubleSet < 3.14159) << endl;
    Set<Money> moneySet = { Money(10, 50), Money(5, 75), Money(20, 0) };
    cout << "Set: " << moneySet << endl;

    Money m1(5, 75);
    cout << m1 << " in set: " << (moneySet < m1) << endl;

    Money m2(7, 30);
    cout << m2 << " in set: " << (moneySet < m2) << endl;

    cout << "moneySet[0] = " << moneySet[0] << endl;

    Set<Money> moneySet2;
    cout << "\nEnter money in format 'rubles,kopecks' (e.g. 15,30): ";
    cin >> moneySet2;
    cout << "You entered: " << moneySet2 << endl;

    return 0;
}

