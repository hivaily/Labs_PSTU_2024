#include <iostream>
using namespace std;
/* var 24
 Записи в линейном списке содержат ключевое поле типа
 *char(строка символов). Сформировать списки-стек-очередь. Удалить элемент с заданным номером. Добавить по
 К элементов перед и после элемента с заданным ключом. */

struct Node 
{
    string key;
    Node* next;
};

int lsize = 0;

void push(Node*& head, const string& key) 
{
    Node* newNode = new Node{ key, head };
    head = newNode;
    lsize++;
}

string pop(Node*& head) 
{
    if (!head) 
    {
        cerr << "Stack underflow!" << endl;
        return "";
    }
    Node* temp = head;
    string key = temp->key;
    head = head->next;
    delete temp;
    lsize--;
    return key;
}

void print(Node* head)
{
    Node* current = head;
    while (current) 
    {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

struct TempStack 
{
    Node* top = nullptr;
    void push(const string& key) 
    {
        Node* newNode = new Node{ key, top };
        top = newNode;
    }
    string pop() 
    {
        if (!top) return "";
        Node* temp = top;
        string key = temp->key;
        top = top->next;
        delete temp;
        return key;
    }
    bool isEmpty() 
    {
        return top == nullptr;
    }
};

void keyadd(Node*& head, const string& tkey, int K)
{
    TempStack temp;
    bool found = false;
    while (head) 
    {
        string key = pop(head);
        temp.push(key);
        if (key == tkey)
        {
            found = true;
            break;
        }
    }

    if (!found) 
    {
        cout << "No node with that key found!" << '\n';
        while (!temp.isEmpty()) 
        {
            push(head, temp.pop());
        }
        return;
    }

    for (int i = 0; i < K; ++i) 
    {
        string newKey;
        cout << "Input key for new node after key node" << "\n";
        cin >> newKey;
        push(head, newKey);
    }
    push(head, tkey);
    for (int i = 0; i < K; ++i) 
    {
        string newKey;
        cout << "Input key for new node before key node" << "\n";
        cin >> newKey;
        push(head, newKey);
    }
    temp.pop();
    while (!temp.isEmpty()) push(head, temp.pop());
  
}

void remove(Node*& head, int n)
{
    if (n < 0 || n >= lsize) 
    {
        cerr << "Index out of range!" << '\n';
        return;
    }
    TempStack temp;
    for (int i = 0; i < n; ++i) 
    {
        temp.push(pop(head));
    }
    Node* target = head;
    head = head->next;
    delete target;
    lsize--;
    while (!temp.isEmpty()) push(head, temp.pop());
}

int main() 
{
    Node* stack = nullptr;
    push(stack, "future");
    push(stack, "the");
    push(stack, "build");
    push(stack, "fear");
    push(stack, "the");
    push(stack, "face");
    print(stack);
    remove(stack, 2);
    print(stack); 
    keyadd(stack, "build", 2); 
    print(stack); 

    return 0;
}