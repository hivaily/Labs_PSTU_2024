#ifndef TREECLASS_H
#define TREECLASS_H
#include <QMap>
#include <QPoint>
#include <QDebug>
#include <algorithm>
#include <stack>
#include <queue>
extern QString infos;
class Tree
{
public:
    struct Node {
        int key, x, y;
        Node* left;
        Node* right;
        Node(int k) : key(k), left(nullptr), right(nullptr), x(0), y(0) {}
    };

    Tree() : root(nullptr) {}
    ~Tree() { clear(); }

    void balance();
    void insert(int key) { root = insert(root, key); }
    void clear();
    int count() const;
    void remove(int key) { root = remove(root, key); }
    void calculate(int width);
    Node* getRoot() const { return root; }
    bool search(int key) { return search(root, key) != nullptr; }
    void preOrder(Node* node);
    void inOrder(Node* node);
    void postOrder(Node* node);

private:
    Node* root;
    Node* insert(Node* node, int key);
    Node* remove(Node* node, int key);
    Node* search(Node* node, int key) const;
    Node* build(const std::vector<Node*>& nodes, int start, int end);
    void calculate(Node* node, int x, int y, int level, int offset);
    void clear(Node* node);
    void store(Node* node, std::vector<Node*>& nodes);
    int count(Node* node) const;
};

#endif // BINARYTREE_H
