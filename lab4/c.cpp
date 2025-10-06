#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
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

Node* find(Node* root, int k) {
    if (!root) { // Если не найдено
        return nullptr;
    }
    if (root->data == k) { // Если найдено возвращаем дерево
        return root; 
    }
    if (k < root->data) { // Если кей меньше чем нынешнее значние то идем влево рекурсией
        return find(root->left, k);
    }
    else { // Если кей меньше чем нынешнее значние то идем вправо рекурсией
        return find(root->right, k);
    }
}

void subtree_output(Node* root) { // Вывод поддерева сначала левых потом правых
    if (!root) return;
    cout << root->data << " ";
    subtree_output(root->left);
    subtree_output(root->right);
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

    subtree_output(subtree);
    return 0;
}