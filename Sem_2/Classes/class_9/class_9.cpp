#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class IntSet {
private:
    std::vector<int> elements;

    bool isUnique(int value) const {
        return std::find(elements.begin(), elements.end(), value) == elements.end();
    }

public:
    IntSet() = default;
    IntSet(std::initializer_list<int> init) {
        for (int value : init) {
            add(value);
        }
    }

    void add(int value) {
        if (isUnique(value)) {
            elements.push_back(value);
            std::sort(elements.begin(), elements.end());
        }
    }

    bool contains(int value) const {
        return std::binary_search(elements.begin(), elements.end(), value);
    }

    size_t size() const {
        return elements.size();
    }

    int operator[](size_t index) const {
        if (index >= elements.size()) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    bool operator!=(const IntSet& other) const {
        return elements != other.elements;
    }

    bool operator<(int value) const {
        return contains(value);
    }

    IntSet operator+(size_t n) const {
        if (n > elements.size()) {
            throw std::out_of_range("Index out of range");
        }

        IntSet result;
        for (size_t i = n; i < elements.size(); ++i) {
            result.add(elements[i]);
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const IntSet& set) {
        os << "{ ";
        for (int elem : set.elements) {
            os << elem << " ";
        }
        os << "}";
        return os;
    }
};

int main() {
    try {
        IntSet set1 = { 5, 3, 7, 2, 8 };
        std::cout << "Set 1: " << set1 << std::endl;

        std::cout << "set1[2] = " << set1[2] << std::endl;

        IntSet set2 = { 2, 3, 5, 7, 8 };
        std::cout << "set1 != set2: " << (set1 != set2) << std::endl;

        std::cout << "5 ∈ set1: " << (set1 < 5) << std::endl;
        std::cout << "4 ∈ set1: " << (set1 < 4) << std::endl;

        IntSet set3 = set1 + 2;
        std::cout << "set1 + 2: " << set3 << std::endl;

        try {
            std::cout << "Trying to get set1[10]: ";
            std::cout << set1[10] << std::endl;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        try {
            std::cout << "Trying set1 + 10: ";
            IntSet set4 = set1 + 10;
            std::cout << set4 << std::endl;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}