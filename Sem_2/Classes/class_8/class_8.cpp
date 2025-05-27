#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <stdexcept>

using namespace std;

class Print {
protected:
    string title;
    string author;

public:
    Print(const string& t, const string& a) : title(t), author(a) {}
    virtual ~Print() = default;

    virtual void printInfo() const = 0;
    virtual void inputInfo() = 0;

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }

    Print& operator=(const Print& other) {
        if (this != &other) {
            title = other.title;
            author = other.author;
        }
        return *this;
    }
};

class Book : public Print {
private:
    int pageCount;
    string publisher;

public:
    Book(const string& t = "", const string& a = "", int pc = 0, const string& p = "")
        : Print(t, a), pageCount(pc), publisher(p) {}

    void printInfo() const override {
        cout << "Book: " << title << "\nAuthor: " << author
            << "\nPages: " << pageCount << "\nPublisher: " << publisher << endl;
    }

    void inputInfo() override {
        cout << "Input name of the book: ";
        getline(cin, title);
        cout << "Input author of the book: ";
        getline(cin, author);
        cout << "Input number of pages: ";
        cin >> pageCount;
        cin.ignore();
        cout << "Input publisher: ";
        getline(cin, publisher);
    }

    int getPageCount() const { return pageCount; }
    string getPublisher() const { return publisher; }
    void setPageCount(int pc) { pageCount = pc; }
    void setPublisher(const string& p) { publisher = p; }
};

template <typename T>
class Group {
protected:
    vector<shared_ptr<T>> items;

public:
    Group() = default;
    ~Group() = default;

    void addItem(shared_ptr<T> item) {
        items.push_back(item);
    }

    void removeItem(size_t index) {
        if (index >= items.size()) {
            throw out_of_range("Wrong index");
        }
        items.erase(items.begin() + index);
    }

    void printGroup() const {
        for (size_t i = 0; i < items.size(); ++i) {
            cout << "Element #" << i + 1 << ":\n";
            items[i]->printInfo();
            cout << endl;
        }
    }

    size_t size() const {
        return items.size();
    }

    shared_ptr<T> operator[](size_t index) const {
        if (index >= items.size()) {
            throw out_of_range("Wrong index");
        }
        return items[index];
    }
};

class Dialog : public Group<Book> {
public:
    void handleCommand(const string& command) {
        try {
            if (command == "m") {
                int count;
                cout << "Input amount of elements: ";
                cin >> count;
                cin.ignore();

                for (int i = 0; i < count; ++i) {
                    auto book = make_shared<Book>();
                    book->inputInfo();
                    addItem(book);
                }
            }
            else if (command == "+") {
                auto book = make_shared<Book>();
                book->inputInfo();
                addItem(book);
            }
            else if (command == "-") {
                size_t index;
                cout << "Input index to delete: ";
                cin >> index;
                cin.ignore();
                removeItem(index - 1);
            }
            else if (command == "s") {
                printGroup();
            }
            else if (command[0] == 'z') {
                size_t index = stoi(command.substr(2)) - 1;
                if (index < items.size()) {
                    cout << " #" << index + 1 << ": "
                        << items[index]->getTitle() << endl;
                }
                else {
                    cout << "Wrong index" << endl;
                }
            }
            else if (command == "q") {
                // Выход
                cout << "Shutting down." << endl;
                exit(0);
            }
            else {
                cout << "Unknown command" << endl;
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
};

int main() {
    Dialog dialog;
    string command;

    cout << "Avaiable commands:\n"
        << "m - create group\n"
        << "+ - add element\n"
        << "- - delete element\n"
        << "s - show group\n"
        << "z k - show element with index k\n"
        << "q - quit\n";

    while (true) {
        cout << "\nInput command: ";
        getline(cin, command);
        dialog.handleCommand(command);
    }

    return 0;
}