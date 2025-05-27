#include <iostream>
#include <vector>
#include <algorithm>

class IntSet {
private:
    std::vector<int> elements;

public:
    IntSet() = default;

    void add(int value) {
        if (!contains(value)) {
            elements.push_back(value);
            std::sort(elements.begin(), elements.end());
        }
    }

    bool contains(int value) const {
        return std::binary_search(elements.begin(), elements.end(), value);
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

    class Iterator {
    private:
        const IntSet& set;
        size_t current_index;

    public:
        Iterator(const IntSet& s, size_t index = 0)
            : set(s), current_index(index) {}

        int operator*() const {
            return set[current_index];
        }

        Iterator operator+(size_t n) const {
            return Iterator(set, current_index + n);
        }

        Iterator& operator++() {
            ++current_index;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current_index != other.current_index;
        }
    };

    Iterator begin() const {
        return Iterator(*this, 0);
    }

    Iterator end() const {
        return Iterator(*this, elements.size());
    }

    Iterator operator+(size_t n) const {
        return Iterator(*this, std::min(n, elements.size()));
    }

    void print() const {
        for (int elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    IntSet set1;
    set1.add(5);
    set1.add(3);
    set1.add(7);
    IntSet set2;
    set2.add(3);
    set2.add(5);
    set2.add(7);
    std::cout << "Set1: ";
    set1.print();
    std::cout << "Set2: ";
    set2.print();
    std::cout << "set1 != set2: " << (set1 != set2) << std::endl;
    std::cout << "5 in set1: " << (set1 < 5) << std::endl;
    std::cout << "4 in set1: " << (set1 < 4) << std::endl;
    std::cout << "set1[0]: " << set1[0] << std::endl;
    std::cout << "set1[1]: " << set1[1] << std::endl;
    std::cout << "Iteration: ";
    for (auto it = set1.begin(); it != set1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    auto it = set1.begin();
    std::cout << "Element at position 1: " << *it << std::endl;
    return 0;
}