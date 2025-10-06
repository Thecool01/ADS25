#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) { // Структура БИНАРНОГО ДЕРЕВА
        data = value;
        left = nullptr;
        right = nullptr;
    }   
};

Node* insert(Node* root, int value) {
    if (!root) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* find(Node* root, int key) {
    if (!root) {
        return nullptr;
    }

    if (root->data == key) {
        return root;
    }
    if (root->data > key) {
        return find(root->left, key);
    }
    else {
        return find(root->right, key);
    }

}

// функция возвращает количество узлов в поддереве
int counting_subtree(Node* root) {
    if (!root) return 0; // пустое поддерево — 0 узлов
    return 1 + counting_subtree(root->left) + counting_subtree(root->right);
}

int main() {
    int n;
    cin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int key;
    cin >> key;

    Node* subtree = find(root, key);

    cout << counting_subtree(subtree);
    return 0;
}