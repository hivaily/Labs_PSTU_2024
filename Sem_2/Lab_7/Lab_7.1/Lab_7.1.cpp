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
};

void add(Node*& head, string key)
{
    Node* newNode = new Node{ key, head };
    head = newNode;
    lsize++;
}

void keyadd(Node*& head, const string& key, int K) {

    Node* cur = head;
    Node* prev = nullptr;
    int tmp = -1;
    for (int i = 0; i < lsize; i++)
    {
        if (cur->key == key) { tmp = i; break; }
        prev = cur;
        cur = cur->next;
    }
    if (tmp == -1) { cout << "No node with that key found!" << '\n'; return; }

    for (int i = 0; i < K; ++i)
    {
        string newData;
        cout << "Input key for new node before key node" << "\n";
        cin >> newData;

        Node* newNode = new Node{ newData, cur };

        if (prev) prev->next = newNode;
        else head = newNode;
        prev = newNode;
    }

    for (int i = 0; i < K; ++i) 
    {
        string newData;
        cout << "Input key for new node after key node" << "\n";
        cin >> newData;
        Node* newNode = new Node{ newData, cur->next };
        cur->next = newNode;
        cur = newNode;
    }
}


void remove(Node*& head, int i)
{
    if (i >= lsize)
    {
        cout << "No node with that index" << "\n";
        return;
    }

    if (i == 0)
    {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }

    Node* cur = head;
    for (int j = 0; j < i - 1; j++)
    {
        cur = cur->next;
    }

    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
    lsize--;
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
    add(list, "future");
    add(list, "the");
    add(list, "build");
    add(list, "fear");
    add(list, "the");
    add(list, "face");
    print(list);
    remove(list, 3);
    print(list);
    keyadd(list, "fear", 2);
    print(list);


    return 0;
}

