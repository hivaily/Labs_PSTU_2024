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

void keyadd(Node*& head, string key, int k)
{
    Node* cur = head;
    Node* rightcur = nullptr;
    Node* leftcur = nullptr;
    Node* tmpcur = nullptr;
    int temp = -1;
    string tkey;
    for ( int i = 0; i < lsize; i++)
    {
        if (cur->key == key) { temp = i; break; }
        leftcur = cur;
        cur = cur->next;
    }
    rightcur = cur->next;

    if (leftcur == nullptr)
    {
        for (size_t i = 0; i < k; i++)
        {
            cout << "Input key for new node before key node" << "\n";
            cin >> tkey;
            Node* newNode = new Node{ tkey, head };
            head = newNode;
        }

        for (size_t i = 0; i < k; i++)
        {
            cout << "Input key for new node after key node" << "\n";
            cin >> tkey;
            Node* newNode = new Node{ tkey, cur->next };
            cur->next = newNode;
            cur = cur->next;
        }

        return;
    }

    if (rightcur == nullptr)
    {
        for (size_t i = 0; i < k; i++)
        {
            cout << "Input key for new node before key node" << "\n";
            cin >> tkey;
            Node* newNode = new Node{ tkey, cur };
            leftcur = newNode;
        }

        for (size_t i = 0; i < k; i++)
        {
            cout << "Input key for new node after key node" << "\n";
            cin >> tkey;
            Node* newNode = new Node{ tkey, cur->next };
            cur->next = newNode;
            cur = cur->next;
        }
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
    for (int j = 0; j < i - 1 ; j++)
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
    add(list, "!");
    add(list, "maganera");
    add(list, "cha");
    print(list);
    keyadd(list,"!",2);
    print(list);


    return 0;
}

