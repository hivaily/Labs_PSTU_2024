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

struct Queue 
{
    Node* front = nullptr;
    Node* rear = nullptr;
};

void enqueue(Queue& q, const string& key)
{
    Node* newNode = new Node{ key, nullptr };
    if (q.rear) q.rear->next = newNode;
    else q.front = newNode;
    q.rear = newNode;
    lsize++;
}


string dequeue(Queue& q) 
{
    Node* temp = q.front;
    string key = temp->key;
    q.front = q.front->next;
    if (!q.front) q.rear = nullptr;
    delete temp;
    lsize--;
    return key;
}

void keyadd(Queue& q, const string& tkey, int K) 
{
    Queue temp;
    bool found = false;
    int size = lsize;
    for (int i = 0; i < size; i++) 
    {
        string key = dequeue(q);
        if (key == tkey) 
        {
            found = true;
            for (int j = 0; j < K; ++j) 
            {
                string newKey;
                cout << "Input key for new node before key node" << "\n";
                cin >> newKey;
                enqueue(temp, newKey);
            }

            enqueue(temp, key);
            for (int j = 0; j < K; ++j) 
            {
                string newKey;
                cout << "Input key for new node after key node" << "\n";
                cin >> newKey;
                enqueue(temp, newKey);
            }
        }
        else enqueue(temp, key);
    }

    if (!found) cout << "No node with that key found!" << '\n';
    while (temp.front) enqueue(q, dequeue(temp));
}

void remove(Queue& q, int i) 
{
    if (i < 0 || i >= lsize)
    {
        cout << "Index out of range!" << endl;
        return;
    }
    Queue temp;
    int cur = 0;
    while (cur < i)
    {
        enqueue(temp, dequeue(q));
        cur++;
    }
    Node* del = q.front;
    q.front = q.front->next;
    if (!q.front) q.rear = nullptr;
    delete del;

    lsize--;
    while (q.front) enqueue(temp, dequeue(q));
    while (temp.front) enqueue(q, dequeue(temp));
    
}

void print(Queue& q)
{
    Queue temp;
    while (q.front) 
    {
        string key = dequeue(q);
        cout << key << " ";
        enqueue(temp, key);
    }

    cout << endl;
    while (temp.front) enqueue(q, dequeue(temp));
}

void clear(Queue& q) 
{
    while (q.front)
    {
        Node* temp = q.front;
        q.front = q.front->next;
        delete temp;
    }
    q.rear = nullptr;
    lsize = 0;
}

int main() {
    Queue q;
    enqueue(q, "face");
    enqueue(q, "the");
    enqueue(q, "fear");
    enqueue(q, "build");
    enqueue(q, "the");
    enqueue(q, "future");
    print(q);
    remove(q, 3);
    print(q);
    keyadd(q, "fear", 1); 
    print(q);

    return 0;
}