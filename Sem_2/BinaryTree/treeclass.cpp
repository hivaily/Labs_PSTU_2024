#include "treeclass.h"


void Tree::preOrder(Node *node)
{
    if (node == nullptr) return;
    infos += QString::number(node->key) + ' ';
    preOrder(node->left);
    preOrder(node->right);

}

void Tree::inOrder(Node *node)
{
    if (node == nullptr) return;
    inOrder(node->left);
    infos += QString::number(node->key) + ' ';
    inOrder(node->right);

}

void Tree::postOrder(Node *node)
{
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    infos += QString::number(node->key) + ' ';

}



Tree::Node* Tree::insert(Node* node, int key) {
    if (!node) return new Node(key);

    Node* current = node;
    Node* parent = nullptr;

    while (current) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            return node; 
        }
    }

    if (key < parent->key) {
        parent->left = new Node(key);
    } else {
        parent->right = new Node(key);
    }

    return node;
}

Tree::Node* Tree::remove(Node* node, int key) {
    if (!node) return nullptr;

    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        } else {
            // Находим минимальный узел в правом поддереве
            Node* minRight = node->right;
            while (minRight->left) {
                minRight = minRight->left;
            }

            node->key = minRight->key;
            node->right = remove(node->right, minRight->key);
        }
    }
    return node;
}

Tree::Node* Tree::search(Node* node, int key) const {
    while (node && node->key != key) {
        node = (key < node->key) ? node->left : node->right;
    }
    return node;
}

void Tree::clear() {
    std::stack<Node*> nodes;
    nodes.push(root);
    root = nullptr;

    while (!nodes.empty()) {
        Node* current = nodes.top();
        nodes.pop();

        if (current) {
            if (current->left) nodes.push(current->left);
            if (current->right) nodes.push(current->right);
            delete current;
        }
    }
}


int Tree::count() const {
    if (!root) return 0;

    std::stack<Node*> nodes;
    nodes.push(root);
    int count = 0;

    while (!nodes.empty()) {
        Node* current = nodes.top();
        nodes.pop();
        count++;

        if (current->left) nodes.push(current->left);
        if (current->right) nodes.push(current->right);
    }

    return count;
}


void Tree::balance() {
    int n = count();
    if (n == 0) return;

    std::vector<Node*> nodes;
    nodes.reserve(n);
    store(root, nodes);

    root = build(nodes, 0, n - 1);
}

void Tree::store(Node* node, std::vector<Node*>& nodes) {
    if (!node) return;

    store(node->left, nodes);
    nodes.push_back(node);
    store(node->right, nodes);
}

Tree::Node* Tree::build(const std::vector<Node*>& nodes, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    Node* node = nodes[mid];

    node->left = build(nodes, start, mid - 1);
    node->right = build(nodes, mid + 1, end);

    return node;
}


void Tree::calculate(int width) {
    if (!root) return;

    int depth = 0;
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        depth++;

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    calculate(root, width / 2, 50, width / 4, depth);
}

void Tree::calculate(Node* node, int x, int y, int offset, int depth) {
    if (!node) return;
    node->x = x;
    node->y = y;
    int newOffset = offset * std::max(1, depth / 2);
    calculate(node->left, x - newOffset, y + 60, offset / 2, depth - 1);
    calculate(node->right, x + newOffset, y + 60, offset / 2, depth - 1);
}
