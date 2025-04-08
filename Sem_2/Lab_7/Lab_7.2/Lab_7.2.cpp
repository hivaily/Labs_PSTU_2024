#include <iostream>
using namespace std;
/* var 24
 Записи в линейном списке содержат ключевое поле типа
 *char(строка символов). Сформировать списки-стек-очередь. Удалить элемент с заданным номером. Добавить по
 К элементов перед и после элемента с заданным ключом. */

int lsize = 0;

struct Node
{
    string key;
    Node* next;
    Node* prev;

};


void add(Node*& head, Node*& tail, string value)
{
    Node* newNode = new Node{ value, head, tail };
    if (head) head->prev = newNode;
    else tail = newNode;
    head = newNode;
    lsize++;
}


void keyadd(Node*& head, Node*& tail, string key, int K) {
    Node* cur = head;
    int tmp = -1;

    for (int i = 0; i < lsize; i++)
    {
        if (cur->key == key) { tmp = i; break; }
        cur = cur->next;
    }
    if (tmp == -1) { cout << "No node with that key found!" << '\n'; return; }

    for (int i = 0; i < K; ++i) {
        string tkey;
        cout << "Input key for new node before key node" << "\n";
        cin >> tkey;
        Node* newNode = new Node{ tkey, cur, cur->prev };

        if (cur->prev) cur->prev->next = newNode;
        else head = newNode; 
        cur->prev = newNode;
    }

    for (int i = 0; i < K; ++i) {
        string tkey;
        cout << "Input key for new node after key node" << "\n";
        cin >> tkey;

        Node* newNode = new Node{ tkey, cur->next, cur };

        if (cur->next) {
            cur->next->prev = newNode;
        }
        else {
            tail = newNode;  
        }
        cur->next = newNode;
    }
}


void remove(Node*& head, Node*& tail, int pos)
{
    if (!head) return;
    Node* current = head;
    for (int i = 0; current && i < pos; i++)
    {
        current = current->next;
    }
    if (!current) return;
    if (current->prev) current->prev->next = current->next;
    else head = current->next;
    if (current->next) current->next->prev = current->prev;
    else tail = current->prev;
    lsize--;
    delete current;
}


void print(Node* head)
{
    while (head)
    {
        cout << head->key << " ";
        head = head->next;

    }
    cout << "\n";
}



void clear(Node*& head)
{
    while (head)
    {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}


int main()
{

    Node* list = nullptr;
    Node* listtail = nullptr;
    add(list, listtail, "future");
    add(list, listtail, "the");
    add(list, listtail, "build");
    add(list, listtail, "fear");
    add(list, listtail, "the");
    add(list, listtail, "face");
    print(list);
    remove(list, listtail, 2);
    print(list);
    keyadd(list, listtail, "build", 2);
    print(list);






    return 0;
}

